#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define RightMotorSpeed D5 
#define RightMotorDir D6 
#define LeftMotorSpeed D7 
#define LeftMotorDir D8 
char auth[] = "kHkmjS-83JED4I5ocR5fDbs5WuWqzbKP"; 
char ssid[] = "1234"; 
char pass[] = "12345678"; 
int minRange = 312;
int maxRange = 712;
int minspeed = 75;
int maxspeed = 150;
int nospeed = 0;
void moveControl(int x, int y)
{
//Move Forward
 if(y >= maxRange && x >= minRange && x<= maxRange)
 {
 digitalWrite( RightMotorDir,HIGH);
 digitalWrite(LeftMotorDir,HIGH);
 analogWrite(RightMotorSpeed, maxspeed);
 analogWrite(LeftMotorSpeed , maxspeed);
 }
//Move Forward Right
 else if(x <= maxRange && y >= maxRange)
 {
 digitalWrite( RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir,HIGH);
 analogWrite(RightMotorSpeed,minspeed);
 analogWrite(LeftMotorSpeed ,maxspeed);
 }
//Move Forward Left
 else if(x >= minRange && y >= maxRange)
 {
 digitalWrite( RightMotorDir,HIGH);
 digitalWrite(LeftMotorDir,HIGH);
 analogWrite(RightMotorSpeed,maxspeed);
 analogWrite(LeftMotorSpeed ,minspeed);
 }
//No Move
 else if(y < maxRange && y > minRange && x < maxRange && x > 
minRange)
 {
 analogWrite(RightMotorSpeed,nospeed);
 analogWrite(LeftMotorSpeed , nospeed);
 }
//Move Backward
 else if(y <= minRange && x >= minRange && x <= maxRange)
 {
 digitalWrite( RightMotorDir,LOW);
 digitalWrite(LeftMotorDir,LOW);
 analogWrite(RightMotorSpeed,maxspeed);
 analogWrite(LeftMotorSpeed ,maxspeed);
 }
//Move Backward Right
 else if(y <= minRange && x >= minRange)
 {
 digitalWrite( RightMotorDir,LOW);
 digitalWrite(LeftMotorDir,LOW);
 analogWrite(RightMotorSpeed,minspeed);
 analogWrite(LeftMotorSpeed ,maxspeed);
 }
//Move Backward Left
 else if(y <= minRange && x <= maxRange)
 {
 digitalWrite( RightMotorDir,LOW);
 digitalWrite(LeftMotorDir,LOW);
 analogWrite(RightMotorSpeed,maxspeed);
 analogWrite(LeftMotorSpeed ,minspeed);
 }
//Move Right
 else if(x >= maxRange && y >= minRange && y<= maxRange)
 {
 digitalWrite( RightMotorDir,HIGH);
 digitalWrite(LeftMotorDir,LOW);
 analogWrite(RightMotorSpeed, maxspeed);
 analogWrite(LeftMotorSpeed , minspeed);
 }
//Move Left
 else if(x <= minRange && y >= minRange && y <= maxRange)
 {
 digitalWrite( RightMotorDir,LOW);
 digitalWrite(LeftMotorDir,HIGH);
 analogWrite(RightMotorSpeed,minspeed);
 analogWrite(LeftMotorSpeed ,maxspeed);
 }
}
void setup()
{
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 pinMode(RightMotorSpeed, OUTPUT);
 pinMode(LeftMotorSpeed , OUTPUT);
 pinMode( RightMotorDir, OUTPUT);
 pinMode(LeftMotorDir, OUTPUT);
 digitalWrite(RightMotorSpeed, LOW);
 digitalWrite(LeftMotorSpeed , LOW);
 digitalWrite( RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, HIGH);
}
void loop()
{
 Blynk.run();
}
BLYNK_WRITE(V1)
{
 int x = param[0].asInt();
 int y = param[1].asInt();
 moveControl(x,y);
}