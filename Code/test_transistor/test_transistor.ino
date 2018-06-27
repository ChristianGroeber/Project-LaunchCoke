int myPins[] = {14, 15, 16, 17, 18, 19, 20};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(getChanged() != 0){
    Serial.println(getChanged());
  }
  delay(100);
}

int getChanged(){
  int ret = 0;
  for (int i = 0; i < sizeof(myPins); i++) {
    if ((analogRead(myPins[i])) < 10) {
      ret = myPins[i];
    }
  }
  if(ret < 0){
    ret = 0;
  }else if(ret > 25){
    ret = 0;
  }
  return ret;
}

