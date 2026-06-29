// Author: Kyle Angeles
// Date-Written: 6/29/26
// Description: Creating a radar system that detects objects based off the ultras sonic sensor based on distance = duration * speed / 2
// used most of my old code for easier implementation
// continuation of learning condition statements and adding more components to projects

#include <LiquidCrystal.h>
#include <Servo.h>
#include <SR04.h>

// Variable Declaration6
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


// Servo
Servo servo1;

// joystick
int xPin = A0;
int yPin = A1;
int buttonPin = 5;
int xVal;
int yVal;
int buttonState;


// Ultrasonic sensor
const int echoPin = 2;
const int trigPin = 3;



long duration;
float distanceObject;
float distanceM;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Servo
  servo1.attach(13);

  // Joystick
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  delay(3000);

  // // // Ultrasound sensor 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);

  // lcd
  lcd.begin(16, 2);
  lcd.clear();

  





}

void loop() {
  // put your main code here, to run repeatedly:

 
 


  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  int servoAngle = map(xVal, 0,  1023, 0, 180);
  servo1.write(servoAngle);
  

   // Sensor  code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // // Math equations simply multipcation 
  duration = pulseIn(echoPin, HIGH, 30000);

  distanceObject = (duration * 0.034) / 2;

  distanceM = duration / 100.0;

  
 

   // x: XXX | y: YYY | Button: 0/1
  // Serial.println(" Unkown Object ");
  // Serial.print(distanceObject);
  // Serial.println("X: ");
  // Serial.println(xVal);
  // Serial.println(" | Y: ");
  // Serial.println(yVal);
  // Serial.println(" | Button: ");
  // Serial.println("buttonState");
  

if (distanceObject < 10) {

  lcd.setCursor(0, 1);
  lcd.print(" Object detected");
  lcd.print(distanceObject);
  

} else if (distanceObject < 30) {
 
  lcd.setCursor(0, 0);
  lcd.print(" Object unknown ");
  lcd.print(distanceObject);
  
}





  delay(50);

}
