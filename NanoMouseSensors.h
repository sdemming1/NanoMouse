#include <Arduino.h>

template <byte frontEmitter, byte frontDetector>

class NanoMouseSensors
{

  public:

  void configure()
  {
    pinMode(frontEmitter,OUTPUT);


    digitalWrite(frontEmitter,HIGH);
    
  }
  
  void view()
  {
    Serial.println(analogRead(frontDetector));
  }

};

