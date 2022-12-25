#include <Adafruit_BMP085.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

int R = 8.314;
double V;


const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 1, 0}; 

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


Adafruit_BMP085 bmp;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  lcd.begin(16,2);
 }
}

void loop() {
   int T = bmp.readTemperature();
   int P = bmp.readPressure();
   char key = keypad.getKey();
   int n = - (P*V)/(R*T);
   

    lcd.setCursor(0,0);
    
  
   if(key == '7'){
    lcd.print(" T=");
     lcd.print(bmp.readTemperature() + 273);
     lcd.print("K  ");
  }
  else if(key == '*'){
    lcd.print("P=");
     lcd.print(bmp.readPressure()/1000);
     lcd.print("x10^3");
     lcd.print("Pa");
  }
  else if(key == '0'){
    lcd.print("n = ");
    lcd.print(n/4);
  }
  
  if(key == '2'){
    V+=1;
  }
  else if(key == '8'){
    V=V-1;
  }

  
  else if(key == '4'){
    V=V+0.10;
  }
  else if(key == '5'){
    lcd.clear();
  }
  if (key == '1'){
    lcd.print("V ="); 
    lcd.print(V);
    lcd.print("m^3");    
   
  }
 

    
    

}
