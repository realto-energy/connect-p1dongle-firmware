static const String addJson[][2] PROGMEM = {
  /*You can add custom JSON fields to individual NVS keys here, which will be added to the JSON response when querying/updating the variables through the HTTP API or MQTT.
   * Format: { "NVS key name", "JSON string" }
   * Make sure the JSON string is valid and properly escaped!
   */
  {"WIFI_STA", "{ \"array\": [ 1, 2, 3 ], \"boolean\": true, \"color\": \"gold\", \"null\": null, \"number\": 123, \"object\": { \"a\": \"b\", \"c\": \"d\" }, \"string\": \"Hello World\" }"}, 
  {"MQTT_EN", "test"}
};

static const String svgIcons[][2] PROGMEM = {
  {"wifi-strength-4",  "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3Z\" /></svg>"},
  {"wifi-strength-3", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-3</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L18.77,9.88C17.26,9 14.88,8 12,8C9,8 6.68,9 5.21,9.84L3.27,7.44C5.91,5.85 8.93,5 12,5Z\" /></svg>"},
  {"wifi-strength-2", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-2</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L17.5,11.43C16.26,10.74 14.37,10 12,10C9.62,10 7.74,10.75 6.5,11.43L3.27,7.44C5.91,5.85 8.93,5 12,5Z\" /></svg>"},
  {"wifi-strength-1", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-1</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L15.61,13.81C14.5,13.28 13.25,13 12,13C10.75,13 9.5,13.28 8.39,13.8L3.27,7.44C5.91,5.85 8.93,5 12,5Z\" /></svg>"},
  {"wifi-strength-outline", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-outline</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7H0.36C4.24,11.83 8.13,16.66 12,21.5C15.89,16.66 19.77,11.83 23.64,7H23.65C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L12,18.3L3.27,7.44C5.9,5.85 8.92,5 12,5Z\" /></svg>"},
  {"wifi-cog", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-cog</title><path d=\"M12 12C9.97 12 8.1 12.67 6.6 13.8L4.8 11.4C6.81 9.89 9.3 9 12 9S17.19 9.89 19.2 11.4L18.74 12C17.66 12.05 16.63 12.33 15.73 12.81C14.6 12.29 13.33 12 12 12M21 9L22.8 6.6C19.79 4.34 16.05 3 12 3S4.21 4.34 1.2 6.6L3 9C5.5 7.12 8.62 6 12 6S18.5 7.12 21 9M12 15C10.65 15 9.4 15.45 8.4 16.2L12 21L12.22 20.71C12.08 20.16 12 19.59 12 19C12 17.57 12.43 16.24 13.17 15.13C12.79 15.05 12.4 15 12 15M23.8 20.4C23.9 20.4 23.9 20.5 23.8 20.6L22.8 22.3C22.7 22.4 22.6 22.4 22.5 22.4L21.3 22C21 22.2 20.8 22.3 20.5 22.5L20.3 23.8C20.3 23.9 20.2 24 20.1 24H18.1C18 24 17.9 23.9 17.8 23.8L17.6 22.5C17.3 22.4 17 22.2 16.8 22L15.6 22.5C15.5 22.5 15.4 22.5 15.3 22.4L14.3 20.7C14.2 20.6 14.3 20.5 14.4 20.4L15.5 19.6V18.6L14.4 17.8C14.3 17.7 14.3 17.6 14.3 17.5L15.3 15.8C15.4 15.7 15.5 15.7 15.6 15.7L16.8 16.2C17.1 16 17.3 15.9 17.6 15.7L17.8 14.4C17.8 14.3 17.9 14.2 18.1 14.2H20.1C20.2 14.2 20.3 14.3 20.3 14.4L20.5 15.7C20.8 15.8 21.1 16 21.4 16.2L22.6 15.7C22.7 15.7 22.9 15.7 22.9 15.8L23.9 17.5C24 17.6 23.9 17.7 23.8 17.8L22.7 18.6V19.6L23.8 20.4M20.5 19C20.5 18.2 19.8 17.5 19 17.5S17.5 18.2 17.5 19 18.2 20.5 19 20.5 20.5 19.8 20.5 19Z\" /></svg>"}
  };

String returnSvg(){
  String svg = svgIcons[5][1];
  return svg;
}

const char test_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}
  </style>
<script>
  function getJsonData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onload = function() {
    if (this.status == 200) {
      var jsonResponse = JSON.parse(this.responseText);
      console.log(jsonResponse);
      console.log(jsonResponse.SSIDlist);
      console.log(jsonResponse[0]);
      console.log(jsonResponse.SSIDlist[0]);
      console.log(jsonResponse.SSIDlist.length);    
      for (var i = 0; i < jsonResponse.SSIDlist.length; i++) {
          var select = document.getElementById("WIFI_SSID");
          var option = document.createElement("option");
          option.text = jsonResponse.SSIDlist[i].SSID;
          option.value = jsonResponse.SSIDlist[i].SSID;
          select.add(option);
      }
    }
  };
  xhttp.open("GET", "wifi", true);
  xhttp.send();
}
</script>
</head>
<body onload="getJsonData()">
  <h2>ESP Web Server</h2>
  <p><form method="post" action="config" enctype="text/plain" accept-charset="utf-8"></p>
    <p><label for="cars">Choose a car:</label>
    <select id="WIFI_SSID" name="_wifi_ssid">
    </select></p>
    <p><input name="_tempString" length=64 type="password" id="myPassword"></p>
    <p><input type="submit" value="Submit"></p>
  </form>
</body>
</html>
)rawliteral";
