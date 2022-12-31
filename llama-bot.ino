void setup() {
  Serial.begin(115200);
  delay(100);
  
  ServoSetup();
  BuzzerSetup();
}

void loop() {
  ServoControlLoop();
  BuzzerControlLoop();
}
