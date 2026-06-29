#include <LiquidCrystal.h>

#include <SR04.h>

// Author: Kyle Angeles
// Description: Simple alarm system that actives buzzer and led when condition is met through distance
// looking to updating this with the lcd screen for better visual 
// Updated the project to blink the led and lcd screen to show more visualization prowess


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Variable Declaration
// LED
int ledRed = 4;


// BUZZER
int buzzer = 5;

// SENSOR
const int trigPin = 3;
const int echoPin = 2;

long duration;
float distance;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  // LED PIN MODE
  pinMode(ledRed, OUTPUT);


  // UltraSonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);


  // BUZZER
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.clear();
  

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

  Serial.println("Distance   CM");
  Serial.print(distance);

if (distance  < 10 ) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ALERT   ");
  lcd.print(distance, 1);
  lcd.print(" CM ");

  digitalWrite(buzzer, HIGH);

  digitalWrite(ledRed, HIGH);
  delay(100);
  digitalWrite(ledRed, LOW);
  delay(100);
  

  
} else if (distance < 20) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" WARNING   CM");
  lcd.print(distance, 1);
  lcd.print(" CM ");



  digitalWrite(buzzer, LOW);

  digitalWrite(ledRed, HIGH);
  delay(250);
  digitalWrite(ledRed, LOW);
  delay(250);
  
} else if (distance < 30) {
 
  digitalWrite(ledRed, LOW);
  lcd.setCursor(0, 0);
  lcd.print(" NO WARNING  CM");
  lcd.print(distance, 3);
  lcd.print(" CM ");
  
} else {
 
  digitalWrite(buzzer, LOW);
  digitalWrite(ledRed, LOW);
  lcd.setCursor(0, 0);
  lcd.print(" IN THE CLEAR    CM");
  lcd.print(distance, 3);
  lcd.print(" CM ");
  
}

  delay(200);

  

}
