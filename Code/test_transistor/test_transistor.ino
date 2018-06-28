int myPins[7] = {14, 15, 16, 17, 18, 19, 20};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int changed = getChanged();
  if(changed != 0){
    Serial.println(changed);
  }
  for(int i = 0; i < 7; i++){
    Serial.print(i);
    Serial.print(": ");
    Serial.println(analogRead(myPins[i]));
  }
  delay(1000);
}

int getChanged(){
  int ret = 0;
//  for (int i = 0; i < sizeof(myPins); i++) {
//    if ((analogRead(myPins[i])) < 10) {
//      ret = myPins[i];
//    }
//  }
  if((analogRead(14)) < 10){
    ret = 14;
  }else if((analogRead(15)) < 10){
    ret = 15;
  }else if((analogRead(16)) < 10){
    ret = 10;
  }else if((analogRead(17)) < 10){
    ret = 17;
  }else if((analogRead(18)) < 10){
    ret = 18;
  }
  if(ret < 0){
    ret = 0;
  }else if(ret > 25){
    ret = 0;
  }
  return ret;
}

