#include "limit_switch.h"

// Stop lift motor
void stopLift() {
  digitalWrite(in1MotorT, LOW);
  digitalWrite(in2MotorT, LOW);
}

// Lift Motor Pickup
void pickProduct() {
  bool isPressed = checkLimitSwitch();

  while (!isPressed) {
    // Turn lift motor on and spin clock wise
    analogWrite(enT, 255);
    digitalWrite(in1MotorT, 1);
    digitalWrite(in2MotorT, 0);
    // Check if limit siwtch is pressed
    isPressed = checkLimitSwitch();
    delay(40);
  }

  if (isPressed) {
    delay(4000);
    stopLift();
    delay(1000);
  }
}

// Lift Motor Dropoff
void dropProduct() {
  bool isPressed = checkLimitSwitch();

  while (isPressed) {
    // Turn lift motor on and spin counter clock wise
    analogWrite(enT, 255);
    digitalWrite(in1MotorT, 0);
    digitalWrite(in2MotorT, 1);
    // Check if limit siwtch is pressed
    isPressed = checkLimitSwitch();
    delay(40);
  }

  if (!isPressed) {
    delay(4000);
    stopLift();
    delay(1000);
  }
}