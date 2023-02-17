#include "obstacle_sensor_controller.h"
#include "buzzer.h"

// FRONT SENSOR
#define IRF1 21
#define IRF2 20

// LEFT SENSOR
#define IRL1 44
#define IRL2 45

// RIGHT SENSOR
#define IRR1 22
#define IRR2 23

// BACK SENSOR
#define IRB1 18
#define IRB2 19

int IRF1Value = 0;
int IRF2Value = 0;
int IRL1Value = 0;
int IRL2Value = 0;
int IRR1Value = 0;
int IRR2Value = 0;
int IRB1Value = 0;
int IRB2Value = 0;

void setupLineSensor() {
  pinMode(IRF1, INPUT);
  pinMode(IRF2, INPUT);
  pinMode(IRL1, INPUT);
  pinMode(IRL2, INPUT);
  pinMode(IRR1, INPUT);
  pinMode(IRR2, INPUT);
  pinMode(IRB1, INPUT);
  pinMode(IRB2, INPUT);
}

// Follow line forward
void lineFollowForward() {
  IRF1Value = digitalRead(IRF1);
  IRF2Value = digitalRead(IRF2);
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);

  bool isDetected = frontObstacleCheck();

  if (isDetected) {
    stopBot(100);
    soundAlarm();
  } else {
    if (IRF1Value == 1 && IRF2Value == 1) {
      Serial.println("Forward");
      moveForward(130, 105, 150, 125);
      delay(40);
    }
    if ((IRF1Value == 0 && IRF2Value == 1 && IRB1Value == 1 && IRB2Value == 1) || 
    (IRF1Value == 0 && IRF2Value == 1 && IRB1Value == 0 && IRB2Value == 0)) {
      Serial.println("Forward right");
      moveForward(180, 105, 200, 125);
      delay(40);
    }
    if ((IRF1Value == 1 && IRF2Value == 0 && IRB1Value == 1 && IRB2Value == 1) || 
    (IRF1Value == 1 && IRF2Value == 0 && IRB1Value == 0 && IRB2Value == 0)) {
      Serial.println("Forward left");
      moveForward(110, 155, 130, 175);
      delay(40);
    }
    if ((IRF1Value == 0 && IRF2Value == 1 && IRB1Value == 0 && IRB2Value == 1) || 
    (IRF1Value == 0 && IRF2Value == 0 && IRB1Value == 0 && IRB2Value == 1)) {
      Serial.println("Move forward diagonal right");
      moveForwardDiagonalRight(110, 125);
      delay(40);
    }
    if ((IRF1Value == 1 && IRF2Value == 0 && IRB1Value == 1 && IRB2Value == 0) || 
    (IRF1Value == 0 && IRF2Value == 0 && IRB1Value == 1 && IRB2Value == 0)) {
      Serial.println("Move forward diagonal left");
      moveForwardDiagonalLeft(115, 130);
      delay(40);
    }
    if (IRF1Value == 0 && IRF2Value == 0) {
      stopBot(100);
      soundAlarm();
      delay(40);
    }
  }
}

// Follow line backward
void lineFollowBackward() {
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  IRF1Value = digitalRead(IRF1);
  IRF2Value = digitalRead(IRF2);

  bool isDetected = backObstacleCheck();

  if (isDetected) {
    stopBot(100);
    soundAlarm();
  } else {
    if (IRB1Value == 1 && IRB2Value == 1) {
      Serial.println("Backward");
      moveBackward(110, 105, 130, 125);
      delay(40);
    }
    if ((IRB1Value == 1 && IRB2Value == 0 && IRF1Value == 1 && IRF2Value == 1) || 
    (IRB1Value == 1 && IRB2Value == 0 && IRF1Value == 0 && IRF2Value == 0)) {
      Serial.println("Backward left");
      moveBackward(100, 165, 130, 195);
      delay(40);
    }
    if ((IRB1Value == 0 && IRB2Value == 1 && IRF1Value == 1 && IRF2Value == 1) || 
    (IRB1Value == 0 && IRB2Value == 1 && IRF1Value == 0 && IRF2Value == 0)) {
      Serial.println("Backward right");
      moveBackward(160, 105, 190, 125);
      delay(40);
    }
    if ((IRB1Value == 1 && IRB2Value == 0 && IRF1Value == 1 && IRF2Value == 0) || 
    (IRB1Value == 0 && IRB2Value == 0 && IRF1Value == 1 && IRF2Value == 0)) {
      Serial.println("Move back diagonal left");
      moveBackDiagonalLeft(110, 125);
      delay(40);
    }
    if ((IRB1Value == 0 && IRB2Value == 1 && IRF1Value == 0 && IRF2Value == 1) || 
    (IRB1Value == 0 && IRB2Value == 0 && IRF1Value == 0 && IRF2Value == 1)) {
      Serial.println("Move back diagonal right");
      moveBackDiagonalRight(105, 130);
      delay(40);
    }
    if (IRB1Value == 0 && IRB2Value == 0) {
      stopBot(100);
      Serial.println("Stop");
      soundAlarm();
      delay(40);
    }
  }
}

