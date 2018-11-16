#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include <Servo.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
Servo MOTOR1;
Servo MOTOR2;
Servo MOTOR3;
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int List[5];
int temp[5];
int battery[3];
String inString = "";
int Status = 0;
int index = 0;
int i = 0;
int a = 0;
int x = 0;
int y = 0;
int z = 0;
long timeThis, timeLast;
Adafruit_LiquidCrystal lcd(0);
void setup() {
  // put your setup code here, to run once:
  MOTOR1.attach(9);
  MOTOR2.attach(10);
  MOTOR3.attach(11);
  x = 90;
  y = 90;
  z = 90;
  x = map(x, 0, 180, 54, 130);
  y = map(y, 0, 180, 54, 130);
  z = map(z, 0, 180, 54, 130);
  MOTOR1.write(x);
  MOTOR2.write(y);
  MOTOR3.write(z);
  delay(3000);
}

void loop() {
  x = 110;
  y = 110;
  z = 110;
  x = map(x, 0, 180, 54, 130);
  y = map(y, 0, 180, 54, 130);
  z = map(z, 0, 180, 54, 130);

  MOTOR1.write(x);
  //MOTOR2.write(y);
  //MOTOR3.write(z);
  delay(200);

  x = 90;
  y = 90;
  z = 90;
  x = map(x, 0, 180, 54, 130);
  y = map(y, 0, 180, 54, 130);
  z = map(z, 0, 180, 54, 130);

  MOTOR1.write(x);
  //MOTOR2.write(y);
  //MOTOR3.write(z); 
  delay(150);
  /*

        MOTOR1.write(100);
        MOTOR2.write(100);
        MOTOR3.write(100);
        //delay(200);
        //MOTOR1.write(86);
        //MOTOR2.write(86);
        //MOTOR3.write(86);
        //delay(200);

        //*/

}
