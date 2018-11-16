int a;

void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() {

while(Serial.available()) {

a = Serial.read();// read the incoming data


Serial.println(a);

}

}
