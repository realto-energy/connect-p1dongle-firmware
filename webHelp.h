static const String addJson[][2] PROGMEM = {
  /*You can add custom JSON fields to individual NVS config keys here, which will be added to the JSON response when querying/updating the variables through the HTTP API or MQTT.
   * Format: { "NVS key name", "JSON string" }
   * Make sure the JSON string is valid and properly escaped!
   */
  {"WIFI_STA", "{ \"array\": [ 1, 2, 3 ], \"boolean\": true, \"color\": \"gold\", \"null\": null, \"number\": 123, \"object\": { \"a\": \"b\", \"c\": \"d\" }, \"string\": \"Hello World\" }"}, 
  {"MQTT_EN", "test"}
};

static const String svgIcons[][3] PROGMEM = {
  {"wifi-strength-4", "Meter configured", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3Z\" /></svg>"},
  {"wifi-strength-3", "WiFi configured", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-3</title><path class=\"icons\" d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L18.77,9.88C17.26,9 14.88,8 12,8C9,8 6.68,9 5.21,9.84L3.27,7.44C5.91,5.85 8.93,5 12,5Z\" /></svg>"},
  {"wifi-strength-2", "WiFi configured", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-2</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L17.5,11.43C16.26,10.74 14.37,10 12,10C9.62,10 7.74,10.75 6.5,11.43L3.27,7.44C5.91,5.85 8.93,5 12,5Z\" /></svg>"},
  {"wifi-strength-1", "WiFi configured", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-1</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7C4.41,12.06 7.89,16.37 12,21.5C16.08,16.42 20.24,11.24 23.65,7C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L15.61,13.81C14.5,13.28 13.25,13 12,13C10.75,13 9.5,13.28 8.39,13.8L3.27,7.44C5.91,5.85 8.93,5 12,5Z\" /></svg>"},
  {"wifi-strength-outline", "WiFi configured", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-strength-outline</title><path d=\"M12,3C7.79,3 3.7,4.41 0.38,7H0.36C4.24,11.83 8.13,16.66 12,21.5C15.89,16.66 19.77,11.83 23.64,7H23.65C20.32,4.41 16.22,3 12,3M12,5C15.07,5 18.09,5.86 20.71,7.45L12,18.3L3.27,7.44C5.9,5.85 8.92,5 12,5Z\" /></svg>"},
  {"wifi-cog", "WiFi not configured", "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><title>wifi-cog</title><path class=\"icons\" d=\"M12 12C9.97 12 8.1 12.67 6.6 13.8L4.8 11.4C6.81 9.89 9.3 9 12 9S17.19 9.89 19.2 11.4L18.74 12C17.66 12.05 16.63 12.33 15.73 12.81C14.6 12.29 13.33 12 12 12M21 9L22.8 6.6C19.79 4.34 16.05 3 12 3S4.21 4.34 1.2 6.6L3 9C5.5 7.12 8.62 6 12 6S18.5 7.12 21 9M12 15C10.65 15 9.4 15.45 8.4 16.2L12 21L12.22 20.71C12.08 20.16 12 19.59 12 19C12 17.57 12.43 16.24 13.17 15.13C12.79 15.05 12.4 15 12 15M23.8 20.4C23.9 20.4 23.9 20.5 23.8 20.6L22.8 22.3C22.7 22.4 22.6 22.4 22.5 22.4L21.3 22C21 22.2 20.8 22.3 20.5 22.5L20.3 23.8C20.3 23.9 20.2 24 20.1 24H18.1C18 24 17.9 23.9 17.8 23.8L17.6 22.5C17.3 22.4 17 22.2 16.8 22L15.6 22.5C15.5 22.5 15.4 22.5 15.3 22.4L14.3 20.7C14.2 20.6 14.3 20.5 14.4 20.4L15.5 19.6V18.6L14.4 17.8C14.3 17.7 14.3 17.6 14.3 17.5L15.3 15.8C15.4 15.7 15.5 15.7 15.6 15.7L16.8 16.2C17.1 16 17.3 15.9 17.6 15.7L17.8 14.4C17.8 14.3 17.9 14.2 18.1 14.2H20.1C20.2 14.2 20.3 14.3 20.3 14.4L20.5 15.7C20.8 15.8 21.1 16 21.4 16.2L22.6 15.7C22.7 15.7 22.9 15.7 22.9 15.8L23.9 17.5C24 17.6 23.9 17.7 23.8 17.8L22.7 18.6V19.6L23.8 20.4M20.5 19C20.5 18.2 19.8 17.5 19 17.5S17.5 18.2 17.5 19 18.2 20.5 19 20.5 20.5 19.8 20.5 19Z\" /></svg>"}
  };

