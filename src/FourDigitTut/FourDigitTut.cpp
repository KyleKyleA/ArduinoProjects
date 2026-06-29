#include <Arduino.h>

// Author: Kyle Angeles
// Date-Written: 6/27/26
// Description: Referenced off a youtube tutorial but my 4 digit 7 segment isn't displaying properly still even tho
// i wired it properly and programmed it still displaying weird things i might need to order a new one
// longs of conditional statements and variable declaration
// great reference 

// Segment pins A-G
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

// 74HC595 shift register pins
int latchPin = 9;
int clockPin = 10;
int dataPin = 11;

// 4 digit select pins
int D1 = 12;
int D2 = 13;
int D3 = 11;  // using analog pins as digital
int D4 = 12;

// Number patterns 0-9
// 1=ON 0=OFF, order = a,b,c,d,e,f,g
byte seven_seg_digits[10] = { 
  B00000011,  // 0
  B10011111,  // 1
  B00100101,  // 2
  B00001101,  // 3
  B10011001,  // 4
  B01001001,  // 5
  B01000001,  // 6
  B00011111,  // 7
  B00000001,  // 8
  B00001001   // 9
};

void setup() {
  // Segment pins A-G as output
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

  // Shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Digit select pins as output
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

// Send number pattern to shift register
void sevenSegWrite(byte digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seven_seg_digits[digit]);
  digitalWrite(latchPin, HIGH);
}

// Turn all 4 digits off
void allOff() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void loop() {
  // Count UP 0 to 9
  for (byte digit = 0; digit <= 9; digit++) {

    // Show each number for 1 second across all 4 digits
    unsigned long start = millis();
    while (millis() - start < 1000) {

      allOff();
      digitalWrite(D1, LOW);
      sevenSegWrite(digit);
      delay(2);

      allOff();
      digitalWrite(D2, LOW);
      sevenSegWrite(digit);
      delay(2);

      allOff();
      digitalWrite(D3, LOW);
      sevenSegWrite(digit);
      delay(2);

      allOff();
      digitalWrite(D4, LOW);
      sevenSegWrite(digit);
      delay(2);
    }
  }

  delay(3000); // pause 3 seconds then repeat
}