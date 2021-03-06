/*modified by Tania Winters 18/02/2021
created extra lcd.print lines to add more text
this program is to check the temperature and display with print lines.
giving you a coloured screen that can be changed
was set at a pink display screen,
I modified it from colorR = 250, colorG = 0 modified to 250, colorB = 250
gave it a blue screen by cahnging the middle, The relay is to control external fan heater, which is set at D7.*/
#include <Wire.h>
#include "rgb_lcd.h"
#include <math.h>
const int B = 4275; // B value of the thermistor
const int R0 = 100000; // R0 = 100k
const int pinTempSensor = A0; // Grove - Temperature Sensor connect to A0

int reading = 0;
int relay =7;



rgb_lcd lcd;

const int colorR = 250;
const int colorG = 250;
const int colorB = 250;

void setup()
{
  // set up the LCD's number of columns and rows:
 // set up the LCD's number of columns and rows:
lcd.begin(16, 2);
lcd.setRGB(colorR, colorG, colorB);
// Print a message to the LCD.
lcd.print(" Welcome");
delay(1500);

 lcd.begin(16, 2);
lcd.setRGB(colorR, colorG, colorB);
lcd.print(" Lamcubator ");
delay(1500);
}

void loop()
{
  Serial.begin(9600);
  pinMode(relay,OUTPUT);

 int a = analogRead(pinTempSensor);
  float R = 1023.0/a-1.0;
  R = R0*R;
  
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
 
  
  
 

  //lcd.print(temperature, DEC);
  //lcd.setCursor(0,0);

  
 if (temperature <= 26)
{
 
  digitalWrite(7, HIGH);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(" ON ");
  lcd.print("Temp: ");
  lcd.setCursor(0,5);
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  
 
 
}
else if (temperature > 26)
{
digitalWrite(7, LOW);
lcd.print(" OFF");
}
delay(1500);
 
  
}
