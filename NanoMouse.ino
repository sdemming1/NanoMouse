#include <Servo.h>
#include "NanoMouseMotors.h"
#include "NanoMouseSensors.h"

const byte ledPin = 13;
const byte buttonPin = 9;

NanoMouseMotors motors;
NanoMouseSensors sensors;

//Main
void setup() 
{
 // motors.attach(6,5);
  
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);

//Emitters: 4=left,3=front,2=right
  sensors.configure(4,3,2);
  Serial.begin(9600);
  
  while(digitalRead(buttonPin))
  {
  }
}

void loop() 
{
  //Detectors: A7=left,A6=front,A5=right
  sensors.view(A7,A6,A5);
  delay(100);

}








