#include <ShiftOutX.h>
#include <ShiftPinNo.h>

int pinVal1 = 14;
int pinVal2 = 15;
int pinVal3 = 16;
int pinVal4 = 17;
int pinVal5 = 18;

int laserPin = 6;
int ledPin = 13;

//#include "pitches.h"
#include <Servo.h>
Servo myServo;

//Kopiert von https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay________________
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//___________________________________________________________________________________

int pin2Servo[] = {0, 45, 90, 135, 180};

void setup() {
  Serial.begin(9600);                           //für Testzwecke wird anstelle des LCD's der Serielle Monitor verwendet
  lcd.begin(16, 2);                             //Grösse des Display's festlegen
  myServo.attach(7);                            //den Servo anhängen
  pinMode(laserPin, OUTPUT);                    //der Laser Pin, auf digital Pin 6
  pinMode(ledPin, OUTPUT);                      //der LED Oin, auf digital Pin 13
}

int lastToneHeightPlayed = 0;                   //die zuletzt gespielte Höhe
void loop() {
  //    partyTime();                            //wird nicht verwendet, da LED's nicht in Verwendung
  if (lastToneHeightPlayed != getTone()) {      //Wenn die zuletzt gespielte Höhe sich von der neuen unterscheidet (Der Potentiometer gedreht wurde)
    lastToneHeightPlayed = getTone();           //Wird die Höhe angepasst.
    String toPrint = "Tonhoehe: ";
    toPrint += lastToneHeightPlayed;            //Was auf dem Bildschirm ausgegeben wird
    lcd.clear();                                //Den LCD clearen
    lcd.println(toPrint);                       //Auf dem Bildschirm ausgeben
    Serial.println("Lautsprecher");
    Serial.println(toPrint);                    //Auf dem Serial Monitor ausgeben
  }

  int toneToPlay = getTone();                   //Die zu spielende Tonhöhe
  int changed = getChanged();                   //Der zu spielende Ton
  if (changed != 0) {
    doDaDance(changed);                         //Den Servo drehen
    tone(10, spielen(changed, toneToPlay), 100); //Den Ton spielen
    digitalWrite(ledPin, HIGH);                 //die LED zum leuchten bringen
  }else{
    digitalWrite(ledPin, LOW);                  //die LED wieder aus schalten
  }
}


void doDaDance(int changed) {                   //1A namensgebung ;)
  digitalWrite(laserPin, HIGH);                 //den Laser an machen
  switch (changed) {                            //die angetippte Aluminium Folie
    case 18:
      myServo.write(0);
      break;
    case 17:
      myServo.write(45);
      break;
    case 16:
      myServo.write(90);
      break;
    case 15:
      myServo.write(135);
      break;
    case 14:
      myServo.write(180);
      break;
  }
}


shiftOutX party(8, 11, 12, MSBFIRST, 4);        //Der Teil des Programmes, das die LED's an der Vorderseite zum leuchten bringen sollte.
void partyTime() {
  party.pinOn(shPin1);                          //Der erste Pin des Shift Register's wird auf HIGH geschaltet
  delay(1000);                                  //1 Sekunde warten
  party.pinOff(shPin1);                         //Den vorherigen Pin wieder LOW schalten
  delay(1000);                                  //1 Sekunde warten
  party.pinOn(shPin2);                          //Pin 2 des Shift Register's HIGH nehmen
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
        case 15:
          return (73);
        case 16:
          return (82);
        case 17:
          return (87);
        case 18:
          return (98);
      }
      break;
    case 3:
      switch (changed) {
        case 14:
          return (131);
        case 15:
          return (147);
        case 16:
          return (156);
        case 17:
          return (175);
        case 18:
          return (196);
      }
      break;
    case 4:
      switch (changed) {
        case 14:
          return (262);
        case 15:
          return (294);
        case 16:
          return (330);
        case 17:
          return (349);
        case 18:
          return (392);
      }
      break;
    case 5:
      switch (changed) {
        case 14:
          return (523);
        case 15:
          return (587);
        case 16:
          return (659);
        case 17:
          return (698);
        case 18:
          return (784);
      }
      break;
    case 6:            //die höchste Höhe
      switch (changed) {
        case 14:
          return (1047);
        case 15:
          return (1175);
        case 16:
          return (1319);
        case 17:
          return (1397);
        case 18:
          return (1568);
      }
  }
}




