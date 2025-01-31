#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(4,5,6,7,8,9);
SoftwareSerial GSerial(11,12); 
char rec=0;

void setup()
{
  Serial.begin(9600);
  GSerial.begin(300);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" LiFi - Wireless");
  lcd.setCursor(0, 1);
  lcd.print(" Communication  ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" using Light    ");
  lcd.setCursor(0, 1);
  lcd.print(" RX TESTING ..  ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  By Group 8  ");
  lcd.setCursor(0,1); 
  lcd.print("    ED2   ");
  delay(3000);
  lcd.clear();
}

void loop()
{
  if(GSerial.available() != 0)
  {    
    rec = GSerial.read();
    if(rec=='^')
    {
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
    }
    else if(rec=='&')
    {
      lcd.clear();
    }
    
    else
    {
      Serial.print(rec);
      lcd.print(rec);
    }
  }
}
