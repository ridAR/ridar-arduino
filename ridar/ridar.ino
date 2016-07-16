#include <SoftwareSerial.h>
SoftwareSerial ridar(10, 11); // RX, TX
int input;
int RIGHT = 2;
int LEFT = 3;
int STR = 4;
int BACK = 5;
bool strblk = false;
bool backblk = false;
bool rightblk = false;
bool leftblk = false;
bool strrtblk = false;
bool strltblk = false;
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
      case 0:
        digitalWrite(RIGHT, LOW);
        digitalWrite(LEFT, LOW);
        digitalWrite(STR, LOW);
        digitalWrite(BACK, LOW);
        strblk = false;
        backblk = false;
        rightblk = false;
        leftblk = false;
        strrtblk = false;
        strltblk = false;
        ridar.println("Cleared All");
        break;
      case 1:
        digitalWrite(STR, HIGH);
        strblk = false;
        ridar.println("Straight set");
        break;
      case 2:
        digitalWrite(BACK, HIGH);
        backblk = false;
        ridar.println("Back set");
        break;
      case 3:
        digitalWrite(RIGHT, HIGH);
        rightblk = false;
        ridar.println("Right set");
        break;
      case 4:
        digitalWrite(LEFT, HIGH);
        leftblk = false;
        ridar.println("Left set");
        break;
     case 5:
        digitalWrite(STR, HIGH);
        digitalWrite(RIGHT, HIGH);
        strrtblk = false;
        ridar.println("Straight Rigt set");
        break;
      case 6:
        digitalWrite(STR, HIGH);
        digitalWrite(LEFT, HIGH);
        strltblk = false;
        ridar.println("Straight Left set");
        break;
      case 7:
        strblk = true;
        break;
      case 8:
        backblk = true;
        break;
      case 9:
        rightblk = true;
        break;
      case 10:
        leftblk = true;
        break;
      case 11:
        strrtblk = true;
        break;
      case 12:
        strltblk = true;
        break;  
      default:
        ridar.println("Invalid code");
        break;
    }
  }
  if(strblk || backblk || rightblk || leftblk || strrtblk || strltblk)  {
    for(int i = 0; i < 5; i++) {
      if(strblk){
        digitalWrite(STR, HIGH);
      }
      if(backblk){
        digitalWrite(BACK, HIGH);
      }
      if(rightblk){
        digitalWrite(RIGHT, HIGH);
      }
      if(leftblk){
        digitalWrite(LEFT, HIGH);
      }
      if(strrtblk){
        digitalWrite(STR, HIGH);
        digitalWrite(RIGHT, HIGH);
      }
      if(strltblk){
        digitalWrite(STR, HIGH);
        digitalWrite(LEFT, HIGH);
      }
      delay(100);
      digitalWrite(STR, LOW);
      digitalWrite(BACK, LOW);
      digitalWrite(RIGHT, LOW);
      digitalWrite(LEFT, LOW);
      delay(100);
    }
  }
  else{
    delay(1000);
  }
  
} 
