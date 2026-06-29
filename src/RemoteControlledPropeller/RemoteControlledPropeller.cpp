// Author: Kyle Angeles 
// Description: Controlled DC motor with joystick for a simple fan
// File: RemoteControlledPropeller
// Date: 2026/6/28
#include <Arduino.h>
// Variable Declaration


// Joystick
// Using old code from previous mini project
#include <Arduino.h>
int xPin = A0;
int yPin = A1;
int xVal;
int yVal;
int buttonState;
int buttonPin = 2;

// DC motor variables
#define ENABLE 5
#define DIRA 3
#define DIRB 4






void setup() {
  // put your setup code here, to run once:
  // Display feed in the terminal 
  

  // pinMode for the joystick
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  

  // pinMode for the dc motor 
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
  delay(3000);
  





}

void loop() {
  // put your main code here, to run repeatedly:

  // Joystick
  int joystickVal = analogRead(A0);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
 

  // Values for the joystick from old code to display on the serial monitor
  int motorSpeed(0, 1023, 0, 255);
  analogWrite(ENABLE, motorSpeed);
  Serial.println("Joystick: ");
  Serial.print(xVal);
  Serial.println("Speed: ");
  Serial.print(motorSpeed);
  delay(20);

  // digital writes for the dc motor values
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  
  // Testing statements
  // High speed
  // analogWrite(ENABLE, 50);
  // delay(3000);

  // analogWrite(ENABLE, 120);
  // delay(3000);

  // analogWrite(ENABLE, 255);
  // delay(3000);



// Conditional Statements
// Was going to implement with just print statements but had a hard time figuring out whats not working
// so i ask ai to help a bit just for this part 
// but yea
if (xVal > 700) {

  analogWrite(ENABLE, 225);
  Serial.println(" Fast Speed: ");
   
} else if (xVal < 300) {

  analogWrite(ENABLE, 100);
  Serial.println(" Slow Speed");



} else {

  analogWrite(ENABLE, 0);
  Serial.println(" OFF ");
}

delay(3000);

}
