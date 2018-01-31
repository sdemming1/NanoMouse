#include <Servo.h>
#include "NanoMouseMotors.h"
#include "NanoMouseSensors.h"

const byte ledPin = 13;
const byte buttonPin = 9;

NanoMouseMotors motors;

//<left Emitter,left Detector,front Emitter, front Detector, right Emitter, right Detector>
NanoMouseSensors<4,A7,3,A6,2,A5> sensors;

//Main
void setup() 
{
  motors.attach(6,5);
  
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);

  sensors.configure();
  Serial.begin(9600);
  
  while(digitalRead(buttonPin))
  {
  }
}

void loop() 
{
  sensors.sense();
  sensors.view();
  //delay(100);
}
