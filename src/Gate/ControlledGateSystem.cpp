#include <SR04.h>

#include <Servo.h>
// Author: Kyle Angeles
// Date-Written:  6/29/26
// Description: Controlled Servo real life gate use of a sensor when triggered by an object open the 
// the gate at 90 degrees by the servo or no object is detected close gate at 0 degrees
// use most of old code for reference for the pins and variable declarations
// cool lil mini project.


// Variables

// SERVO
Servo Servo1;

// Sensor
const int trigPin = 3;
const int echoPin = 2;

long duration;
float distance;

int pos = 0;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Servo1.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);


  Servo1.write(0);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

  

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  distance = duration * 0.0343 / 2;

  Serial.println("Distance CM");
  Serial.print(distance);


  if (distance > 10) {
    Servo1.write(90);
  } else if (distance < 20) {
    Servo1.write(0);
  }


  delay(100);

}
