void syslog(String msg, int level){
  String logmsg;
  unsigned long dtimestamp; 
  if(timeSet){
    dtimestamp = printUnixTime();
    logmsg = printLocalTime(false) + " ";
  }
  if(level == 0 || level == 1) logmsg = logmsg + "INFO: ";
  else if(level == 2) logmsg = logmsg + "WARNING: ";
  else if(level == 3 || level == 4) logmsg = logmsg + "ERROR: "; //level 4 is used for ERROR messages when MQTT is down
  else logmsg = logmsg + "MISC: ";
  logmsg = logmsg + msg;
  Serial.println(logmsg);
  if(_mqtt_en && !mqttClientError && !mqttHostError && level < 4){
    DynamicJsonDocument doc(1024);
    doc["friendly_name"] = "System log";
    doc["value"] = logmsg;
    doc["entity"] = apSSID;
    doc["sensorId"] = "syslog";
    doc["timestamp"] = dtimestamp;
    String dtopic = "sys/devices/" + String(apSSID) + "/syslog";
    String jsonOutput;
    serializeJson(doc, jsonOutput);
    pubMqtt(dtopic, jsonOutput, true);
  }
  if(level > 0 && spiffsMounted){
    if(sizeFile(SPIFFS, "/syslog.txt") > 8000){
      Serial.println("Swapping logfiles");
      deleteFile(SPIFFS, "/syslog0.txt");
      renameFile(SPIFFS, "/syslog.txt", "/syslog0.txt");
    }
    logmsg = logmsg + "\r\n";
    appendFile(SPIFFS, "/syslog.txt", logmsg.c_str());
  }
}

void saveResetReason(String rReason){
  if(timeSet){
    _last_reset = printLocalTime(false) + " ";
  }
  else{
    _last_reset = "";
  }
  _last_reset = _last_reset + rReason;
}
