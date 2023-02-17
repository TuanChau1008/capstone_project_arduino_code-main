#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <Firebase_ESP_Client.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

/* 1. Define the WiFi credentials */
// #define WIFI_SSID "MinhNHN"
// #define WIFI_PASSWORD "minhnhn130517"

#define WIFI_SSID "MinhNHN2"
#define WIFI_PASSWORD "minhnhn130517"

/* 2. Define the API Key */
#define API_KEY "AIzaSyCP34kcnA7vZdJHj8z8DyYhqrlrDvlTDl4"

/* 3. Define the RTDB URL */
#define DATABASE_URL "amwr-data-default-rtdb.asia-southeast1.firebasedatabase.app"  //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "minhnhnse130517@fpt.edu.vn"
#define USER_PASSWORD "se130517"

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// Define Web Updater Server
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

// Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson json;

const char *host = "esp8266-webupdate";
unsigned long sendDataPrevMillis = 0;
char received;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.println("WiFi failed, retrying.");
  }

  timeClient.begin();
  timeClient.setTimeOffset(25200);

  MDNS.begin(host);

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);

  Serial.println();
  Serial.print("Connected to WiFi");
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback;  //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);

  Firebase.reconnectWiFi(true);
}

// void loop() {
//   timeClient.update();

//   time_t epochTime = timeClient.getEpochTime();
//   Serial.print("Epoch Time: ");
//   Serial.println(epochTime);

//   String formattedTime = timeClient.getFormattedTime();
//   Serial.print("Formatted Time: ");
//   Serial.println(formattedTime);

//   int currentHour = timeClient.getHours();
//   Serial.print("Hour: ");
//   Serial.println(currentHour);

//   int currentMinute = timeClient.getMinutes();
//   Serial.print("Minutes: ");
//   Serial.println(currentMinute);

//   int currentSecond = timeClient.getSeconds();
//   Serial.print("Seconds: ");
//   Serial.println(currentSecond);

//   //Get a time structure
//   struct tm *ptm = gmtime((time_t *)&epochTime);

//   int monthDay = ptm->tm_mday;
//   Serial.print("Month day: ");
//   Serial.println(monthDay);

//   int currentMonth = ptm->tm_mon + 1;
//   Serial.print("Month: ");
//   Serial.println(currentMonth);

//   int currentYear = ptm->tm_year + 1900;
//   Serial.print("Year: ");
//   Serial.println(currentYear);

//   //Print complete date:
//   String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
//   Serial.print("Current date: ");
//   Serial.println(currentDate);

//   Serial.println("");

//   delay(2000);
// }

void loop() {
  httpServer.handleClient();
  MDNS.update();

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 100 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    int modeInt = 0;
    String operateMode = "";

    if (Firebase.RTDB.getString(&fbdo, "/operate-mode/mode")) {
      if (fbdo.dataType() == "string") {
        operateMode = fbdo.stringData();
      }
    } else {
      Serial.println(fbdo.errorReason());
    }

    if (operateMode == "manual_control") {
      modeInt = 1;
    }
    if (operateMode == "auto_control") {
      modeInt = 2;
    }

    switch (modeInt) {
      case 1:
        Serial.print('`');
        delay(100);
        manualControl();
        break;
      case 2:
        Serial.print('~');
        delay(100);
        autoControl();
        break;
      default:
        break;
    }
  }
}

void autoControl() {
  String operateMode = "";
  String task = "";
  String location = "";

  while (true) {
    if (Firebase.ready() && (millis() - sendDataPrevMillis > 100 || sendDataPrevMillis == 0)) {
      sendDataPrevMillis = millis();

      if (Firebase.RTDB.getString(&fbdo, "/operate-mode/mode")) {
        if (fbdo.dataType() == "string") {
          operateMode = fbdo.stringData();
        }
      } else {
        Serial.println(fbdo.errorReason());
      }

      delay(40);

      if (operateMode == "exit_mode") {
        Serial.print('x');
        delay(100);
        break;
      } else {
        // task = Firebase.RTDB.getString(&fbdo, "/auto-control/task") ? fbdo.stringData() : fbdo.errorReason().c_str();
        // location = Firebase.RTDB.getString(&fbdo, "/auto-control/product_location") ? fbdo.stringData() : fbdo.errorReason().c_str();
        // while(Serial.available() == 0) {}
        if (Firebase.RTDB.getString(&fbdo, "/auto-control/task")) {
          if (fbdo.dataType() == "string") {
            task = fbdo.stringData();

            if (task == "pickup") {
              Serial.print('p');
            }
            if (task == "drop off") {
              Serial.print('d');
            }
          }
        } else {
          Serial.println(fbdo.errorReason());
        }

        delay(40);

        if (Firebase.RTDB.getString(&fbdo, "/auto-control/product_location")) {
          if (fbdo.dataType() == "string") {
            location = fbdo.stringData();

            if (location == "1A") {
              Serial.print('1');
              Serial.println('A');
            }
            if (location == "1B") {
              Serial.print('1');
              Serial.println('B');
            }
            if (location == "2A") {
              Serial.print('2');
              Serial.println('A');
            }
            if (location == "2B") {
              Serial.print('2');
              Serial.println('B');
            }
          }
        } else {
          Serial.println(fbdo.errorReason());
        }

        Serial.flush();
        delay(100);

        // While Serial still open, loop reading from Arduino
        // if received char 'D' from Arduino, set task_progress
        // as "Done" on firebase
        while (Serial.available() > 0) {
          char fromArduino = Serial.read();
          delay(40);

          if (fromArduino == 'D') {
            Firebase.RTDB.setString(&fbdo, "/current_operation/data/task_progress", "Done") ? "ok" : fbdo.errorReason().c_str();
            delay(40);
            break;
          }
        }
      }
    }
  }
}

void manualControl() {
  while (true) {
    if (Firebase.ready() && (millis() - sendDataPrevMillis > 100 || sendDataPrevMillis == 0)) {
      sendDataPrevMillis = millis();

      String operateMode = "";
      String direction = "";

      if (Firebase.RTDB.getString(&fbdo, "/operate-mode/mode")) {
        if (fbdo.dataType() == "string") {
          operateMode = fbdo.stringData();
        }
      } else {
        Serial.println(fbdo.errorReason());
      }

      if (operateMode == "exit_mode") {
        Serial.print('x');
        delay(50);
        break;
      } else {
        if (Firebase.RTDB.getString(&fbdo, "/manual-control/direction")) {
          if (fbdo.dataType() == "string") {
            direction = fbdo.stringData();
          }
        } else {
          Serial.println(fbdo.errorReason());
        }

        if (direction == "f") {
          Serial.println('f');
          delay(10);
        }
        if (direction == "b") {
          Serial.println('b');
          delay(10);
        }
        if (direction == "l") {
          Serial.println('l');
          delay(10);
        }
        if (direction == "r") {
          Serial.println('r');
          delay(10);
        }
        if (direction == "q") {
          Serial.println('<');
          delay(10);
        }
        if (direction == "e") {
          Serial.println('>');
          delay(10);
        }
        if (direction == "s") {
          Serial.println('s');
          delay(10);
        }
      }
    }
  }
  if (Serial.available() > 0) {
    Serial.read();
  }
}
