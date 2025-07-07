void setup() {
  pinMode(8, INPUT);   
  pinMode(9, OUTPUT);    
}

void loop() {
  if (digitalRead(8) == HIGH) {
    digitalWrite(9, HIGH); 
  } else {
    digitalWrite(9, LOW);  
  }
}
