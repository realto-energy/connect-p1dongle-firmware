
bool realtoUpload(){
  if(lastRealtoUpload > _realtoThrottle){
    String availabilityTopic = _mqtt_prefix.substring(0, _mqtt_prefix.length()-1);
    pubMqtt(availabilityTopic, "online", false);
    DynamicJsonDocument realtoData(1024);
    realtoData["timestamp"] = meterTimestamp;
    for(int i = 0; i < sizeof(dsmrKeys)/sizeof(dsmrKeys[0]); i++){
      for(int j = 0; j < sizeof(realtoKeys)/sizeof(realtoKeys[0]); j++){
        if(dsmrKeys[i].dsmrKey == realtoKeys[j]){
          if(*dsmrKeys[i].keyFound == true){
            realtoData[realtoKeys[j]]["value"] = *dsmrKeys[i].keyValueFloat;
            realtoData[realtoKeys[j]]["unit"] = getUnit(dsmrKeys[i].deviceType);
          }
        }
      }
    }
    String realtoOutput;
    serializeJson(realtoData, realtoOutput);
    /*Push the JSON string over MQTT*/
    if(pubMqtt(_mqtt_prefix.substring(0, _mqtt_prefix.length()-1), realtoOutput, "false")){
      lastRealtoUpload = 0;
      realtoUploadTries = 0;
    }
    else{
      /*If MQTT push failed, try again in 5 sec*/
      lastRealtoUpload = _realtoThrottle - 5000;
      realtoUploadTries++;
    }
    /*Give up after five tries, trying again in five minutes*/
    if(realtoUploadTries > 5){
      lastRealtoUpload = 5*5000; //to compensate for the five retry delays
      realtoUploadTries = 0;
    }
  }
  return true;
}
