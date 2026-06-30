#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 
#define DHTPIN 2 
#define DHTTYPE DHT11 
#define SOIL A0 
#define PUMP 7 
#define FAN 8 
DHT dht(DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() { 
pinMode(PUMP, OUTPUT); 
pinMode(FAN, OUTPUT); 
digitalWrite(PUMP, HIGH); 
digitalWrite(FAN, HIGH); 
lcd.begin(); 
lcd.backlight(); 
dht.begin(); 
} 
void loop() { 
int soil = analogRead(SOIL); 
float temp = dht.readTemperature(); 
float hum = dht.readHumidity(); 
lcd.setCursor(0,0); 
lcd.print("T:"); 
lcd.print(temp); 
lcd.print(" H:"); 
lcd.print(hum); 
lcd.setCursor(0,1); 
lcd.print("Soil:"); 
lcd.print(soil); 
// Soil condition 
if (soil > 800) { 
digitalWrite(PUMP, LOW); // ON 
} else { 
digitalWrite(PUMP, HIGH); // OFF 
} 
// Temperature condition 
if (temp > 30) { 
digitalWrite(FAN, LOW); // ON 
} else { 
digitalWrite(FAN, HIGH); // OFF 
} 
delay(2000); 
} 