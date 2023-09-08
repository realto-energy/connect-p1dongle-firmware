void syslog(String msg, int level){
  String logmsg;
  unsigned long dtimestamp; 
  if(timeSet){
    dtimestamp = printUnixTime();
    logmsg = printLocalTime(false) + " ";
  }
  if(level == 0 || level == 1) logmsg = logmsg + "INFO: "; //level 0 is used for INFO messages when MQTT is down
  else if(level == 2) logmsg = logmsg + "WARNING: ";
  else if(level == 3 || level == 4) logmsg = logmsg + "ERROR: "; //level 4 is used for ERROR messages when MQTT is down
  else logmsg = logmsg + "MISC: ";
  logmsg = logmsg + msg;
  Serial.println(logmsg);
  bufferSyslog( { logmsg.c_str(), dtimestamp });

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

bool publishSyslog(SyslogEntry entry) {
  DynamicJsonDocument doc(1024);
  doc["friendly_name"] = "System log";
  doc["value"] = entry.msg;
  doc["entity"] = apSSID;
  doc["sensorId"] = "syslog";
  doc["timestamp"] = entry.timestamp;
  String dtopic = "plan-d/" + String(apSSID) + "/sys/syslog"; //JSI: Changed to plan-d/P1XXXXXX/sys/syslog
  String jsonOutput;
  serializeJson(doc, jsonOutput);
  return pubMqtt(dtopic, jsonOutput, true);
}

void bufferSyslog(SyslogEntry entry) {
  // buffer syslog messages in case mqtt is not enabled
  log_v("Buffering syslog message: %s", entry.msg.c_str());
  syslogBuffer.push(entry);
  while(syslogBuffer.size() > syslogBufferSize) syslogBuffer.pop();
}

elapsedMillis sinceLastSyslogPublishFail;

void proccessSyslogBuffer() {
  if(sinceLastSyslogPublishFail < 10000) return; // don't try to publish imidiatly after a fail (to avoid flooding mqtt)
  // empty syslog buffer
  while(!syslogBuffer.empty()){
    SyslogEntry entry = syslogBuffer.front();
    if(!publishSyslog(entry)) { 
      log_e("Failed to publish syslog message: %s", entry.msg.c_str());
      sinceLastSyslogPublishFail = 0;
      break; 
    };
    log_d("Published syslog message from buffer: %s", entry.msg.c_str());
    syslogBuffer.pop();
  }
}