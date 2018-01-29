#include <Arduino.h>

template <byte leftEmitter, byte leftDetector, byte frontEmitter, byte frontDetector, byte rightEmitter, byte rightDetector>

class NanoMouseSensors
{
private:
//Used to filter out ambient light from the front detector
int frontAmbient; //Emitters off
int frontCombined; //Emitters on
int frontReflected; //Emitters on - Emitters off

//Used to filter out ambient light from the left detector
int leftAmbient; //Emitters off
int leftCombined; //Emitters on
int leftReflected; //Emitters on - Emitters off

//Used to filter out ambient light from the right detector
int rightAmbient; //Emitters off
int rightCombined; //Emitters on
int rightReflected; //Emitters on - Emitters off

public:
    void configure()
    {
      pinMode(leftEmitter, OUTPUT);
      pinMode(frontEmitter, OUTPUT);
      pinMode(rightEmitter, OUTPUT);

    }

    void sense()
    {
      digitalWrite(frontEmitter, HIGH);
      delay(1);
      frontCombined = analogRead(frontDetector);
      digitalWrite(frontEmitter, LOW);
      delay(1);
      frontAmbient = analogRead(frontDetector);
      frontReflected = frontCombined - frontAmbient;

      digitalWrite(leftEmitter, HIGH);
      delay(1);
      leftCombined = analogRead(leftDetector);
      digitalWrite(leftEmitter,LOW);
      delay(1);
      leftAmbient = analogRead(leftDetector);
      leftReflected = leftCombined - leftAmbient;

      digitalWrite(rightEmitter, HIGH);
      delay(1);
      rightCombined = analogRead(rightDetector);
      digitalWrite(rightEmitter,LOW);
      delay(1);
      rightAmbient = analogRead(rightDetector);
      rightReflected = rightCombined - rightAmbient;
      
    }


    void view()
    {
      Serial.print(leftReflected);
      Serial.print("\t");
      Serial.print(frontReflected);
      Serial.print("\t");
      Serial.println(rightReflected);
    }
};

