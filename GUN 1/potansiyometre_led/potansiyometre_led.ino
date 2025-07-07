int led = 9;      
int potPin = A0; 
int potDeger;     
void setup() {
  pinMode(led, OUTPUT); 
}
void loop() {
potDeger = analogRead(potPin); 
potDeger = map(potDeger, 0, 1023, 0, 255);
analogWrite(led, potDeger); 
delay(10);  
}
