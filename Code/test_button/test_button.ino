int buttonPin = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  Serial.begin(9600);
}

int counter = 0;
boolean wasHigh = false;
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8) == 1 && !wasHigh){
    counter++;
    wasHigh = false;
  }else if(digitalRead(8) == 0 && wasHigh){
    counter++;
    wasHigh = true;
  }
  if(counter % 2 == 1){
    Serial.println("not playing");
  }else{
    Serial.println("playing");
  }
//Serial.println(digitalRead(8));
//delay(1000);
}