// Follow line right side
void lineFollowRight() {
  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);
  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);

  bool isDetected = rightObstacleCheck();

  if (isDetected) {
    stopBot(100);
    soundAlarm();
  } else {
    if (IRR1Value == 1 && IRR2Value == 1) {
      Serial.println("Move right");
      moveRight(120, 125, 135, 125);
      delay(40);
    }
    if (IRR1Value == 0 && IRR2Value == 1 && IRL1Value == 1 && IRL2Value == 1) {
      Serial.println("Rotate right");
      moveRight(150, 155, 135, 125);
      delay(40);
    }
    if (IRR1Value == 1 && IRR2Value == 0 && IRL1Value == 1 && IRL2Value == 1) {
      Serial.println("Rotate left");
      moveRight(120, 125, 165, 155);
      delay(40);
    }
    if ((IRR1Value == 0 && IRR2Value == 1 && IRL1Value == 0 && IRL2Value == 1) || 
    (IRR1Value == 0 && IRR2Value == 1 && IRL1Value == 0 && IRL2Value == 0)) {
      Serial.println("Move back diagonal right");
      moveBackDiagonalRight(105, 115);
      delay(40);
    }
    if ((IRR1Value == 1 && IRR2Value == 0 && IRL1Value == 1 && IRL2Value == 0) || 
    (IRR1Value == 1 && IRR2Value == 0 && IRL1Value == 0 && IRL2Value == 0)) {
      Serial.println("Move forward diagonal right");
      moveForwardDiagonalRight(100, 105);
      delay(40);
    }
    if (IRR1Value == 0 && IRR2Value == 0) {
      stopBot(100);
      soundAlarm();
      delay(40);
    }
  }
}

// Follow line left side
void lineFollowLeft() {
  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);
  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);

  bool isDetected = leftObstacleCheck();

  if (isDetected) {
    stopBot(100);
    soundAlarm();
  } else {
    if (IRL1Value == 1 && IRL2Value == 1) {
      Serial.println("Move left");
      moveLeft(120, 125, 135, 125);
      delay(40);
    }
    if (IRL1Value == 0 && IRL2Value == 1 && IRR1Value == 1 && IRR2Value == 1) {
      Serial.println("Rotate left");
      moveLeft(200, 125, 215, 125);
      delay(40);
    }
    if (IRL1Value == 1 && IRL2Value == 0 && IRR1Value == 1 && IRR2Value == 1) {
      Serial.println("Rotate right");
      moveLeft(120, 125, 205, 195);
      delay(40);
    }
    if ((IRL1Value == 1 && IRL2Value == 0 && IRR1Value == 1 && IRR2Value == 0) || 
    (IRL1Value == 1 && IRL2Value == 0 && IRR1Value == 0 && IRR2Value == 0)) {
      Serial.println("Move forward diagonal left");
      moveForwardDiagonalLeft(105, 115);
      delay(40);
    }
    if ((IRL1Value == 0 && IRL2Value == 1 && IRR1Value == 0 && IRR2Value == 1) || 
    (IRL1Value == 0 && IRL2Value == 1 && IRR1Value == 0 && IRR2Value == 0)) {
      Serial.println("Move back diagonal left");
      moveBackDiagonalLeft(100, 105);
      delay(40);
    }
    if (IRL1Value == 0 && IRL2Value == 0) {
      stopBot(100);
      soundAlarm();
      delay(40);
    }
  }
}

// Count each row while moving forward
void lineFollowCountRow(int targetRow) {
  Serial.println("Moving to destination");
  IRF1Value = digitalRead(IRF1);
  IRF2Value = digitalRead(IRF2);
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  int rowCount = 0;
  bool rowDetected = false;

  while (rowCount < targetRow) {
    lineFollowForward();
    // get IR sensor readings
    IRR1Value = digitalRead(IRR1);
    IRL1Value = digitalRead(IRL1);
    delay(40);
    // toggle between checking for line versus checking for no line
    if (rowDetected == false) {
      // when all 2 side sensors detect line, increase line count and toggle to checking for no line
      if ((IRR1Value == 1 && IRL1Value == 1)) {
        rowCount += 1;
        rowDetected = true;
        delay(100);
      }
    } else if (rowDetected == true) {
      // when all side sensors are 0, toggle back to checking for line
      if ((IRR1Value == 0 && IRL1Value == 0)) {
        rowDetected = false;
      }
    }
  }
  // target line count reached
  rowCount = 0;
  stopBot(1000);
}