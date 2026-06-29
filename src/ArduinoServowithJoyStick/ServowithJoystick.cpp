#include <Servo.h>
#include <Arduino.h>

// Author: Kyle Angeles
// Date-Written: 6/25/26
// Description: Controlled servo with a joystick based on coordinates based of the xPin and yPin
// and determining the angle for the servo based off the joysticks values
// cool lil mini project focused on controlling an electronic part

// Servo Variables
Servo servo1;

int xPin = A0;
int yPin = A1;
int buttonPin = 2;
int xVal;
int yVal;
int buttonState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(9);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  int joystickVal = analogRead(A0);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  // x: XXX | y: YYY | Button: 0/1
  Serial.print(joystickVal);
  Serial.println("X: ");
  Serial.println(xVal);
  Serial.println(" | Y: ");
  Serial.println(yVal);
  Serial.println(" | Button: ");
  Serial.println("buttonState");
  int servoAngle = map(joystickVal, 0,  1023, 0, 180);
  servo1.write(servoAngle);
  delay(100);

}
