int buzzerP=7;
void setup() {
pinMode(buzzerP,OUTPUT);
}

void loop() {
  digitalWrite(buzzerP,HIGH);
  delay(2000);

  digitalWrite(buzzerP,LOW);
  delay(2000);
}
