void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println((-40 + 0.488155 * (analogRead(A0) - 20)));
  delay(50000);
}
