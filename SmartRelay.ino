/*
SmartSwitch Sample Code
Written by Dominick Lee <dominick@lifebeam.net>
Distributed until the GPL v2 License for free use.
Last modified 2/24/15.
*/

#include <CapacitiveSensor.h>
CapacitiveSensor   cs_6_5 = CapacitiveSensor(6,5); 

int relay = 3;
int led = 12;
boolean stat = false;
long totalMS = 0;

long time = 60; // SPECIFY TIME (in minutes) for auto-off

void setup()                    
{
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  totalMS = time * 3600 * 1000;
}

void loop()
{
  long total1 =  cs_6_5.capacitiveSensor(30);
  
  if (total1 > 80) {
    stat = !stat;
    digitalWrite(relay, stat);
    digitalWrite(led, stat);
    delay(2000);
  }
  
  if (millis() % totalMS == 0) {
    digitalWrite(relay, LOW);
    digitalWrite(led, LOW);
    delay(2000);
  }
}
