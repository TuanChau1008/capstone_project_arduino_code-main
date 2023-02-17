#define limitSwitch 41

void setupLimitSwitch() {
  pinMode(limitSwitch, INPUT);
}

bool checkLimitSwitch() {
  if (digitalRead(limitSwitch) == LOW) {
    return true;
    delay(40);
  }
  return false;
  delay(40);
}