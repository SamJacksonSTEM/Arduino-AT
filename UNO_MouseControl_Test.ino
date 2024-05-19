int d7 =7;
int d8 =8;
int X = 0;
int Y = 0;

void setup() {
 pinMode(d7,INPUT_PULLUP);
 pinMode(d8,INPUT_PULLUP);
 
Serial.begin(9600);
}

void loop() {
  X = (X+1)%1000+1;
  Y = (Y+2)%1000+1;
  int x = map(X, 1, 1023, 1917, 2);
  int y = map(Y, 1, 1023, 2, 1077);
  

if(digitalRead(d8)==LOW){
Serial.print("c");

}else{
  Serial.print("z");
}
Serial.print(" ");
Serial.print(x);
Serial.print(" ");
Serial.print(y);
Serial.print(" ");
Serial.println("m");
delay(180);
}
