int pinVal1 = 14;
int pinVal2 = 15;
int pinVal3 = 16;
int pinVal4 = 17;
int pinVal5 = 18;
int pinVal6 = 19;
int pinVal7 = 20;

int myPins[] = {pinVal1, pinVal2, pinVal3, pinVal4, pinVal5, pinVal6, pinVal7};

#include "pitches.h";
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int h1[] = {C1, D1, E1, F1, G1, A1, B1};
int h2[] = {C2, D2, E2, F2, G2, A2, B2};
int h3[] = {C3, D3, E3, F3, G3, A3, B3};
int h4[] = {C4, D4, E4, F4, G4, A4, B4};
int h5[] = {C5, D5, E5, F5, G5, A5, B5};
int h6[] = {C6, D6, E6, F6, G6, A6, B6};
int h7[] = {C7, D7, E7, F7, G7, A7, B7};

int tones[] = {h1, h2, h3, h4, h5, h6, h7};

void setup() {
  //  pinMode(pinVal1, INPUT);
  //  pinMode(pinVal2, INPUT);
  //  pinMode(pinVal3, INPUT);
  //  pinMode(pinVal4, INPUT);
  //  pinMode(pinVal5, INPUT);
  //  pinMode(pinVal6, INPUT);
  //  pinMode(pinVal7, INPUT);
  //  pinMode(A7, INPUT);
  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

int lastToneHeightPlayed = 0;
void loop() {
  if (lastToneHeightPlayed != getTone()) {
    lastToneHeightPlayed = getTone();
    lcd.clear();
    lcd.print("Tonhoehe: ");
    lcd.println(lastToneHeightPlayed);
  }
  int toneToPlay[] = {tones[getTone()]};
  Serial.println(getChanged());
  if (getChanged() != 0) {
    int playingTone = toneToPlay[getChanged() - 14];
    tone(8 /*DigitalPin*/, playingTone, 100);
  }
  delay(100);
}

int getTone() {
  int anRead = analogRead(21);
  if (anRead >= 0 && anRead <= 195) {
    return 0;
  } else if (anRead > 195 && anRead <= 330) {
    return 1;
  } else if (anRead > 330 && anRead <= 456) {
    return 2;
  } else if (anRead > 456 && anRead <= 600) {
    return 3;
  } else if (anRead > 600 && anRead <= 735) {
    return 4;
  } else if (anRead > 735 && anRead <= 870) {
    return 5;
  } else if (anRead > 870 && anRead <= 1100) {
    return 6;
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



