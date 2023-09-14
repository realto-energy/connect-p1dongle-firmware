#include <deque>

static const char preRebootLogFileName[] = "preRebootLog.txt";

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
  //bufferSyslog( { std::string(logmsg.c_str()), dtimestamp });

  if(_mqtt_en && !mqttClientError && !mqttHostError && level > 0 && level < 4){
    DynamicJsonDocument doc(1024);
    doc["friendly_name"] = "System log";
    doc["value"] = logmsg;
    doc["entity"] = apSSID;
    doc["sensorId"] = "syslog";
    doc["timestamp"] = dtimestamp;
    String dtopic = "plan-d/" + String(apSSID) + "/sys/syslog"; //JSI: Changed to plan-d/P1XXXXXX/sys/syslog
    String jsonOutput;
    serializeJson(doc, jsonOutput);
    pubMqtt(dtopic, jsonOutput, true);
  }
  if(level > 0 && spiffsMounted){
    if(sizeFile(SPIFFS, "/syslog.txt") > 5120){
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
/*
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

std::deque<std::string> getLastLogLines(File file, size_t lineLimit = 10) {
  std::deque<std::string> last_lines;

  char buffer[512];
  while (file.available()) {
    int l = file.readBytesUntil('\n', buffer, sizeof(buffer));
    buffer[l] = 0;
    last_lines.push_back(std::string(buffer));

    if (last_lines.size() > lineLimit) {
      last_lines.pop_front();
    }
  }

  log_v("fetched %d last lines ", last_lines.size());

  return last_lines;
}

void dumpSysLogFile(const char* logFileName, size_t lineLimit = 10) {
  File file = SPIFFS.open(logFileName);
  log_d("Opening %s", logFileName);
  if(!file || file.isDirectory()){
      Serial.println("- failed to open file for reading");
      file.close();
      return;
  }

  auto lastLines = getLastLogLines(file, lineLimit);
  publishLogLines(lastLines);

  file.close();
}

void publishLogLines(std::deque<std::string> lines) {
  int lineNumber = 0;
  for (auto& line : lines) {
    log_v("Publishing log line: %s", line.c_str());
    DynamicJsonDocument doc(1024);
    doc["friendly_name"] = "Previous runtime log tail";
    doc["value"] = line.c_str();
    doc["entity"] = apSSID;
    doc["sensorId"] = "previous_syslog";
    doc["line"] = lineNumber++;
    String dtopic = "plan-d/" + String(apSSID) + "/sys/previous_syslog"; //JSI: Changed to plan-d/P1XXXXXX/sys/syslog
    String jsonOutput;
    serializeJson(doc, jsonOutput);
    pubMqtt(dtopic, jsonOutput, true);
  }
}


void dumpSysLog(size_t lineLimit) {
  log_i("Dumping syslog");
  static const char* logFileName  = "/syslog.txt";
  // static const char* logFileName0 = "/syslog0.txt";
  dumpSysLogFile(logFileName, lineLimit);
  // dumpSysLogFile(logFileName0);
}*/
