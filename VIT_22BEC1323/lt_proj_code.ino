// C++ code
//
/*
  LiquidCrystal Library

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>

int count=0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  // Print a message to the LCD.
  lcd_1.print("Occupancy:");
}

void loop()
{
  
  if(digitalRead(10)==HIGH){
    digitalWrite(13,HIGH);
    delay(2000);
    digitalWrite(13,LOW);
    count++;
  }
  if(digitalRead(9)==HIGH){
    digitalWrite(8,HIGH);
    delay(2000);
    digitalWrite(8,LOW);
    if (count>0)
    {
      count--;
    }
  }
    // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  lcd_1.setCursor(0, 1);
  lcd_1.print("                ");
  lcd_1.setCursor(0, 1);
  lcd_1.print(count);
  
  if (count==0){
    digitalWrite(7,LOW);}
  else{
    digitalWrite(7,HIGH);}
  delay(1000); // Wait for 1000 millisecond(s
  
}