String returnSvg(){
  String jsonOutput;
  DynamicJsonDocument doc(5120);
  JsonObject wifiVar  = doc.createNestedObject("wifi");
  wifiVar["img"] = svgIcons[5][2];
  wifiVar["alt"] = svgIcons[5][1];
  JsonObject meterVar  = doc.createNestedObject("meter");
  meterVar["img"] = svgIcons[4][2];
  meterVar["alt"] = svgIcons[4][1];
  JsonObject cloudVar  = doc.createNestedObject("cloud");
  cloudVar["img"] = svgIcons[3][2];
  cloudVar["alt"] = svgIcons[3][1];
  JsonObject extVar  = doc.createNestedObject("externalio");
  extVar["img"] = svgIcons[0][2];
  extVar["alt"] = svgIcons[0][1];
  serializeJson(doc, jsonOutput);
  return jsonOutput;
}

String releaseChannels(){
  /*Replace with a dynamic Jsondoc*/
  String channels;
  if(_alpha_fleet) channels = "{\"Releasechannels\":[{\"channel\":\"alpha\"},{\"channel\":\"develop\"},{\"channel\":\"main\"},{\"channel\":\"V2\"}]}"; 
  else if(_dev_fleet) channels = "{\"Releasechannels\":[{\"channel\":\"develop\"},{\"channel\":\"alpha\"},{\"channel\":\"main\"},{\"channel\":\"V2\"}]}";
  else if(_v2_fleet) channels = "{\"Releasechannels\":[{\"channel\":\"V2\"},{\"channel\":\"develop\"},{\"channel\":\"alpha\"},{\"channel\":\"main\"}]}";
  else channels = "{\"Releasechannels\":[{\"channel\":\"main\"},{\"channel\":\"develop\"},{\"channel\":\"alpha\"},{\"channel\":\"V2\"}]}";
  return channels;
}

/*Everything between rawliteral( ) is treated as one big string*/
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
    <link rel="stylesheet" href="style.css">
    <title>Digital meter - Main Menu</title>
</head>

