int pinVal1 = A5;
int pinVal2 = A4;
int pinVal3 = A3;
int pinVal4 = A2;
int pinVal5 = A1;

int myPins[] = {pinVal1, pinVal2, pinVal3, pinVal4, pinVal5};

#include "pitches.h";

int h1[] = {C1, D1, E1, F1, G1};
int h2[] = {C2, D2, E2, F2, G2};
int h3[] = {C3, D3, E3, F3, G3};
int h4[] = {C4, D4, E4, F4, G4};
int h5[] = {C5, D5, E5, F5, G5};
int h6[] = {C6, D6, E6, F6, G6};
int h7[] = {C7, D7, E7, F7, G7};

void setup() {
  pinMode(pinVal1, INPUT);
  pinMode(pinVal2, INPUT);
  pinMode(pinVal3, INPUT);
  pinMode(pinVal4, INPUT);
  pinMode(pinVal5, INPUT);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Playing: ");
  Serial.println(getTone());
  delay(100);
}

int getTone() {
  int anRead = analogRead(A0);
  if (anRead >= 60 && anRead <= 195) {
    return 1;
  } else if (anRead > 195 && anRead <= 330) {
    return 2;
  } else if (anRead > 330 && anRead <= 456) {
    return 3;
  } else if (anRead > 456 && anRead <= 600) {
    return 4;
  } else if (anRead > 600 && anRead <= 735) {
    return 5;
  } else if (anRead > 735 && anRead <= 870) {
    return 6;
  } else if (anRead > 870 && anRead <= 1020) {
    return 7;
  }
}

int getChanged() {
  //get smallest number
  int smallestNumber = 100;
  for (int i = 0; i < sizeof(myPins); i++) {
    if ((analogRead(myPins[i]) / 2) < analogRead(smallestNumber)) {
      smallestNumber = myPins[i];
    }
  }
  if (smallestNumber >= 100) {
    return 0;
  } else if (smallestNumber <= -20) {
    return 0;
  } else {
    return smallestNumber;
  }
}



