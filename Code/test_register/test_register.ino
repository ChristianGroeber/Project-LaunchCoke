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

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  leds = 0;
  updateShiftRegister();
  digitalWrite(9, HIGH);
  for (int i = 0; i < 8; i++)
  {
    Serial.print("In");
    Serial.print(digitalRead(2));
    Serial.print(digitalRead(3));
    Serial.print(digitalRead(4));
    Serial.print(digitalRead(5));
    Serial.println(digitalRead(6));
    bitSet(leds, i);
    updateShiftRegister();
    delay(100);
    bitClear(leds, i);
    updateShiftRegister();

  }
  for (int y = 0; y < 8; y++)
  {
    Serial.print("Out");
    Serial.print(digitalRead(2));
    Serial.print(digitalRead(3));
    Serial.print(digitalRead(4));
    Serial.print(digitalRead(5));
    Serial.println(digitalRead(6));
    bitSet(leds, y);
    updateShiftRegisterBack();
    delay(100);
    bitClear(leds, y);
    updateShiftRegisterBack();
  }
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void updateShiftRegisterBack()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