<body>

    <div class="container">
        <noscript>To use the digital meter dongle, please enable JavaScript<br></noscript>
        <h2>Digital meter dongle</h2>
        <h2 id="hostnameHeader"></h2>
        <h3><span id="infoMessage" style='text-align:center;color:red;'></span></h3>
    <div class="svg-container">
        <img id="wifi" alt="" src="" />
        <img id="meter" alt="" src="" />
        <img id="cloud" alt="" src="" />
        <img id="externalio" alt="" src="" />
    </div>
    
        <form id="configForm">
            <button type="button" class="collapsible active">Basic settings</button>
            <div class="content" style="display: block;">
            <!-- Dropdown for WiFi Network -->
            <label for="WIFI_SSID">WiFi Network:</label>
            <select id="WIFI_SSID" name="WIFI_SSID"></select><br><br>
    
            <!-- Password Input -->
            <label for="WIFI_PASSWD">WiFi Password:</label>
            <input type="password" id="WIFI_PASSWD" name="WIFI_PASSWD"><br>
            <span class="show-password">Show password</span>
    
            <!-- Email Input -->
            <label for="EMAIL">User Email:</label>
            <input type="email" id="EMAIL" name="EMAIL"><br><br>
            
            </div>
            <button type="button" class="collapsible">Advanced settings</button>
            <div class="content">
            <!-- Dropdown for Release Channel -->
            <label for="REL_CHAN">Release Channel:</label>
            <select id="REL_CHAN" name="REL_CHAN"></select><br><br>
            
            </div>
            <input type="submit" class="submit" value="Submit">
        </form>
        <footer>
            <a href='https://realto.io' target='_blank' id="footerLink">Digital meter dongle by re.alto & plan-d.io</a>
        </footer>
    </div>

    <script>
        var coll = document.getElementsByClassName("collapsible"); //animate the collapsibles
        for (var i = 0; i < coll.length; i++) {
            coll[i].addEventListener("click", function() {
                this.classList.toggle("active");
                var content = this.nextElementSibling;
                if (content.style.display === "block") {
                    content.style.display = "none";
                } else {
                    content.style.display = "block";
                }
            });
        }
        document.addEventListener("DOMContentLoaded", function() {
              // Fetch SVG images
              fetch('/svg')
                .then(response => response.json())
                .then(data => {
                    const wifiImg = document.getElementById('wifi');
                    const meterImg = document.getElementById('meter');
                    const cloudImg = document.getElementById('cloud'); // New
                    const externalioImg = document.getElementById('externalio'); // New
            
                    // Modify the SVG fill color to white
                    let wifiSvg = data.wifi.img.replace('<path', '<path fill="white"');
                    let meterSvg = data.meter.img.replace('<path', '<path fill="white"');
                    let cloudSvg = data.cloud.img.replace('<path', '<path fill="white"'); // New
                    let externalioSvg = data.externalio.img.replace('<path', '<path fill="white"'); // New
            
                    wifiImg.src = 'data:image/svg+xml,' + encodeURIComponent(wifiSvg);
                    wifiImg.alt = data.wifi.alt;
                    wifiImg.title = data.wifi.alt;
            
                    meterImg.src = 'data:image/svg+xml,' + encodeURIComponent(meterSvg);
                    meterImg.alt = data.meter.alt;
                    meterImg.title = data.meter.alt;
            
                    cloudImg.src = 'data:image/svg+xml,' + encodeURIComponent(cloudSvg); // New
                    cloudImg.alt = data.cloud.alt; // New
                    cloudImg.title = data.cloud.alt; // New
            
                    externalioImg.src = 'data:image/svg+xml,' + encodeURIComponent(externalioSvg); // New
                    externalioImg.alt = data.externalio.alt; // New
                    externalioImg.title = data.externalio.alt; // New
            
                    return fetch('/wifi');
                })
                // Fetch the SSID list and populate the dropdown
                .then(response => response.json())
                .then(data => {
                    const ssidSelect = document.getElementById('WIFI_SSID');
                    data.SSIDlist.forEach(item => {
                        const option = document.createElement('option');
                        option.value = item.SSID;
                        option.textContent = item.SSID;
                        ssidSelect.appendChild(option);
                    });

                    // Fetch the release channels and populate the dropdown
                    return fetch('/releasechan');
                })
                .then(response => response.json())
                .then(data => {
                    const releaseChannelSelect = document.getElementById('REL_CHAN');
                    data.Releasechannels.forEach(item => {
                        const option = document.createElement('option');
                        option.value = item.channel;
                        option.textContent = item.channel;
                        releaseChannelSelect.appendChild(option);
                    });

                    // After populating the dropdowns, fetch the configuration data
                    return fetch('/config');
                })
                .then(response => response.json())
                .then(data => {
                    // Set the hostname header
                    const hostname = data.HOSTNAME.value;
                    document.getElementById('hostnameHeader').textContent = hostname;
                    // Set the footer version
                    const version = data.FW_VER.value;
                    const footerLink = document.getElementById('footerLink');
                    footerLink.textContent = `Digital meter dongle V${version} by re.alto & plan-d.io`;
                    //Populate all the form fields
                    const inputs = document.querySelectorAll('input, select, textarea');
                    inputs.forEach(input => {
                        const name = input.name;
                        if (data[name]) {
                            const type = data[name].type;
                            const value = data[name].value;
                            switch (type) {
                                case 'bool':
                                    if (input.type === 'checkbox') {
                                        input.checked = value;
                                    } else {
                                        input.value = value ? 'true' : 'false';
                                    }
                                    break;
                                case 'int32':
                                case 'uint32':
                                case 'uint64':
                                case 'string':
                                    input.value = value;
                                    break;
                                case 'password':
                                    if (data[name].filled) {
                                        input.placeholder = 'Password is set';
                                    }
                                    break;
                                case 'email':
                                    if (data[name].filled) {
                                        input.placeholder = 'Email is set';
                                    }
                                    break;
                                default:
                                    console.warn(`Unhandled type: ${type} for input: ${name}`);
                            }
                        }
                    });
                })
                .catch(error => {
                    console.error('Error fetching or processing data:', error);
                });
            // Mark password fields as changed when their value is modified
            const passwordFields = document.querySelectorAll('input[type="password"]');
            passwordFields.forEach(field => {
                field.addEventListener('input', function() {
                    this.setAttribute('data-changed', 'true');
                });
            });

            // Handle form submission
            const form = document.getElementById('configForm');
            form.addEventListener('submit', function(event) {
                event.preventDefault();

                const formData = new FormData(form);
                const jsonData = {};

                // Handle unchecked checkboxes
                const checkboxes = document.querySelectorAll('input[type="checkbox"]');
                checkboxes.forEach(checkbox => {
                    jsonData[checkbox.name] = checkbox.checked;
                });

                formData.forEach((value, key) => {
                    const inputElement = document.querySelector(`[name="${key}"]`);
                    if (inputElement.type !== 'checkbox') {
                        if (inputElement.type === 'password' || inputElement.type === 'email') {
                            if (value && (inputElement.getAttribute('data-changed') === 'true' || !inputElement.placeholder.includes('set'))) {
                                jsonData[key] = value;
                            }
                        } else {
                            jsonData[key] = value;
                        }
                    }
                });

                console.log('Submitting JSON:', JSON.stringify(jsonData));

                fetch('/config', {
                    method: 'PUT',
                    headers: {
                        'Content-Type': 'application/json'
                    },
                    body: JSON.stringify(jsonData)
                })
                .then(response => response.json())
                .then(data => {
                    console.log('Server response:', data);
                    // Fetch the info message after form submission
                    return fetch('/info');
                })
                .then(response => response.text())
                .then(message => {
                    document.getElementById('infoMessage').textContent = message;
                })
                .catch(error => {
                    console.error('Error submitting data:', error);
                });
            });
            // Show password functionality
            const passwordInput = document.getElementById('WIFI_PASSWD');
            const showPasswordText = document.querySelector('.show-password');

            showPasswordText.addEventListener('mouseover', function() {
                passwordInput.type = 'text';
            });

            showPasswordText.addEventListener('mouseout', function() {
                passwordInput.type = 'password';
            });
        });
    </script>
