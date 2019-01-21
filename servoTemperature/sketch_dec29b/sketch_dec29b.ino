/*
  Arduino Starter Kit example
 Project 5  - Servo Mood Indicator

 This sketch is written to accompany Project 5 in the
 Arduino Starter Kit

 Parts required:
 servo motor
 10 kilohm potentiometer
 2 100 uF electrolytic capacitors

 Created 13 September 2012
 by Scott Fitzgerald

 http://www.arduino.cc/starterKit

 This example code is part of the public domain
 */

// include the servo library
#include <Servo.h>

Servo myServo;  // create a servo object

int const tempPin = A0; // analog pin used to connect the potentiometer
int tempVal;  // variable to read the value from the analog pin
int angle;   // variable to hold the angle for the servo motor
float voltage;
float temperature;

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
  // set the servo position
  myServo.write(0);
}


void loop() {
  tempVal = analogRead(tempPin); // read the value of the potentiometer
  voltage = (tempVal/1024.0)*5.0;
  temperature = (voltage - .5) *100;
  // print out the value to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  
  if(temperature < 20){
    myServo.write(0);
    Serial.print(", angle: ");
    Serial.println(0);
  }
  else if(temperature >=20 & temperature < 22){
    myServo.write(60);
    Serial.print(", angle: ");
    Serial.println(60);
  }else if(temperature >= 22 & temperature < 24){
    myServo.write(120);
    Serial.print(", angle: ");
    Serial.println(120);
  }
  
  // scale the numbers from the pot
  //angle = map(tempVal, 0, 1023, 0, 179);

  // wait for the servo to get there
  delay(5000);
}


