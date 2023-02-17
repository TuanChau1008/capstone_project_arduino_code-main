#include "servo_motor_controller.h"
#include <HCSR04.h>

// Initialise HCSR04 sensor (trig pin , echo pin)
const HCSR04 frontObSensor(26, 27);

const HCSR04 backObSensor(31, 30);

const HCSR04 leftObSensor(43, 42);

const HCSR04 rightObSensor(25, 24);

int frontObSensorDist = 0;
int backObSensorDist = 0;
int leftObSensorDist = 0;
int rightObSensorDist = 0;

bool frontObstacleCheck() {
  frontObSensorDist = frontObSensor.dist();

  if (frontObSensorDist == 0 || frontObSensorDist > 20) {
    // servoSweepFront();
    return false;
  } else if (frontObSensorDist > 0 && frontObSensorDist <= 20) {
    // servofront.write(servoPositionFront);
    Serial.println("Front obstacles detected!");
    return true;
  }
}

bool backObstacleCheck() {
  backObSensorDist = backObSensor.dist();

  if (backObSensorDist == 0 || backObSensorDist > 20) {
    // servoSweepBack();
    return false;
  } else if (backObSensorDist > 0 && backObSensorDist <= 20) {
    // servoback.write(servoPositionBack);
    Serial.println("Back obstacle detected!");
    return true;
  }
}

bool leftObstacleCheck() {
  leftObSensorDist = leftObSensor.dist();

  if (leftObSensorDist == 0 || leftObSensorDist > 20) {
    return false;
  } else if (leftObSensorDist > 0 && leftObSensorDist <= 20) {
    Serial.println("Left obstacles detected!");
    return true;
  }
}

bool rightObstacleCheck() {
  rightObSensorDist = rightObSensor.dist();

  if (rightObSensorDist == 0 || rightObSensorDist > 20) {
    return false;
  } else if (rightObSensorDist > 0 && rightObSensorDist <= 20) {
    Serial.println("Right obstacles detected!");
    return true;
  }
}