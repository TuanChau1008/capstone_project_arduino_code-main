#include <HCSR04.h>

const HCSR04 front_ObSensor(2, 3);  //initialisation class HCSR04 (trig pin , echo pin, number of sensor)

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(front_ObSensor.dist());  //return curent distance (cm) in serial for sensor
  Serial.println(" cm");
  Serial.println(" ");
  delay(1500);
}