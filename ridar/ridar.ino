#include <SoftwareSerial.h>
SoftwareSerial ridar(10, 11); // RX, TX
int input;
int RIGHT = 2;
int LEFT = 3;
int STR = 4;
int BACK = 5;
void setup() 
{  
  ridar.begin(9600);
  Serial.begin(9600);
  pinMode(RIGHT, OUTPUT); //#3
  pinMode(LEFT, OUTPUT);  //#4
  pinMode(STR, OUTPUT); //#1
  pinMode(BACK, OUTPUT);  //#2
  //#5 stright right
  //#6 straight left
  ridar.println("Initiating");
  digitalWrite(RIGHT, LOW);
  digitalWrite(LEFT, LOW);
  digitalWrite(STR, LOW);
  digitalWrite(BACK, LOW);
}  
  
void loop() 
{    
  if (ridar.available()) {
    input = ridar.read();
    Serial.println(input);
    switch(input) {
      case '0':
        digitalWrite(RIGHT, LOW);
        digitalWrite(LEFT, LOW);
        digitalWrite(STR, LOW);
        digitalWrite(BACK, LOW);
        ridar.println("Cleared All");
        break;
      case '1':
        digitalWrite(STR, HIGH);
        ridar.println("Straight set");
        break;
      case '2':
        digitalWrite(BACK, HIGH);
        ridar.println("Back set");
        break;
      case '3':
        digitalWrite(RIGHT, HIGH);
        ridar.println("Right set");
        break;
      case '4':
        digitalWrite(LEFT, HIGH);
        ridar.println("Left set");
        break;
     case '5':
        digitalWrite(STR, HIGH);
        digitalWrite(RIGHT, HIGH);
        ridar.println("Straight Rigt set");
        break;
      case '6':
        digitalWrite(STR, HIGH);
        digitalWrite(LEFT, HIGH);
        ridar.println("Straight Left set");
        break;
      default:
        ridar.println("Invalid code");
        break;
    }
  }
  delay(1000);
} 
