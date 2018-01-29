#include <Servo.h>
#include "NanoMouseMotors.h"
#include "NanoMouseSensors.h"

const byte ledPin = 13;
const byte buttonPin = 9;


NanoMouseMotors motors;

//<3,A6> is the front emitter and front detector
NanoMouseSensors<3,A6> sensors; //A6 is passed as front detector

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
  
  //motors.square(RIGHT,2);
}

void loop() 
{

  //digitalWrite(ledPin,HIGH);
  sensors.view();
  delay(100);
}
