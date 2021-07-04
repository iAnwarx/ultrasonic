#include <Servo.h>
#define maxdistance 100
#include<SoftwareSerial.h>

Servo srv1;
Servo srv2;
Servo srv3;

void setup()
{
 Serial.begin(9600);
 pinMode(9, OUTPUT);
 pinMode(8, INPUT);
  
 srv1.attach(4);
 srv1.attach(4);
 srv1.attach(4);
}
  
void loop()
{
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);
  
 int d=pulseIn(8,LOW);
  d=d/29/2;
  Serial.println(d);
  
  if (d<maxdistance)
  {
    srv1.write(90);
    srv2.write(90);
    srv3.write(90);
    delay(1000);
  }
  else
  {
    delay(1000);
    srv1.write(0);
    srv2.write(0);
    srv3.write(0);
  }
}
