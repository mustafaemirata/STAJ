#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int setButton  = 8;
const int upButton   = 9;
const int downButton = 10;

int hours = 0;
int minutes = 0;
int seconds = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

enum State {
  RUNNING,
  SET_HOURS,
  SET_MINUTES
};

State currentState = RUNNING;

void setup() {
  pinMode(setButton, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Digital Clock");
  delay(1500);
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();
//SET
  if (digitalRead(setButton) == LOW) {
    delay(50);
    if (digitalRead(setButton) == LOW) {
      if (currentState == RUNNING) {
        currentState = SET_HOURS;
      } else if (currentState == SET_HOURS) {
        currentState = SET_MINUTES;
      } else {
        currentState = RUNNING;
      }
      delay(200); 
    }
  }

  if (currentState == RUNNING) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      seconds++;
      if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
          minutes = 0;
          hours = (hours + 1) % 24;
        }
      }
    }
  }

//AYAR
  else if (currentState == SET_HOURS) {
    if (digitalRead(upButton) == LOW) {
      hours = (hours + 1) % 24;
      delay(200);
    }
    if (digitalRead(downButton) == LOW) {
      hours = (hours - 1 + 24) % 24;
      delay(200);
    }
  }

  else if (currentState == SET_MINUTES) {
    if (digitalRead(upButton) == LOW) {
      minutes = (minutes + 1) % 60;
      delay(200);
    }
    if (digitalRead(downButton) == LOW) {
      minutes = (minutes - 1 + 60) % 60;
      delay(200);
    }
  }
//LCD GĞNCELLE
  lcd.setCursor(0, 0);
  if (currentState == SET_HOURS) {
    lcd.print("Set Hours    ");
  } else if (currentState == SET_MINUTES) {
    lcd.print("Set Minutes  ");
  } else {
    lcd.print("Digital Clock");
  }

  lcd.setCursor(0, 1);
  if (hours < 10) lcd.print('0');
  lcd.print(hours);
  lcd.print(':');
  if (minutes < 10) lcd.print('0');
  lcd.print(minutes);
  lcd.print(':');
  if (seconds < 10) lcd.print('0');
  lcd.print(seconds);
}
