int ground1 = A0;
int ground2 = A1;
int ground3 = A2;

int blue = A5;
int green = A4;
int red = A3;

int led1 = 11;
int led2 = 12;
int led3 = 13;

int MUX_Input[8] = {0};
const int SZ = 8;
int out = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(ground1, OUTPUT);
  pinMode(ground2, OUTPUT);
  pinMode(ground3, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  analogWrite(ground1, LOW);
  analogWrite(ground2, LOW);
  analogWrite(ground3, LOW);
  analogWrite(red, LOW);
  analogWrite(green, LOW);
  analogWrite(blue, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //updateMux1 ();
  testBoard();
  //printInput();
  //digitalWrite(pin1, HIGH);
  //digitalWrite(pin2, LOW);
  //digitalWrite(pin3, LOW);
}

void testBoard() {
  while (true) {
    //analogWrite(blue, 255);
    analogWrite(green, 255);
      for(int i=0;i<8;i++){
        digitalWrite(led1, (HIGH && (i & 1)));
        digitalWrite(led2, (HIGH && (i & 10)));
        digitalWrite(led3, (HIGH && (i & 100)));
        for(int j=0;j<8;j++) {
          digitalWrite(ground1, (HIGH && (j & 1)));
          digitalWrite(ground2, (HIGH && (j & 10)));
          digitalWrite(ground3, (HIGH && (j & 100)));
          delay(50);
        }
      }
  }
}

//void printInput() {
//  for(int i = 0; i < 8; i++) {
//    Serial.print(MUX_Input[i]);
//    Serial.print(", ");
//  }
//  Serial.println();
//}
//
//void updateMux1 ()
//{
//    for(int i = 0; i < 8; i++) {
//      digitalWrite(pin1, (HIGH && (i & 1)));
//      digitalWrite(pin2, (HIGH && (i & 10)));
//      digitalWrite(pin3, (HIGH && (i & 100)));
//      MUX_Input[i] = digitalRead(out12);
//      delay(100);
//    }  
//}

