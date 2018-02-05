#include <Arduino.h>

class NanoMouseSensors
{
    public:

    void configure(byte leftEmitter, byte frontEmitter,byte rightEmitter)
    {
      pinMode(leftEmitter,OUTPUT);
      pinMode(frontEmitter,OUTPUT);
      pinMode(rightEmitter,OUTPUT);

      digitalWrite(leftEmitter,HIGH);
      digitalWrite(frontEmitter,HIGH);
      digitalWrite(rightEmitter,HIGH);
    }

    void view(byte leftDetector,byte frontDetector,byte rightDetector)
    {
      Serial.print(analogRead(leftDetector));
      Serial.print("\t");
      Serial.print(analogRead(frontDetector));
      Serial.print("\t");
      Serial.println(analogRead(rightDetector));
    }
};

