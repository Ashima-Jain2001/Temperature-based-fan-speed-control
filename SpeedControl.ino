// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 10, 5, 4, 3, 2);

int val;
float TEMP;
int led4=6;//connect LED6 to Pin #pwm pin
int fan_speed=0;


void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(led4, OUTPUT);
  
  analogWrite(led4, fan_speed);//pwm
  lcd.clear();
  fan_speed=0;
  analogWrite(led4, fan_speed);delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Temp Based");
  lcd.setCursor(0,1);
  lcd.print("Fan Control");
  delay(3000);
  lcd.clear();
}
void loop()
{
  val=analogRead(0);
  float T=(val/1024.0)*5000;
  float TEMP=T/10;
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.setCursor(3,0);
  lcd.print(TEMP);
  delay(500);
  delay(1000);
  
  
  if (TEMP>0 && TEMP<20)
  {
    fan_speed=0; analogWrite(led4, fan_speed);
    lcd.setCursor(0,1);
    lcd.print("Fan Stopped");
    delay(3000);
  	lcd.clear();
    
  }
  
  if (TEMP>20 && TEMP<25)
  {
    fan_speed=80; analogWrite(led4, fan_speed);
    lcd.setCursor(0,1);
    lcd.print("Speed Low");
    delay(3000);
  	lcd.clear();
    
  }
  if (TEMP>25 && TEMP<30)
  {
    fan_speed=120;
    analogWrite(led4, fan_speed);
    lcd.setCursor(0,1);
    lcd.print("Speed Medium");
    delay(3000);
  	lcd.clear();
  }
  if (TEMP>30 && TEMP<40)
  {
    fan_speed=160;
    analogWrite(led4, fan_speed);
    lcd.setCursor(0,1);
    lcd.print("Speed High");
    delay(3000);
  	lcd.clear();
  }
  if (TEMP>40 && TEMP<120)
  {
    fan_speed=250;
    analogWrite(led4, fan_speed);
    lcd.setCursor(0,1);
    lcd.print("Speed Very High");
    delay(3000);
  	lcd.clear();
  }
  
}
  
  
  
