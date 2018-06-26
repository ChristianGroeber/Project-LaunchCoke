#include <VarSpeedServo.h>

VarSpeedServo myservo;

void setup()
{
  myservo.attach(9, 0, 255);
}

void loop()
{
  myServo.slowmove (50, 255);
}
