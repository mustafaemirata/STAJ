#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(32, 16, 2);

void setup() {
  lcd_1.init();
  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();
}

void loop() {
  lcd_1.setCursor(0, 0);
  lcd_1.print("mustafa emir");
  delay(3000);
  lcd_1.clear();

  
  lcd_1.setCursor(0, 0);
  lcd_1.print("ata");
  delay(1000);
  lcd_1.clear();

 

  lcd_1.clear();
}
