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
bool backrtblk = false;
bool backltblk = false;
void setup() 
{  
  ridar.begin(9600);
  Serial.begin(9600);
  pinMode(STR, OUTPUT); //#1
  pinMode(BACK, OUTPUT);  //#2
  pinMode(LEFT, OUTPUT);  //#3  
  pinMode(RIGHT, OUTPUT); //#4
  //#5 stright left
  //#6 straight right
  //#7 back left
  //#8 back right
  //# blink straight
  //# blink back
  //# blink left
  //# blink right
  //# blink straight left
  //# blink straight right
  //# blink back left
  //# blink back right
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
        backrtblk = false;
        backltblk = false;
        ridar.println("Cleared All");
        break;

        //SOLID LEDs Set high 1-4
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
        digitalWrite(LEFT, HIGH);
        leftblk = false;
        ridar.println("Left set");
        break;
      case 4:
        digitalWrite(RIGHT, HIGH);
        rightblk = false;
        ridar.println("Right set");
        break;

     //SET half angles SOLID LEDs High   
     case 5:
        digitalWrite(STR, HIGH);
        digitalWrite(LEFT, HIGH);
        strltblk = false;
        ridar.println("Straight left set");
        break;
      case 6:
        digitalWrite(STR, HIGH);
        digitalWrite(RIGHT, HIGH);
        strrtblk = false;
        ridar.println("Straight right set");
        break;
      case 7:
        digitalWrite(BACK, HIGH);
        digitalWrite(LEFT, HIGH);
        backltblk = false;
        ridar.println("back left set");
        break;
      case 8:
        digitalWrite(BACK, HIGH);
        digitalWrite(RIGHT, HIGH);
        backrtblk = false;
        ridar.println("back right set");
        break;

       //BLINK LEDs 
      case 9:
        strblk = true;
        break;
      case 10:
        backblk = true;
        break;
      case 11:
        leftblk = true;
        break;
      case 12:
        rightblk = true;
        break;
      case 13:
        strltblk = true;
        break;
      case 14:
        strrtblk = true;
        break;
      case 15:
        backltblk = true;
        break;
       case 16:
        backrtblk = true;
        break;
       
      default:
        ridar.println("Invalid code");
        break;
    }
  }
  if(strblk || backblk || rightblk || leftblk || strrtblk || strltblk || backltblk || backrtblk)  {
    for(int i = 0; i < 5; i++) {
      if(strblk){
        digitalWrite(STR, HIGH);
      }
      else if(backblk){
        digitalWrite(BACK, HIGH);
      }
      else if(rightblk){
        digitalWrite(RIGHT, HIGH);
      }
      else if(leftblk){
        digitalWrite(LEFT, HIGH);
      }
      else if(strrtblk){
        digitalWrite(STR, HIGH);
        digitalWrite(RIGHT, HIGH);
      }
      else if(strltblk){
        digitalWrite(STR, HIGH);
        digitalWrite(LEFT, HIGH);
      }
      else if(backrtblk){
        digitalWrite(BACK, HIGH);
        digitalWrite(RIGHT, HIGH);
      }
      else if(backltblk){
        digitalWrite(BACK, HIGH);
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
