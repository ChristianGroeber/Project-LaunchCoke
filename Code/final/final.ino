#include <ShiftOutX.h>
#include <ShiftPinNo.h>

int pinVal1 = 14;
int pinVal2 = 15;
int pinVal3 = 16;
int pinVal4 = 17;
int pinVal5 = 18;

int laserPin = 6;

/**
   Can probably be deleted
  int myPins[] = {pinVal1, pinVal2, pinVal3, pinVal4, pinVal5};
**/

//#include "pitches.h"
#include <Servo.h>
Servo myServo;

//Kopiert von https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay________________
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//___________________________________________________________________________________

int pin2Servo[] = {0, 45, 90, 135, 180};


/**
   Can probably be deleted
  //Alle unterschiedlichen Tonhöhen mitsamt ihren Tönen
  int h1[] = {C1, D1, E1, F1, G1, A1, B1};
  int h2[] = {C2, D2, E2, F2, G2, A2, B2};
  int h3[] = {C3, D3, E3, F3, G3, A3, B3};
  int h4[] = {C4, D4, E4, F4, G4, A4, B4};
  int h5[] = {C5, D5, E5, F5, G5, A5, B5};
  int h6[] = {C6, D6, E6, F6, G6, A6, B6};
  int h7[] = {C7, D7, E7, F7, G7, A7, B7};
**/

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  myServo.attach(7);
  pinMode(laserPin, OUTPUT);
}

int lastToneHeightPlayed = 0;                   //die zuletzt gespielte Höhe
void loop() {
    partyTime();
    delay(100);
  if (lastToneHeightPlayed != getTone()) {      //Wenn die zuletzt gespielte Höhe sich von der neuen unterscheidet (Der Potentiometer gedreht wurde)
    lastToneHeightPlayed = getTone();           //Wird die Höhe angepasst.
    String toPrint = "Tonhoehe: ";
    toPrint += lastToneHeightPlayed;            //Was auf dem Bildschirm ausgegeben wird
    lcd.clear();   //Den LCD clearen
    lcd.println(toPrint);                       //Auf dem Bildschirm ausgeben
    Serial.println(toPrint);                    //Auf dem Serial Monitor ausgeben
  }
  int toneToPlay = getTone();                   //Die zu spielende Tonhöhe
  int changed = getChanged();                   //Der zu spielende Ton
  delay(10);
  if (changed != 0) {
    doDaDance(changed);
    tone(5, spielen(changed, toneToPlay), 100);
  }
}


void doDaDance(int changed) {
  digitalWrite(laserPin, HIGH);
  switch (changed) {
    case 14:
      myServo.write(0);
      break;
    case 15:
      myServo.write(45);
      break;
    case 16:
      myServo.write(90);
      break;
    case 17:
      myServo.write(135);
      break;
      myServo.write(180);
      break;
  }
}

shiftOutX party(8, 11, 12, MSBFIRST, 4);
void partyTime() {
  party.pinOn(shPin1);
  delay(1000);
  party.pinOff(shPin1);
  delay(1000);
  party.pinOn(shPin2);
}

int getTone() {                                 //Die zu spielende Tonhöhe wird mit dieser Methode ermittelt
  int anRead = analogRead(19);                  //das Resultat vom AnalogPin A7, Range: 0 - 1023
  if (anRead >= 0 && anRead <= 195) {           //Wenn der Wert zwischen 0 und 195 liegt
    return 0;                                   //Wird die 0. Tonleiter gespielt
  } else if (anRead > 195 && anRead <= 330) {   //Wenn der Wert zwischen 195 und 330 liegt
    return 1;                                   //Wird die 1. Tonleiter abgespielt
  } else if (anRead > 330 && anRead <= 456) {   //und so weiter und so fort
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

int getChanged() {                              //diese Methode ermittelt die angefasste Dose
  //get smallest number
  int ret = 0;                                  //der Wert, der am Ende zurückgegeben wird. Standardmässig ist dieser 0
  if ((analogRead(14)) < 10) {
    ret = 14;
  } else if ((analogRead(15)) < 10) {
    ret = 15;
  } else if ((analogRead(16)) < 10) {
    ret = 16;
  } else if ((analogRead(17)) < 10) {
    ret = 17;
  } else if ((analogRead(18)) < 10) {
    ret = 18;
  }
  if (ret < 0) {                                //Manchmal gibt einer der Pins einen negativen Wert zurück, dieser kann jedoch nicht ausgewertet werden
    ret = 0;                                    //also wird einfach 0 zurück gegeben
  } else if (ret > 25) {                        //Der Wert darf auch nicht grösser 25 sein, da es einen solchen Pin auch gar nicht gibt.
    ret = 0;                                    //also wird auch einfach 0 zurück gegeben
  }
  return ret;                                   //rückgabe des geänderten Pins
}

int spielen(int changed, int toneToPlay) {
  switch (toneToPlay) {
    case 0:             //die tiefste Höhe
      switch (changed) {
        case 14:
          return (33);
          break;
        case 15:
          return (37);
          break;
        case 16:
          return (41);
          break;
        case 17:
          return (44);
          break;
        case 18:
          return (49);
          break;
          //          case 19:
          //            return(55);
          //            break;
          //          case 20:
          //            return(62);
          //            break;
      }
      break;
    case 1:
      break;
    case 2:
      switch (changed) {
        case 14:
          return (65);
          break;
        case 15:
          return (73);
          break;
        case 16:
          return (82);
          break;
        case 17:
          return (87);
          break;
        case 18:
          return (98);
          break;
          //          case 19:
          //            return(A2);
          //            break;
          //          case 20:
          //            return(B2);
          //            break;
      }
      break;
    case 3:
      switch (changed) {
        case 14:
          return (131);
          break;
        case 15:
          return (147);
          break;
        case 16:
          return (156);
          break;
        case 17:
          return (175);
          break;
        case 18:
          return (196);
          break;
          //          case 19:
          //            return(A3);
          //            break;
          //          case 20:
          //            return(B3);
          //            break;
      }
      break;
    case 4:
      switch (changed) {
        case 14:
          return (262);
          break;
        case 15:
          return (294);
          break;
        case 16:
          return (330);
          break;
        case 17:
          return (349);
          break;
        case 18:
          return (392);
          break;
          //          case 19:
          //            return(A4);
          //            break;
          //          case 20:
          //            return(B4);
          //            break;
      }
      break;
    case 5:
      switch (changed) {
        case 14:
          return (523);
          break;
        case 15:
          return (587);
          break;
        case 16:
          return (659);
          break;
        case 17:
          return (698);
          break;
        case 18:
          return (784);
          break;
          //          case 19:
          //            return(A5);
          //            break;
          //          case 20:
          //            return(B5);
          //            break;
      }
      break;
    case 6:            //die höchste Höhe
      switch (changed) {
        case 14:
          return (1047);
          break;
        case 15:
          return (1175);
          break;
        case 16:
          return (1319);
          break;
        case 17:
          return (1397);
          break;
        case 18:
          return (1568);
          break;
          //          case 19:
          //            return(A6);
          //            break;
          //          case 20:
          //            return(B6);
          //            break;
      }
  }
}




