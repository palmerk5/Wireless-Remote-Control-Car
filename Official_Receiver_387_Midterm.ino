#include <RCSwitch.h>
#include <Servo.h>
#include <NewPing.h>
 
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo1;
Servo myservo2;
int qlock = 0;
int switcher = 0;
RCSwitch mySwitch = RCSwitch();
void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0); 
  myservo1.attach(6);
  myservo2.attach(5);
  
}

void loop() {
  
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue();
    int uS = sonar.ping_cm();
 
    if (value == 0) {
      Serial.print("Unknown encoding");
    } 
    while (value == 1111 && uS > 6 && switcher == 0) {
      myservo1.write(70);
      myservo2.write(70);
      value = 1;
    }
    while (value == 2222 && uS > 6 && switcher == 0) {
      myservo1.write(80);
      myservo2.write(110);
      value = 1;
    }
    while (value == 3333 && switcher == 0) {
      myservo1.write(100);
      myservo2.write(80);
      value = 1;
    }
    while (value == 4444 && uS > 6 && switcher == 0) {
      myservo1.write(110);
      myservo2.write(110);
      value = 1;
    }
    while (value == 5555 && switcher == 0){
      myservo1.write(90);
      myservo2.write(90);
      uS = sonar.ping_cm();
      value = 1;
    }
    
    while (uS < 6 && switcher == 0) {
      myservo1.write(100);
      myservo2.write(80);
      value = 1;
      uS = sonar.ping_cm();
    }

    while (uS < 12 && switcher == 1) {
      myservo1.write(110);
      myservo2.write(110);
      value = 1;
      uS = sonar.ping_cm();
    }
    
    while (value == 6666 && switcher == 0) {
      switcher = 1;
    }
  
    while (uS > 10 && switcher == 1 && qlock < 500) {
      uS = sonar.ping_cm();
      myservo1.write(80);
      myservo2.write(110);
      qlock = qlock + 1;
    }

    while (qlock == 500 && switcher == 1) {
      myservo1.write(90);
      myservo2.write(90);
      qlock = 0;
      switcher = 0;
    }
    mySwitch.resetAvailable();
  }
}
