int pinVal1 = A5;
int pinVal2 = A4;
int pinVal3 = A3;

void setup() {
  pinMode(pinVal1, INPUT);
  pinMode(pinVal2, INPUT);
  pinMode(pinVal3, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pressed = 0;
  //  if(analogRead(pinVal1) == 0){
  //    Serial.println("Dose 1");
  //    digitalWrite(2, LOW);
  //  }else if(analogRead(pinVal2) == 0){
  //    Serial.println("Dose 2");
  //    digitalWrite(2, LOW);
  //  }else if(analogRead(pinVal3) == 0){
  //    Serial.println("Dose 3");
  //    digitalWrite(2, LOW);
  //  }else{
  //    digitalWrite(2, HIGH);
  //  }

  Serial.print("1: ");
  Serial.println(analogRead(A5));
  Serial.print("2: ");
  Serial.println(analogRead(A4));
  Serial.print("3: ");
  Serial.println(analogRead(A3));
  delay(1000);
}
