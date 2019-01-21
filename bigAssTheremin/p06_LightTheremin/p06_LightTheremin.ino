/*
  Arduino Starter Kit example
 Project 6  - Light Theremin

 This sketch is written to accompany Project 6 in the
 Arduino Starter Kit

 Parts required:
 photoresistor
 10 kilohm resistor
 piezo

 Created 13 September 2012
 by Scott Fitzgerald

 http://www.arduino.cc/starterKit

 This example code is part of the public domain
*/

// variable to hold sensor value
int sensorValue;
int sensorValue2,
    sensorValue3;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  Serial.print("Sensor LOW: ");
  Serial.println(sensorLow);
  Serial.print("Sensor HIGH: ");
  Serial.println(sensorHigh);
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

  float lowBoundry = ((sensorHigh - sensorLow) / 3.0) + sensorLow;
  float highBoundry = sensorHigh - ((sensorHigh - sensorLow) / 3.0);
void loop() {


  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);
  Serial.print("Sensor Val 1: ");
  Serial.println(sensorValue);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);


  if(sensorValue >= sensorLow && sensorValue < lowBoundry){
      tone(8, pitch, 20);
      Serial.print("Pitch Val 1: ");
      Serial.println(pitch);
  }
  else if(sensorValue >= lowBoundry && sensorValue < highBoundry){
    tone(8, pitch, 20);
    Serial.print("Pitch Val 2: ");
      Serial.println(pitch);
  }
  else if(sensorValue >= highBoundry && sensorValue <= sensorHigh){
    tone(8, pitch, 20);
    Serial.print("Pitch Val 3: ");
    Serial.println(pitch);
  }

  // play the tone for 20 ms on pin 8
  
  //tone(8, pitch, 20);
  //tone(8, pitch2, 100);
  //tone(8, pitch3, 300);
  

  // wait for a moment
  delay(3000);
}

