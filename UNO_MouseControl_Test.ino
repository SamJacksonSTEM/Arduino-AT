#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_10DOF.h>

/* Assign a unique ID to the sensors */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(18001);
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);

int d7 =7;
int d8 =8;
float X = 0;
float Y = 0;
int x = 500;
int y = 500;\
int interval = 10;
int samples = 25;

void displaySensorDetails(void) {
  sensor_t sensor;

  gyro.getSensor(&sensor);

  delay(500);
}

void setup(void) {

  pinMode(d7,INPUT_PULLUP);
  pinMode(d8,INPUT_PULLUP);

  Serial.begin(9600);

  if (!gyro.begin()) {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.print("Ooops, no L3GD20 detected ... Check your wiring or I2C ADDR!");
    while (1)
      ;
  }

  // /* Display some basic information on this sensor */
  displaySensorDetails();
}

void loop(void) {
  X = 0;
  Y = 0;
  for(int i=0;i<samples;i++){
    /* Get a new sensor event */
    sensors_event_t event;

    gyro.getEvent(&event);

    X += -event.gyro.y;
    Y += -event.gyro.z;
    delay(interval);
  }
  X = X / samples;
  Y = Y / samples;

  //if(X>0.1||X<-0.1){
      x = x + X*200;
      y = y + Y*200;
  //}
  if(x<10){
    x = 10;
  }
  if(x>1900){
    x=1900;
  }
  if(y<10){
    y = 10;
  }
  if(y>1000){
    y=1000;
  }

  //y = y + Y*3;
  // x = x + 1;
  // y = y + 1;
  //Serial.println(x);

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

  //delay(250);
}
