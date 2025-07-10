#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

int RST_PIN = 9;
int SS_PIN = 10;
int ServoPin = 8;


MFRC522 rfid(SS_PIN, RST_PIN);
Servo motor;

byte id[4] = {0,0,0,0};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  motor.attach(ServoPin);
  motor.write(0); 
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  if (kart()) {
    Serial.println("Anahtar dogru!");
    motor.write(180);  
    delay(1000);
    motor.write(0);   
    delay(1000);
  } else {
    Serial.println("Yanlis anahtar!");
  }

  yazdir();
  rfid.PICC_HaltA(); 
}

bool kart() {
  for (int i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != id[i])
      return true;
  }
  return true;
}

void yazdir() {
  Serial.print("Kart ID: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
