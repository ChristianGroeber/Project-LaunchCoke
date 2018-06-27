int pinVal1 = 14;
int pinVal2 = 15;
int pinVal3 = 16;
int pinVal4 = 17;
int pinVal5 = 18;
int pinVal6 = 19;
int pinVal7 = 20;

int myPins[] = {pinVal1, pinVal2, pinVal3, pinVal4, pinVal5, pinVal6, pinVal7};

#include "pitches.h";

//Kopiert von https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay________________
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//___________________________________________________________________________________


//Alle unterschiedlichen Tonhöhen mitsamt ihren Tönen
int h1[] = {C1, D1, E1, F1, G1, A1, B1};
int h2[] = {C2, D2, E2, F2, G2, A2, B2};
int h3[] = {C3, D3, E3, F3, G3, A3, B3};
int h4[] = {C4, D4, E4, F4, G4, A4, B4};
int h5[] = {C5, D5, E5, F5, G5, A5, B5};
int h6[] = {C6, D6, E6, F6, G6, A6, B6};
int h7[] = {C7, D7, E7, F7, G7, A7, B7};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

int lastToneHeightPlayed = 0;                   //die zuletzt gespielte Höhe
void loop() {
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
    switch (toneToPlay) {
      case 0:             //die tiefste Höhe
        switch (changed) {
          case 14:
            playSound(C1);
            break;
          case 15:
            playSound(D1);
            break;
          case 16:
            playSound(E1);
            break;
          case 17:
            playSound(F1);
            break;
          case 18:
            playSound(G1);
            break;
          case 19:
            playSound(A1);
            break;
          case 20:
            playSound(B1);
            break;
        }
        break;
      case 1:
        playSound(h2);
        break;
      case 2:
        switch (changed) {
          case 14:
            playSound(C2);
            break;
          case 15:
            playSound(D2);
            break;
          case 16:
            playSound(E2);
            break;
          case 17:
            playSound(F2);
            break;
          case 18:
            playSound(G2);
            break;
          case 19:
            playSound(A2);
            break;
          case 20:
            playSound(B2);
            break;
        }
        break;
      case 3:
        switch (changed) {
          case 14:
            playSound(C3);
            break;
          case 15:
            playSound(D3);
            break;
          case 16:
            playSound(E3);
            break;
          case 17:
            playSound(F3);
            break;
          case 18:
            playSound(G3);
            break;
          case 19:
            playSound(A3);
            break;
          case 20:
            playSound(B3);
            break;
        }
        break;
      case 4:
        switch (changed) {
          case 14:
            playSound(C4);
            break;
          case 15:
            playSound(D4);
            break;
          case 16:
            playSound(E4);
            break;
          case 17:
            playSound(F4);
            break;
          case 18:
            playSound(G4);
            break;
          case 19:
            playSound(A4);
            break;
          case 20:
            playSound(B4);
            break;
        }
        break;
      case 5:
        switch (changed) {
          case 14:
            playSound(C5);
            break;
          case 15:
            playSound(D5);
            break;
          case 16:
            playSound(E5);
            break;
          case 17:
            playSound(F5);
            break;
          case 18:
            playSound(G5);
            break;
          case 19:
            playSound(A5);
            break;
          case 20:
            playSound(B5);
            break;
        }
        break;
      case 6:            //die höchste Höhe
        switch (changed) {
          case 14:
            playSound(C6);
            break;
          case 15:
            playSound(D6);
            break;
          case 16:
            playSound(E6);
            break;
          case 17:
            playSound(F6);
            break;
          case 18:
            playSound(G6);
            break;
          case 19:
            playSound(A6);
            break;
          case 20:
            playSound(B6);
            break;
        }
        break;
    }
  }
}

void playSound(int toPlay) {                    //übergeben wird der zu spielende Ton
  tone(8 /*DigitalPin*/, toPlay, 100);          //das Spielen des Tones (auf DigitalPin 8)
  Serial.println(toPlay);                       //Debugging
}

int getTone() {                                 //Die zu spielende Tonhöhe wird mit dieser Methode ermittelt
  int anRead = analogRead(21);                  //das Resultat vom AnalogPin A7, Range: 0 - 1023
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
  for (int i = 0; i < sizeof(myPins); i++) {    //durch alle Pins durchiterieren
    if ((analogRead(myPins[i])) < 5) {          //Wenn die Dose an der Stelle i angefasst wurde (der Wert des dazugehörigen AnalogPins kleiner 5 ist)
      ret = myPins[i];                          //wird dieser Pin zurückgegeben
    }
  }
  if (ret < 0) {                                //Manchmal gibt einer der Pins einen negativen Wert zurück, dieser kann jedoch nicht ausgewertet werden
    ret = 0;                                    //also wird einfach 0 zurück gegeben
  } else if (ret > 25) {                        //Der Wert darf auch nicht grösser 25 sein, da es einen solchen Pin auch gar nicht gibt.
    ret = 0;                                    //also wird auch einfach 0 zurück gegeben
  }
  return ret;                                   //rückgabe des geänderten Pins
}



