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

void setup() {
  Serial.begin(9600); 
  Serial.println("Lutfen bir tusa bas...");
pinMode(13, OUTPUT);
}

void loop() {
  char key = keypad1.getKey(); 

  if (key) { 
    Serial.print("Basilan: "); 
    Serial.println(key);    
  }
  if(key=='1')
  {
    digitalWrite(13,HIGH);
  }

  if(key=='2')
  {
    digitalWrite(13,LOW);
  }
}
