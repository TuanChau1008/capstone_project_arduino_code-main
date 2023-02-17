void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(13, OUTPUT);
  delay(500);
  Serial.println("AT+CIPMUX=1");
  Serial3.println("AT+CIPMUX=1");
  delay(2000);
  Serial.println("AT+CIPSERVER=1,5000");
  Serial3.println("AT+CIPSERVER=1,5000");
  delay(2000);
  Serial.println("AT+CIPSERVER=1,5000");
  Serial3.println("AT+CIPSTO=3600");
  delay(2000);
}

void loop() {
  // listen for communication from the ESP8266 and then write it to the serial monitor
  if (Serial3.available()) {
    Serial.write(Serial3.read());
  }

  // listen for user input and send it to the ESP8266
  if (Serial.available()) {
    Serial3.write(Serial.read());
  }
}