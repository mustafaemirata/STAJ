int led1 = 12;  // 1. LED pini
int led2 = 13;  // 2. LED pini

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // LED1 yanar
  digitalWrite(led2, LOW);   // LED2 söner
  delay(100);                // 0.5 saniye bekle

  digitalWrite(led1, LOW);   // LED1 söner
  digitalWrite(led2, HIGH);  // LED2 yanar
  delay(100);                // 0.5 saniye bekle
}
