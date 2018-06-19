int pinVal1 = A5;
int pinVal2 = A4;
int pinVal3 = A3;

int myPins[] = {pinVal1, pinVal2, pinVal3};

void setup() {
  pinMode(pinVal1, INPUT);
  pinMode(pinVal2, INPUT);
  pinMode(pinVal3, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(getChanged());
  delay(100);
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
  } else {
    return smallestNumber;
  }
}

