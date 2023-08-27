/*Add your custom functions to process meter readings here*/

void onTelegram(){
  /*This function is executed whenever a meter telegram containing a meterID and meterTimestamp is received.
   * Use this function if you want the most recent meter updates
   */
  printTelegramValues();
  mqttPushTelegramValues();
}

void onTelegramCrc(){
  /*This function is executed whenever a meter telegram containing a meterID, a meterTimestamp and a valid CRC is received.
   * Sometimes a meter telegram containing valid measurements can be reveived, but the CRC can be off.
   * Use this function if you want absolute assurance about the telegram contents.
   */
}

void printTelegramValues(){
  /*Example function which loops over both the configured DSMR keys and the detected Mbus keys and, if found, prints their value.
   * This function shows you how you can access these keys and their values.
   */
  Serial.print("Meter ID: ");
  Serial.println(meterId);
  Serial.print("Meter time: ");
  Serial.print(meterTimestamp);
  Serial.print(" ");
  struct tm meterTime;
  localtime_r(&meterTimestamp , &meterTime);
  char timeStringBuff[30];
  strftime(timeStringBuff,sizeof(timeStringBuff),"%A, %B %d %Y %H:%M:%S", &meterTime);
  Serial.println(timeStringBuff);
  /*Loop over the configured DSMR keys and, if present in the received meter telegram, print them*/ 
  for(int i = 0; i < sizeof(dsmrKeys)/sizeof(dsmrKeys[0]); i++){
    if(*dsmrKeys[i].keyFound == true){
      Serial.print(dsmrKeys[i].keyName);
      Serial.print(": ");
      if(dsmrKeys[i].keyType > 0 && dsmrKeys[i].keyType < 4){
        if(fmodf(*dsmrKeys[i].keyValueFloat, 1.0) == 0) Serial.print(int(*dsmrKeys[i].keyValueFloat));
        else Serial.print(round2(*dsmrKeys[i].keyValueFloat));
        Serial.print(" ");
      }
      if(dsmrKeys[i].keyType == 2 || dsmrKeys[i].keyType == 3){
        if(dsmrKeys[i].deviceType == "energy") Serial.print("kWh ");
        else if(dsmrKeys[i].deviceType == "power") Serial.print("kW ");
        else if(dsmrKeys[i].deviceType == "power") Serial.print("kW ");
        else if(dsmrKeys[i].deviceType == "voltage") Serial.print("V ");
        else if(dsmrKeys[i].deviceType == "current") Serial.print("A ");
        else Serial.print(" ");
      }
      if(dsmrKeys[i].keyType == 3){
        Serial.print("(");
        Serial.print(*dsmrKeys[i].keyValueLong);
        Serial.print(")");
      }
      if(dsmrKeys[i].keyType == 4){
        Serial.print(*dsmrKeys[i].keyValueString);
      }
      if(dsmrKeys[i].keyType == 5){
        Serial.print(*dsmrKeys[i].keyValueLong);
      }
      Serial.println("");
    }
  }
  /*Loop over the Mbus keys found in the meter telegram and print their value*/
  for(int i = 0; i < sizeof(mbusMeter)/sizeof(mbusMeter[0]); i++){
    if(mbusMeter[i].keyFound == true){
      if(mbusMeter[i].type == 3) Serial.print("Natural gas consumption: ");
      else if (mbusMeter[i].type == 4) Serial.print("Heat consumption: ");
      else if (mbusMeter[i].type == 7) Serial.print("Water consumption: ");
      if(fmodf(mbusMeter[i].keyValueFloat, 1.0) == 0) Serial.print(int(mbusMeter[i].keyValueFloat));
      else Serial.print(round2(mbusMeter[i].keyValueFloat));
      if(mbusMeter[i].type == 3 || mbusMeter[i].type == 7) Serial.print(" m³ (");
      else if (mbusMeter[i].type == 7) Serial.print(" kWh (");
      Serial.print(mbusMeter[i].keyTimeStamp);
      Serial.println(")");
    }
    
  }
}

