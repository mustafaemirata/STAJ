
#include <Adafruit_LiquidCrystal.h>
#include "Adafruit_LEDBackpack.h"

int ultra = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Adafruit_LiquidCrystal lcd_1(0);

Adafruit_7segment led_display1 = Adafruit_7segment();

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  led_display1.begin(112);
}

void loop()
{
  ultra = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.println(ultra);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Mesafe");
  lcd_1.setCursor(1, 1);
  lcd_1.print(ultra);
  delay(300); 
  led_display1.clear();
  led_display1.writeDisplay();
}
