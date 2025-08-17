#include <IRremote.h>
int buton = 0;
int mapCodeToButton(unsigned long code) {

  if ((code & 0x0000FFFF) == 0x0000BF00) {
    
    code >>= 16;
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;
  
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    result = mapCodeToButton(code);
    IrReceiver.resume();
  }
  return result;
}

void setup()
{
  IrReceiver.begin(2);

  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop()
{
  buton = readInfrared();
  Serial.println(buton);
  delay(1000); 
  if (buton == 16) {
    digitalWrite(12, HIGH);
  }
  if (buton == 17) {
    digitalWrite(12, LOW);
  }
}