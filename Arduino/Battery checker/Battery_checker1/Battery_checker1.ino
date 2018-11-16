float e = 0;//analogRead(1)
float r = 0;//analogRead(2)
float t = 0;//analogRead(3)
float s = 0;//Battery cell 1
float d = 0;//Battery cell 2
float f = 0;//Battery cell 3
void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);//

}

void loop() {
e = analogRead(1);
r = analogRead(2);
t = analogRead(3);

s = e * 4.2;
s = s / 969;//equation for Battery cell 1



Serial.print(s);//Battery cell 1
Serial.print(',');
Serial.print(d);//Battery cell 2
Serial.print(',');
Serial.println(f);//Battery cell 3
}
