#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
const int rs = 8, en = 13, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
char d;
String data,D;
bool rec = false;
int i,a;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//SoftwareSerial lifi(2, 3);
void setup() {
  Serial.begin(4800);
  //lifi.begin(4800);
  lcd.begin(16, 2);
  lcd.print("    WELCOME     ");
  delay(2000);
  lcd.clear();
  lcd.print(" REAL TIME DATA ");
  lcd.setCursor(0,1);
  lcd.print("  TRANSMISSION  ");
  delay(3000);
  lcd.clear();
  lcd.print("   USING LI-FI  ");
  lcd.setCursor(0,1);
  lcd.print("   TECHNOLOGY   ");
}

void loop() {
  while (Serial.available() > 0)
  {
    delayMicroseconds(500);
    d = Serial.read();
    
    a = d;
    //Serial.println(a);
    if (a == 10)
    {
      //Serial.println(data);
      rec = true;
      break;
    }
    data += d;
    //Serial.println(Serial.read());
  }
  if (rec == true)
  {
    lcd.clear();
    
    for(i = 0; i<=data.length()-2; i++)
    {
      D += data[i];
    }
    Serial.println(D);
    if(D.length() > 16)
    {
      lcd.setCursor(0,0);
      for(i = 0; i<=15; i++)
      {
        lcd.print(D[i]);
      }
      lcd.setCursor(0,1);
      for(i = 16; i<=(D.length()-1); i++)
      {
        lcd.print(D[i]);
      }
    }
    else
    {
      lcd.print(D);
    }
    
    rec = false;
    data = "";
    D = "";
    
  }
}
