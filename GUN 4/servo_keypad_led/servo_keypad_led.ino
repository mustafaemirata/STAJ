#include <Servo.h>

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3;


char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};


byte rowPins[ROWS] = {9, 8, 7, 6}; 


byte colPins[COLS] = {5, 4, 3};
 
Keypad keypad1 = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Servo servo;

void setup() {
  Serial.begin(9600); 
  Serial.println("Lutfen bir tusa bas...");
  pinMode(13, OUTPUT);
  servo.attach(11);
}

void loop() {
  char key = keypad1.getKey(); // Basılan tuşu oku

  if (key) { 
    Serial.print("Basilan Tus: "); 
    Serial.println(customKey);    
  }
  if(key=='1')
  {
    digitalWrite(13,HIGH);
  }

  if(key=='2')
  {
    digitalWrite(13,LOW);
  }
   if(key=='4')
  {
    servo.write(0);
  }
   if(key=='5')
  {
    servo.write(60);
  }
  if(key=='6')
  {
    servo.write(120);
  }
   if(key=='7')
  {
    servo.write(180);
  }
   if(key=='8')
  {
    servo.write(20);
    digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000); 
  }
}
