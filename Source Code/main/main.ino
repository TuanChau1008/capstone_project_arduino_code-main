#include <SoftwareSerial.h>

#include "motor_controller.h"
#include "line_sensor_controller.h"
#include "loadcell.h"
#include "run_cases.h"

int mode = 0;

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  Serial.println();

  Serial.println("AT+CIPMUX=1");
  Serial3.println("AT+CIPMUX=1");
  delay(40);

  Serial.println("AT+CIPSERVER=1,5000");
  Serial3.println("AT+CIPSERVER=1,5000");
  delay(40);

  Serial.println("AT+CIPSTO=3600");
  Serial3.println("AT+CIPSTO=3600");
  delay(40);

  setupMotor();
  setupLineSensor();
  setupLimitSwitch();
  setupBuzzer();
}

void loop() {
  while (Serial3.available() > 0) {
    // listen for communication from the ESP8266 and then write it to the serial monitor
    const char received = Serial3.read();
    Serial.print(received);

    if (received == '`') {
      mode = 1;
    }
    if (received == '~') {
      mode = 2;
    }

    switch (mode) {
      case 1:
        Serial.println("Enter Manual Control");
        delay(40);
        manualControl();
        break;
      case 2:
        Serial.println("Enter Auto Control");
        delay(40);
        autoControl();
        break;
      default:
        break;
    }
  }
}

void autoControl() {
  while (true) {
    char fromESP = Serial3.read();

    if (fromESP == 'x') {
      Serial.println("Exit mode");
      break;
    } else {
      Serial.println("Input task: ");
      while (Serial3.available() == 0) {}
      char task = Serial3.read();
      int targetRow = Serial3.parseInt();  // row number the robot needed to drive to
      char targetSide = Serial3.read();     // side the robot needed to take a turn
      
      Serial.println(task);
      Serial.println(targetRow);
      Serial.println(targetSide);

      if (task == 'p' && targetRow != 0) {
        beepTwice();
        pickupTask(targetRow, targetSide);
      }
      if (task == 'd' && targetRow != 0) {
        beepTwice();
        dropTask(targetRow, targetSide);
      }

      task = "";
      targetRow = 0;
      targetSide = "";
    }
  }
}

void manualControl() {
  while (true) {
    char fromESP = Serial3.read();

    if (fromESP == 'x') {
      Serial.println("Exit mode");
      break;
    } else {
    }
    if (fromESP == 'f') {
      Serial.println("move_forward");
      moveForward(100, 90, 120, 90);
      delay(10);
    }
    if (fromESP == 'b') {
      Serial.println("move_backward");
      moveBackward(80, 80, 100, 80);
      delay(10);
    }
    if (fromESP == 'l') {
      Serial.println("move_left");
      moveLeft(90, 90, 110, 90);
      delay(10);
    }
    if (fromESP == 'r') {
      Serial.println("move_right");
      moveRight(90, 90, 110, 90);
      delay(10);
    }
    if (fromESP == '<') {
      Serial.println("rotate_left");
      rotateLeft(90, 90, 110, 90);
      delay(10);
    }
    if (fromESP == '>') {
      Serial.println("rotate_right");
      rotateRight(90, 90, 110, 90);
      delay(10);
    }
    if (fromESP == 's') {
      Serial.println("stop_bot");
      stopBot(100);
      delay(10);
    }
  }
}

// listen for communication from the ESP8266 and then write it to the serial monitor
// if (Serial3.available()) {
//   Serial.write(Serial3.read());
// }

// // listen for user input and send it to the ESP8266
// if (Serial.available()) {
//   Serial3.write(Serial.read());
// }