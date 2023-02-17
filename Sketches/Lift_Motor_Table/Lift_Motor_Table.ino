#define enT 46
#define in1MotorT 52
#define in2MotorT 53

void setup() {
  Serial.begin(9600);
  pinMode(in1MotorT, OUTPUT);
  pinMode(in2MotorT, OUTPUT);
  analogWrite(enT, 255);
}

void loop() {
  forward();
  delay(3000);
  reverse();
  delay(2000);
}

void forward() {
  digitalWrite(in1MotorT, HIGH);
  digitalWrite(in2MotorT, LOW);
}

void reverse() {
  digitalWrite(in1MotorT, LOW);
  digitalWrite(in2MotorT, HIGH);
}
