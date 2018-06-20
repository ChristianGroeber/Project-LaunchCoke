int pinVal1 = A5;
int pinVal2 = A1;
int pinVal3 = A2;
int pinVal4 = A3;
int pinVal5 = A4;

int myPins[] = {pinVal1, pinVal2, pinVal3, pinVal4, pinVal5};

void setup() {
  pinMode(pinVal1, INPUT);
  pinMode(pinVal2, INPUT);
  pinMode(pinVal3, INPUT);
  pinMode(pinVal4, INPUT);
  pinMode(pinVal5, INPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 5; i++){
    Serial.print(i + 1);
    Serial.print(".: ");
    Serial.println(analogRead(myPins[i]));
  }
  delay(1000);
}
