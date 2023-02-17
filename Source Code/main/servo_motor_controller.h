#include <Servo.h>

Servo servofront;
Servo servoleft;
Servo servoright;
Servo servoback;

int servoFrontPin = 48;
int servoLeftPin = 16;
int servoRightPin = 46;
int servoBackPin = 14;

int servoPositionFront = 0;
int servoPositionLeft = 0;
int servoPositionRight = 0;
int servoPositionBack = 0;

int servoSlowInterval = 20;
int servoFastInterval = 10;
int servoInterval = servoSlowInterval;
int servoDegrees = 8;

const int servoMinDegrees = 0;
const int servoMaxDegrees = 180;

unsigned long currentMillis = 0;
unsigned long previousServoMillis = 0;

void initServo() {
  servofront.attach(servoFrontPin);
  servoback.attach(servoBackPin);
  servoleft.attach(servoLeftPin);
  servoright.attach(servoRightPin);

  servoright.write(0);
  servoleft.write(0);
  servoback.write(0);
  servofront.write(0);
}

void servoSweepFront() {
  currentMillis = millis();
  
  if ((currentMillis - previousServoMillis) >= servoInterval) {
    previousServoMillis += servoInterval;
    servoPositionFront = servoPositionFront + servoDegrees;
    if (servoPositionFront <= servoMinDegrees) {
      if (servoInterval == servoSlowInterval) {
        servoInterval = servoFastInterval;
      } else {
        servoInterval = servoSlowInterval;
      }
    }
    if ((servoPositionFront >= servoMaxDegrees) || (servoPositionFront <= servoMinDegrees)) {
      servoDegrees = -servoDegrees;
      servoPositionFront = servoPositionFront + servoDegrees;
    }
    servofront.write(servoPositionFront);
  }
}

void servoSweepBack() {
  currentMillis = millis();
  
  if ((currentMillis - previousServoMillis) >= servoInterval) {
    previousServoMillis += servoInterval;
    servoPositionBack = servoPositionBack + servoDegrees;
    if (servoPositionBack <= servoMinDegrees) {
      if (servoInterval == servoSlowInterval) {
        servoInterval = servoFastInterval;
      } else {
        servoInterval = servoSlowInterval;
      }
    }
    if ((servoPositionBack >= servoMaxDegrees) || (servoPositionBack <= servoMinDegrees)) {
      servoDegrees = -servoDegrees;
      servoPositionBack = servoPositionBack + servoDegrees;
    }
    servoback.write(servoPositionBack);
  }
}

void servoSweepLeft() {
  currentMillis = millis();
  
  if ((currentMillis - previousServoMillis) >= servoInterval) {
    previousServoMillis += servoInterval;
    servoPositionLeft = servoPositionLeft + servoDegrees;
    if (servoPositionLeft <= servoMinDegrees) {
      if (servoInterval == servoSlowInterval) {
        servoInterval = servoFastInterval;
      } else {
        servoInterval = servoSlowInterval;
      }
    }
    if ((servoPositionLeft >= servoMaxDegrees) || (servoPositionLeft <= servoMinDegrees)) {
      servoDegrees = -servoDegrees;
      servoPositionLeft = servoPositionLeft + servoDegrees;
    }
    servoleft.write(servoPositionLeft);
  }
}

void servoSweepRight() {
  currentMillis = millis();
  
  if ((currentMillis - previousServoMillis) >= servoInterval) {
    previousServoMillis += servoInterval;
    servoPositionRight = servoPositionRight + servoDegrees;
    if (servoPositionRight <= servoMinDegrees) {
      if (servoInterval == servoSlowInterval) {
        servoInterval = servoFastInterval;
      } else {
        servoInterval = servoSlowInterval;
      }
    }
    if ((servoPositionRight >= servoMaxDegrees) || (servoPositionRight <= servoMinDegrees)) {
      servoDegrees = -servoDegrees;
      servoPositionRight = servoPositionRight + servoDegrees;
    }
    servoright.write(servoPositionRight);
  }
}