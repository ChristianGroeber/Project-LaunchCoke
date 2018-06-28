#include <Servo.h>
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(7);
  Serial.begin(9600);
}

int initialPosition = 0;
int toAdd;

void loop() {
  // put your main code here, to run repeatedly:
//  if(initialPosition == 180){
//    toAdd = -20;
//  }else if(initialPosition == 0){
//    toAdd = 20;
//  }
  initialPosition = initialPosition + toAdd;
  myServo.write(initialPosition);
  Serial.println(initialPosition);
  delay(100);
}
