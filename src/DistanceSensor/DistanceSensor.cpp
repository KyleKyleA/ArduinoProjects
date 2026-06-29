#include <LiquidCrystal.h>

#include <SR04.h>

// Author: Kyle Angeles
// Date-Written: 6/26/26
// Description: Creating a ultras sonic detection system that detects are object based off the sensor
// and lists the distance in CM and M based off how far the object is.
// later on be adding the active buzzer.



// Libraries for this cool mini project

// Buzzer
int buzzer = 5;

// Define variables
const int trigPin = 3;
const int echoPin = 2;



long duration;
float distanceCM;
float distanceM;

const int distanceMTime = 5000;





#include <LiquidCrystal.h>

// Intialize the library with the number of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  // put your setup code here, to run once:
  

  


  

  // LCD display 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Distance meter: ");

  // // Ultrasound sensor 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);
 

 // Buzzer
 pinMode(buzzer, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  // Sensor  code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // // Math equations simply multipcation 
  duration = pulseIn(echoPin, HIGH);

  distanceCM = (duration * 0.034) / 2;

  distanceM = duration / 100.0;

  // Serial.println("Distance: ");
  // Serial.print(distanceCM);
  // Serial.println("  CM");
  // Serial.println("Distance:   ");
  // Serial.print(distanceM);
  // Serial.println("  M");
  // delay(100000);

  // // Printing statements for the lcd screen
  // // In cm
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCM, 1);
  lcd.print("cm  ");


  // // In meters
 
  lcd.setCursor(0, 1);
  lcd.print(" Distance: ");
  lcd.print(distanceM, 3);
  lcd.print(" M ");
}
// Active buzzer 
// for (int i = 0; i < 80; i++ ) {
//     digitalWrite(buzzer, HIGH);
//     delay(200);


//   }

//   delay(distanceMTime);
// }


// Active buzzer





