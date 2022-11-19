#include <SoftwareSerial.h>

// defining the pin of the motor
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

char inputByte;

SoftwareSerial blu (4,3);

void setup() {
  Serial.begin(9600);
  blu.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

}

void loop() {
  if(blu.available()>0) /// Receiving the data from the bluetooth
  {
    inputByte= blu.read(); /// Read the string recevied from bluetooth
    Serial.println(inputByte);   //// serially printing the data received from bluetooth 
    switch(inputByte)     //// switch condition for the controlling
    {
      case 'F':
        Forward();      //// motor will move forward
        Serial.println("forward");
        break;
  
      case 'B':
        Backward();     //// motor will move backward
        Serial.println("backward");
        break;
  
      case 'L':
        Left();    //// motor will move left
        Serial.println("left");
        break;
  
      case 'R':
        Right();  //// motor will move right
        Serial.println("right");
        break;

      case '0':
        Stop();   //// motor will stop moving
        Serial.println("stop");
        break;
        
      default:
        break;
    }
  }
}

//Defining forward condition
void Forward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

//Defining backward condition
void Backward()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

//Defining left condition
void Left()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

//Defining right condition
void Right()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

//Defining stop condition
void Stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
