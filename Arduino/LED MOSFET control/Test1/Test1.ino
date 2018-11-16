int x=0;
void setup() {

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {

  if (digitalRead(5) == LOW) {
    delay(100); 
    x = !x;
    digitalWrite(3, x);
    digitalWrite(4, x);
  }
}



/*
if (digitalRead(switchPin) == LOW)
  {  // switch is pressed - pullup keeps pin high normally
    delay(100);                        // delay to debounce switch
    running = !running;                // toggle running variable
    digitalWrite(LEDpin, running);      // indicate via LED
  }

  */