void mqttPushTelegramValues(){
  if(sinceLastUpload > _upload_throttle*1000){
    String availabilityTopic = _mqtt_prefix.substring(0, _mqtt_prefix.length()-1);
    pubMqtt(availabilityTopic, "online", false);
    for(int i = 0; i < sizeof(dsmrKeys)/sizeof(dsmrKeys[0]); i++){
      if(*dsmrKeys[i].keyFound == true){
        /*Check if the key,value pair needs to be pushed
         * The unsigned long _key_pushlist contains 32 bits indicating if the value needs to be pushed (1) or not (0)
         * E.g. if _key_pushlist is 329, its binary representation is 00000000000000000000000101001001
         * The LSB (at the rightmost side) represents dsmrKeys[0], the bit to the left of it dsmrKeys[1] etc.
         * We boolean AND the _key_pushlist with a binary mask 1, which is shifted to the left according to which key in dsmrKeys[] we are comparing
         * If the result is 1, this means the key,value pair must be pushed
         * E.g. if _key_pushlist is 329, dsmrKeys[0] must be pushed, dsmrKeys[1] not, dsmrKeys[2] not, dsmrKeys[3] must, etc.
         * Sounds complicated, but this way we only need one variable in NVS to store up to 32 options.
         */
        unsigned long mask = 1;
        mask <<= i;
        unsigned long test = _key_pushlist & mask;
        if(test > 0){
          if(telegramDebug){
            Serial.print(" - ");
            Serial.print(dsmrKeys[i].keyName);
            Serial.print(": ");
          }
          if(dsmrKeys[i].keyType == 0 || dsmrKeys[i].keyType == 4){
            /*Other or string value (currently handled the same)*/
            pushDSMRValue(dsmrKeys[i].dsmrKey, 0, "", meterTimestamp, dsmrKeys[i].deviceType, dsmrKeys[i].keyName, dsmrKeys[i].keyTopic, *dsmrKeys[i].keyValueString);
          }
          else if(dsmrKeys[i].keyType == 1){
            /*Numeric value with no unit*/
            pushDSMRValue(dsmrKeys[i].dsmrKey, *dsmrKeys[i].keyValueFloat, "", meterTimestamp, dsmrKeys[i].deviceType, dsmrKeys[i].keyName, dsmrKeys[i].keyTopic, "");
          }
          else if(dsmrKeys[i].keyType == 2){
            /*Numeric value with unit*/
            String unit;
            if(dsmrKeys[i].deviceType == "energy") unit = "kWh";
            else if(dsmrKeys[i].deviceType == "power") unit = "kW";
            else if(dsmrKeys[i].deviceType == "voltage") unit = "V";
            else if(dsmrKeys[i].deviceType == "current") unit = "A";
            pushDSMRValue(dsmrKeys[i].dsmrKey, *dsmrKeys[i].keyValueFloat, unit, meterTimestamp, dsmrKeys[i].deviceType, dsmrKeys[i].keyName, dsmrKeys[i].keyTopic, "");
          }
          else if(dsmrKeys[i].keyType == 3){
            /*timestamped (Mbus) message*/
            String unit;
            if(dsmrKeys[i].deviceType == "energy") unit = "kWh";
            else if(dsmrKeys[i].deviceType == "power") unit = "kW";
            else if(dsmrKeys[i].deviceType == "voltage") unit = "V";
            else if(dsmrKeys[i].deviceType == "current") unit = "A";
            pushDSMRValue(dsmrKeys[i].dsmrKey, *dsmrKeys[i].keyValueFloat, unit, *dsmrKeys[i].keyValueLong, dsmrKeys[i].deviceType, dsmrKeys[i].keyName, dsmrKeys[i].keyTopic, "");
          }
          else{
            if(telegramDebug) Serial.print("undef");
          }
        }
      }
    }
  }
}
