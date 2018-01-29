#include <Servo.h>
#include "NanoMouseMotors.h"

const byte ledPin = 13;
const byte buttonPin = 9;


NanoMouseMotors motors;

//Main
void setup() 
{
  motors.attach(6,5);
  
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);

  while(digitalRead(buttonPin))
  {
  }
  
  motors.square(RIGHT,2);
}

void loop() 
{

  digitalWrite(ledPin,HIGH);
  
}
