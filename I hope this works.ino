#include <Adafruit_BMP085.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

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
   char key = keypad.getKey();
   int n;
   int R = 8.314;
   int T = bmp.readTemperature();
   int P = bmp.readPressure();
   int V = (n*R*T)/P;


    lcd.setCursor(0,0);
    
  if (key == 'A'){
    lcd.print(n);
   
  }
  else if(key == 'B'){
    lcd.print(T);
  }
  else if(key == 'C'){
    lcd.print(P);
  }
  else if(key == 'D'){
    lcd.print(V);
  }
  
  if(key == '2'){
    n+=10;
  }
  else if(key == '8'){
    n=n-10;
  }
  else if(key == '6'){
    n+=1;
  }
  else if(key == '4'){
    n = n-1;
  }
 
}
    else{
      lcd.clear();
    }
    
    
    

}
