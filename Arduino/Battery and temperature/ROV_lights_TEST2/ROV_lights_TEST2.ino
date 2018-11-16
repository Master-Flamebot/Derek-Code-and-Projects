#include <Wire.h>
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
Servo MOTOR1;
Servo MOTOR2;
Servo MOTOR3;
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int Motors[5];//4-5
int pos = 0;
int number = 0;
int x = 0;
int y = 0;
int z = 0;
int i = 0;
int a = 0;
int b = 0;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;
int Status = 0;
float e = 0;//analogRead(1)
float r = 0;//analogRead(2)
float t = 0;//analogRead(3)
float s = 0;//Battery cell 1
float d = 0;//Battery cell 2
float f = 0;//Battery cell 3
long timeThis, timeLast;
void setup()
{
  Wire.begin(0x04); // join i2c bus (address optional for master
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  analogReference(INTERNAL);// sets it to read 1.1V
  Wire.beginTransmission(0x01);
  sensors.begin();
  MOTOR1.attach(9);
  MOTOR2.attach(10);
  MOTOR3.attach(11);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  MOTOR1.write(90); // set servo to mid-point (90°)
  delay(2000);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}
void loop()
{
  timeThis = millis();
  if (timeThis - timeLast >= 10000) {
    Serial.println("count!");
    timeLast = timeThis;
    sensors.requestTemperatures();
    t1 = sensors.getTempCByIndex(0); 
    t2 = sensors.getTempCByIndex(1);
    t3 = sensors.getTempCByIndex(2);
    t4 = sensors.getTempCByIndex(3);
    t5 = sensors.getTempCByIndex(4);
  }
    Serial.print(t1);
    Serial.print(',');
    Serial.print(t2);
    Serial.print(',');
    Serial.print(t3);
    Serial.print(',');
    Serial.print(t4);
    Serial.print(',');
    Serial.print(t5);
    Serial.print(',');
  e = analogRead(1);
  r = analogRead(2);
  t = analogRead(3);
  e = e / 930;
  e = (e * 13300) / 3300;
  s = e;
  r = r / 930;
  r = (r * 11500) / 1500;
  r = r - s;
  d = r;
  t = t / 930;
  t = (t * 11000) / 1000;
  t = t - r;
  t = t - s;
  f = t;
  Serial.print(s);//Battery cell 1
  Serial.print(',');
  Serial.print(d);//Battery cell 2
  Serial.print(',');
  Serial.println(f);//Battery cell 3
  Serial.print(',');
}
void receiveEvent(int byteCount)
{
  while (Wire.available())
  {
    for (int i = 0; i <= 5; i++)
    {
      number = Wire.read();
      Motors[i] = number;
    }

    if (Motors[0] == 4 and Motors[1] == -1) {
      RequestData();
    }
    if (Motors[0] == 5) {
      Status = 1;
    }
    if (Status == 1) {
      x = Motors[1];
      x = map(x, 0, 180, 54, 130);
      y = Motors[2];
      y = map(y, 0, 180, 54, 130);
      z = Motors[3];
      z = map(z, 0, 180, 54, 130);
      a = Motors[4];
      a = a - 1;
      a = !a;
      b = Motors[5];
      b = b - 1;
      b = !b;
      MOTOR1.write(x);
      MOTOR2.write(y);
      MOTOR3.write(z);
      if (a == 1) {
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
      }
      if (b == 1) {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
      }
    }
  }
}

void RequestData()
{
  Status = 2;
}




