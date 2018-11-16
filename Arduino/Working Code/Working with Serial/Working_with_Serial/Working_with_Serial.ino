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
long timeThis, timeLast;
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
  battery[0] = analogRead(1);
  battery[1] = analogRead(2);
  battery[2] = analogRead(3);
  timeThis = millis();

  if (timeThis - timeLast >= 1000) {
    timeLast = timeThis;
    sensors.requestTemperatures();

    for (int i = 0; i <= 5; i++) {
      temp[i] = sensors.getTempCByIndex(i);
    }
  }
  battery[0] = battery[0] / 930;
  battery[0] = (battery[0] * 13300) / 3300;
  battery[1] = battery[1] / 930;
  battery[1] = (battery[1] * 11500) / 1500;
  battery[2] = battery[2] / 930;
  battery[2] = (battery[2] * 11000) / 1000;
  battery[1] = battery[1] - battery[0];
  battery[2] = battery[2] - battery[1];
  battery[2] = battery[2] - battery[0];

  if (Serial.available()) {
    char x = Serial.read();
    if (isDigit(x)) {
      inString += x;
    }
    else if (x == ',') {
      //lcd.print(inString);
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
      Serial.print(temp[0]);
      Serial.print(',');
      Serial.print(temp[1]);
      Serial.print(',');
      Serial.print(temp[2]);
      Serial.print(',');
      Serial.print(temp[3]);
      Serial.print(',');
      Serial.print(temp[4]);
      Serial.print(',');
      Serial.print(battery[0]);
      Serial.print(',');
      Serial.print(battery[1]);
      Serial.print(',');
      Serial.print(battery[2]);
      Serial.print('T');
    }
  }
}
