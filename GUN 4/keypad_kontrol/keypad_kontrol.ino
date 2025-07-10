#include <Keypad.h>
#include <Servo.h>

const byte satirSayisi = 4;
const byte sutunSayisi = 3;

char tusTakimi[satirSayisi][sutunSayisi] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte satirPinleri[satirSayisi] = {9, 8, 7, 6};
byte sutunPinleri[sutunSayisi] = {5, 4, 3};

Keypad tusTakimiModulu = Keypad(makeKeymap(tusTakimi), satirPinleri, sutunPinleri, satirSayisi, sutunSayisi);
Servo kilitMotoru;

String dogruSifre = "1907";
String girilenSifre = "";

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);

  kilitMotoru.attach(11);
}

void loop() {
  char tus = tusTakimiModulu.getKey();

  if (tus) {
    Serial.print("Basilan tus: ");
    Serial.println(tus);

    if (tus >= '0' && tus <= '9') {
      girilenSifre += tus;

      if (girilenSifre.length() == dogruSifre.length()) {
        if (girilenSifre == dogruSifre) {
          Serial.println("Sifre Dogru! Yesil LED Yandi");
          digitalWrite(10, HIGH);
          delay(1000);
          digitalWrite(10, LOW);
          kilitMotoru.write(180);
        } else {
          Serial.println("Sifre Hatali! Kirmizi LED Yandi");
          digitalWrite(13, HIGH);
          delay(1000);
          digitalWrite(13, LOW);
        }
        girilenSifre = "";
      }
    }

    if (tus == '*') {
      Serial.println("Sifirlandi.");
      girilenSifre = "";
      digitalWrite(13, LOW);
    }
  }
}
