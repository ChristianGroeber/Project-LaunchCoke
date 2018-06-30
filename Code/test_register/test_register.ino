#include <ShiftOutX.h>
#include <ShiftPinNo.h>

//**************************************************************//
//  Name    : shiftOutX, Hello World
//  Author  : Juan Hernandez
//  Date    : 02 Jan 2011
//  Modified:
//  Version : 1.0
//  Notes   : Code for using four 74HC595 Shift Registers           //
//          : with shiftOutX class
//****************************************************************

//_latchPin connected to ST_CP of 74HC595
//_dataPin connected to DS of 74HC595
//_clockPin connected to SH_CP of 74HC595
//_bitOrder is the order in which the bits are send to the register
//values are the constants MSBFIRST for most significant bits first
//or LSBFIRST for least significant bit first, the way I see it is
//do you want Q0 to be shPin1 or do you want Q7 to be shPin1,
//Q0 and Q7 are pin on the 74HC595 shift register.
//number of registers is how many registers you have in series
//so if you have 2 you will shift 16 bits or 24 and 32 if you
//have 3 or 4 registers
//this is how you input the parameters to the class constructor
//shiftOutX(_latchPin, _dataPin, _clockPin, _bitOrder, _NofRegisters);
shiftOutX regOne(8, 11, 12, MSBFIRST, 4);

//_bitString is the class member that holds the string of ones and zeros
//it is just a 4 byte unsigned integer and though all these members are
//public I just use the functions to modify them but you can modify them
//as you like.
//so to access it you would do it like this
//regOne._bitString = xx;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  int delayT = 1;
  regOne.pinOn(shPin1);
  printLinie();
  delay(delayT);
  regOne.pinOff(shPin1);
  printLinie();
  delay(delayT);
  regOne.pinOn(shPin3);
  printLinie();
  delay(delayT);
  regOne.pinOff(shPin3);
  printLinie();
  delay(delayT);
}

void printLinie() {
//  Serial.print("2:");
//  Serial.print(digitalRead(2));
//  Serial.print(" ");
//  Serial.print("3:");
//  Serial.println(digitalRead(3));

  if(digitalRead(2) == 1){
    Serial.println("2");
  }else if(digitalRead(3) == 1){
    Serial.println("3");
  }
}

