#include <SoftwareSerial.h>
SoftwareSerial ridar(10, 11); // RX, TX
int input;
int LED = 13;
void setup() 
{  
  ridar.begin(9600);
  pinMode(LED, OUTPUT);
}  
  
void loop() 
{    
  if (ridar.available()) {
    input = ridar.read();
    if (input == '1') {
      digitalWrite(LED, HIGH);
      ridar.println("LED ON");

    } else if (input == '0') {
      digitalWrite(LED, LOW);
      ridar.println("LED OFF");

    } else {
      ridar.println("Invalid input");
    }
  }
  delay(1000);

} 
