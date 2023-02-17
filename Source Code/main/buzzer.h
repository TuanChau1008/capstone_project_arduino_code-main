#define buzzer 32

void setupBuzzer() {
  pinMode(buzzer, OUTPUT);
  delay(500);
  digitalWrite(buzzer, HIGH);
}

void soundAlarm() {
  tone(buzzer, 2093, 500);
  digitalWrite(buzzer, LOW);  // Turn on sound for 500 miliseconds
  delay(500);
  digitalWrite(buzzer, HIGH); // Turn off sound for 500 miliseconds
  delay(1000);
}

void beepTwice() {
  digitalWrite(buzzer, LOW);  // Turn on sound for 500 miliseconds
  delay(200);
  digitalWrite(buzzer, HIGH); // Turn off sound for 500 miliseconds
  delay(100);
  
  digitalWrite(buzzer, LOW);  // Turn on sound for 500 miliseconds
  delay(200);
  digitalWrite(buzzer, HIGH); // Turn off sound for 500 miliseconds
  delay(100);
}