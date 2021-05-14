#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// 設定 LCD I2C 位址

LiquidCrystal_I2C lcd(0x27, 16, 2);
int sen1=11;
int sen2=12;
unsigned long t1=0;
unsigned long t2=0;
float velocity;
void setup()
{
   lcd.begin(16, 2);
   pinMode(sen1,INPUT);
   pinMode(sen2,INPUT);
   //lcd.backlight(); // 開啟背光
   delay(250);
   Serial.begin(9600);
   lcd.setCursor(0,0);
   lcd.print(" Speed Detector ");
}

void loop()
{
   while(digitalRead(sen1));
   while(digitalRead(sen1)==0);
   t1=millis();
   while(digitalRead(sen2));
   t2=millis();
   float velotime=t2-t1;
   //velocity=velocity/1000;//convert millisecond to second
   //velocity=velocity*3600;//multiply by seconds per hr
   //velocity=velocity/1000;//division by meters per Km
   //velocity=54000.0/velotime;//v=d/t,distance=15cm
   velocity=64800.0/velotime;//distance=18cm
   if (velotime!=0){
     lcd.backlight(); // 開啟背光
     
   for(int i=3;i>0;i--)
   {
   lcd.setCursor(3,1);
   lcd.print(velocity);
   lcd.print(" Km/hr   ");
   delay(1000);
   lcd.setCursor(3,1);
   lcd.print("         ");
   delay(500);
   //
   //delay(250);
   }lcd.noBacklight();
   }else{
    lcd.noBacklight(); // 關閉背光
   }
  
   
}
