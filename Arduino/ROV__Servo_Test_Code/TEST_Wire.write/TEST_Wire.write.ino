#include <Wire.h>
#include <Servo.h>
Servo MOTOR1;
Servo MOTOR2;
Servo MOTOR3;
int Motors[5];//4-5
int pos = 0;
int number = 0;
int x = 0;
int y = 0;
int z = 0;
int i = 0;
int a = 0;
int b = 0;
int Status = 0;
float e = 0;//analogRead(1)
float r = 0;//analogRead(2)
float t = 0;//analogRead(3)
float s = 0;//Battery cell 1
float d = 0;//Battery cell 2
float f = 0;//Battery cell 3

void setup()
{ 
  
  Wire.begin(0x04); // join i2c bus (address optional for master
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  analogReference(INTERNAL);// sets it to read 1.1V
  //Wire.beginTransmission(0x04);
  //Wire.onRequest(RequestData);

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

void receiveEvent(int byteCount)
{

  while (Wire.available())
  {
    for (int i = 0; i <= 5; i++)
    {
      number = Wire.read();
      //Serial.print(number);
      Motors[i] = number;
      //Serial.println(Motors[i]);
    }

    if (Motors[0] == 4 and Motors[1] == -1) {
      RequestData();
      Serial.println("requesting");
    }
    if (Motors[0] == 5) {
      Status = 1;
      Serial.println("Status=1");
    }
  }
}

void RequestData()
{
  Serial.println("Status=2");
  Status = 2;

  /*if (f > 3.00 and f < 4.40  ) {

    Wire.write('Good');
    }

    else{
    Wire.write('Bad');
    }
  */
  
  Wire.write("12");
  
  //Wire.write(b);
  //Wire.write(s);
  //Wire.write(d);
  //Wire.write(f);
}