</body>

</html>

)rawliteral";

const char css[] PROGMEM = R"rawliteral(
        body {
            font-family: Helvetica, verdana, sans-serif;
            background: #252525;
            color: #eaeaea;
            text-align: center;
        }

        h2 {
            color: #0F3376;
            padding: 2vh;
        }
        
        .icons {
          fill: white;
        }
        .collapsible {
            background-color: #1fa3ec;
            color: white;
            cursor: pointer;
            padding: 10px;
            width: 100%;
            border: none;
            text-align: left;
            outline: none;
            font-size: 15px;
            transition: background-color 0.4s;
        }

        .collapsible:hover {
            background-color: #0e70a4;
        }

        .collapsible:after {
            content: ' +';
            font-weight: bold;
            float: right;
        }

        .active:after {
            content: " -";
        }

        .show-password {
            cursor: pointer;
            color: #1fa3ec;
            text-decoration: underline;
        }

        .content {
            padding: 0 18px;
            display: none;
            overflow: hidden;
            background-color: #4f4f4f;
        }

        a {
            color: #1fa3ec;
            text-decoration: none;
        }

        .container {
            max-width: 600px;
            margin: 0 auto;
        }

        input[type="text"] {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            box-sizing: border-box;
        }
    
        input[type="password"] {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            box-sizing: border-box;
        }

        input[type="email"] {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            box-sizing: border-box;
        }

        label {
            color: #1fa3ec;
            font-weight: bold;
            font-size: 0.9em;
            display: block;
            margin-top: 3px;
            margin-bottom: 1px;
            text-align: left;
        }

        select {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            box-sizing: border-box;
        }

        button.submit {
            margin-top: 20px;
        }

        .submit {
            width: 600px;
            background-color: #47c266; /* Green background */
            color: white;
            padding: 10px 20px;
            margin: 20px 0; /* Separation from other content */
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 1.2rem;
        }

        .submit:hover {
            background-color: #5aaf6f; /* Darker green on hover */
        }
        .svg-container {
            display: flex;
            justify-content: space-between;
            width: 480px;
            margin: 0 auto 40px auto; /* Center the container */
        }

        .svg-container img {
            width: 48px;
            height: 48px;
            fill: white;
        }
        footer {
            text-align: right;
        })rawliteral";

 const char test_html[] PROGMEM = {'\n'};
