#include<LiquidCrystal.h>
#define sensor A5 //28 lm35 
#define VOLT A3   //24 solar pannel
#define LUX A4    //27 ldr
LiquidCrystal lcd( 10, 9, 8, 7, 6, 5);   // rs ,e.....

float Temperature, temp, volt, volts,lux,Temp;
int temp1, value;

byte degree[8] = 
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

void setup()
{
  lcd.begin(16,2);
  lcd.createChar(1, degree);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("   SESGOIFOE   ");
  lcd.setCursor(0,1);
  lcd.print(" Diksal-Karjat ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Solar Energy  ");
  lcd.setCursor(0,1);
  lcd.print("  Measurement   ");
  delay(2000);
  lcd.clear();
}

void loop()
{
  /*---------Temperature-------*/
     float reading=analogRead(sensor);
     Temperature=reading*(5.0/1023.0)*100;
     delay(10);
      
  /*---------Voltage----------*/
  
  temp1=analogRead(VOLT);
  volts= (temp1/102.3)*5;     //2000/(2000+18000)*1024=102.3
  delay(10);
  /*-----Light Intensity------*/
  
   value=analogRead(LUX);
   volt=(value/1023.0)*5;
   lux=((2500/volt)-500)/3.3;
   delay(10);
  
  /*------Display Result------*/
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T:");
    lcd.print((int)Temperature);
    lcd.write(1);
    lcd.print("C");
    
    lcd.setCursor(8,0);
    lcd.print("V:");
    lcd.print(volts);
    
    lcd.setCursor(0,1);
    lcd.print("Intens: ");
    lcd.print((int)lux);
    lcd.print(" Lux");
   
   
   Serial.println((int)Temp);
   Serial.println(volts);
   Serial.println((int)lux);
   delay(500);
}
