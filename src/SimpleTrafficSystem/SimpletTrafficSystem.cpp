#include <Arduino.h>

// Author: Kyle Angeles
// Description: Simply traffic light system with a active buzzer addon every time it hits red


// LED COLORS
int ledRed = 13;
int ledYellow = 12;
int ledGreen = 11;


// TIME
const int ledRedTime = 5000;
const int ledYellowTime = 2000;
const int ledGreenTime = 5000;

// BUZZER
int buzzer = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // LED PIN MODE
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // BUZZER
  pinMode(buzzer, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  
  // LED GREEN (traffic light means GO)
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(ledGreenTime);
  

  // LED YELLOW
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledGreen, LOW);
  delay(ledYellowTime);


  // LED RED
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);


// Active buzzer for loop
// What this does it outputs a frequency 1 through 80 and each time
// it increments by 1 
// outputting buzzer noise 
// Active buzzer is used for the red led since it means stop
for (int i = 0; i < 80; i++) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
   
  }

  delay(ledRedTime);
}

 


  






