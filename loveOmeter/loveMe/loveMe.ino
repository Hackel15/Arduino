const int sensorPin = A0;
const float baselineTemp = 18.0;

void setup() {
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

 int message;
 int var;

void loop() {
  int sensorVal = analogRead(sensorPin);
  //Serial.print("Sensor Value: ");
  //Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0)*5.0;
  //Serial.print(", Volts: ");
  //Serial.print(voltage);
  //Serial.print(", degrees C: ");
  float temperature = (voltage - .5)*100;


  if(temperature < baselineTemp+2){
    var = 1;
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    if(message != var){
      message = 1;
      Serial.println("You're cold blooded");
      Serial.print("Degrees C: ");
      Serial.println(temperature);
    }
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    var = 2;
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    if(message != var){
      message = 2;
      Serial.println("You're warm as a babies bottom");
      Serial.print("Degrees C: ");
      Serial.println(temperature);
    }
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    var = 3;
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    if(message != var){
      message = 3;
      Serial.println("Heating up Sparky!");
      Serial.print("Degrees C: ");
      Serial.println(temperature);
    }
  }else if(temperature >= baselineTemp+6){
    var = 4;
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    if(message != var){
      message = 4;
      Serial.println("OMFG, cool down Sunny :D");
      Serial.print("Degrees C: ");
      Serial.println(temperature);
    }
  }

  delay(3000);

}
