#include <Servo.h>
Servo servo;
int pos=0;
int pozisyon=0;

void setup() {
  servo.attach(8);
}

void loop() {
  for(pos=0;pos<=360;pos+=1)
  {
    servo.write(pos);
    delay(100);  
  }
  for(pos=360;pos>=0;pos-=1)
  {
    servo.write(pos);
    delay(100);
    
  }
}
