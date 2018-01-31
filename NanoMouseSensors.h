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


//Smoothing Variables
int frontTotal;
int leftTotal;
int rightTotal;

static const byte numReadings = 20;
byte index;

int frontReadings[numReadings];
int leftReadings[numReadings];
int rightReadings[numReadings];

int frontSmoothed;
int leftSmoothed;
int rightSmoothed;

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


      //-= means frontTotal - frontReadings[index]
      frontTotal -= frontReadings[index];
      leftTotal -= leftReadings[index];
      rightTotal -= rightReadings[index];
      
      frontReadings[index] = frontReflected;
      leftReadings[index] = leftReflected;
      rightReadings[index] = rightReflected;
      
      frontTotal += frontReadings[index];
      leftTotal += leftReadings[index];
      rightTotal += rightReadings[index];

      index++;
      
      if(index >=numReadings)
        {

          index = 0;
          
        }
        
      frontSmoothed = frontTotal/numReadings;
      leftSmoothed = leftTotal/numReadings;
      rightSmoothed = rightTotal/numReadings;
    }

    void view()
    {
      Serial.print(leftSmoothed);
      Serial.print("\t");
      Serial.print(frontSmoothed);
      Serial.print("\t");
      Serial.println(rightSmoothed);
    }
};

