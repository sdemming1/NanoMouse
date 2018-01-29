#include <Arduino.h>
#include <Servo.h>

#define RIGHT 1
#define LEFT -1

class NanoMouseMotors
{
private:
    Servo leftServo;
    Servo rightServo;

    static const byte power = 250;
    static const byte ii = 1;

public:

    void attach(byte leftMotor,byte rightMotor)
    {

        leftServo.attach(leftMotor);
        rightServo.attach(rightMotor);
      
    }
    void stop(int StopTime)
    {

      leftServo.writeMicroseconds(1500);
      rightServo.writeMicroseconds(1500);
      delay(StopTime);

    }

    void forwardTime(unsigned int time)
    {

      leftServo.writeMicroseconds(1500 - power);
      rightServo.writeMicroseconds(1500 + power);
      delay(time);
      stop(200);

    }

    void turn(int direction, int degrees)
    {

      leftServo.writeMicroseconds(1500 - power * direction);
      rightServo.writeMicroseconds(1500 - power * direction);
      delay(degrees * 5.9);
      stop(200);
    }

    void square(int direction, int size)
    //Size is a single integer that is multiplied by 1000
    {

      for (int ii = 1; ii < 5; ii++)
      {
        forwardTime(size * 1000);
        turn(direction, 90);
        delay(200);
        ii++;
      }

    }

}; //Semicolon for classes


