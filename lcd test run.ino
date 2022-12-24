
#include <LiquidCrystal.h>


const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
   lcd.print("Hello World");
}
