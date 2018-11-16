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
Adafruit_LiquidCrystal lcd(0);

void setup() {
  Serial.begin(38400);
  analogReference(INTERNAL);
  sensors.begin();
  MOTOR1.attach(9);
  MOTOR2.attach(10);
  MOTOR3.attach(11);
}
void loop() {
  
  if (Serial.available()) {
    char x = Serial.read();
    if (isDigit(x)) {
      inString += x;
    }
    else if (x == ',') {
      List[index] = inString.toInt();
      inString = "";
      index++;
    }
    else if (x == 'T') {
      index = 0;
      List[0] = map(List[0], 0, 180, 54, 130);
      List[1] = map(List[1], 0, 180, 54, 130);
      List[2] = map(List[2], 0, 180, 54, 130);
      MOTOR1.write(List[0]);
      MOTOR2.write(List[1]);
      MOTOR3.write(List[2]);
      delay(15);
    }
  }
}
