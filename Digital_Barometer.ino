#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <LiquidCrystal.h>


DHT dht(1, DHT11);
Adafruit_BMP085 bmp;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  dht.begin();
  bmp.begin();
  lcd.begin(16,2);
}

void loop() {
    Serial.print("P =");
    Serial.print(bmp.readSealevelPressure());
    Serial.println("Pa");


    Serial.print("Temperature = ");
    Serial.print(dht.readTemperature());
    Serial.println(" *C");



    lcd.setCursor(0,0);
    lcd.print("P=");
    lcd.print(bmp.readSealevelPressure());
    lcd.print("Pa");
    lcd.setCursor(1,0);
    lcd.print("Temperature =");
    lcd.print(dht.readTemperature());
    lcd.print("C");
}
