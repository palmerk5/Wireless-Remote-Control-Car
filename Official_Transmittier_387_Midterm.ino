#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
const int buttonPin = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);
    pinMode(buttonPin4, INPUT);
    pinMode(buttonPin5, INPUT);
    Serial.begin(9600);
  
  mySwitch.enableTransmit(10);
 
}

void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);

    if (buttonState == HIGH){
    mySwitch.send(1111, 24);
    delay(100);  
  }
    else if (buttonState2 == HIGH){
    mySwitch.send(2222, 24);
    delay(100);  
  }
    else if (buttonState3 == HIGH){
    mySwitch.send(3333, 24);
    delay(100);  
  }
    else if (buttonState4 == HIGH){
    mySwitch.send(4444, 24);
    delay(100);  
  }
    else if (buttonState5 == HIGH){
    mySwitch.send(6666, 24);
    delay(100);  
  }
    else {
    mySwitch.send(5555, 24);
    delay(100);    
    }

}
