#include <Servo.h>
Servo myservo; 
int pos = 0; 
int state; int flag=0;
void setup() 
{ 
pinMode(10,OUTPUT);
myservo.attach(9);  
Serial.begin(9600);
myservo.write(1800); 
delay(1000); 
digitalWrite(10,LOW);
}
void loop()
{ 
if(Serial.available() > 0)
{ 
state = Serial.read();
flag=0; 
}     // if the state is '0' the DC motor will turn off 
if (state == '0')
{ 
myservo.write(180); 
delay(1000); 
Serial.println("Door Locked"); 
digitalWrite(10,LOW);
} 
else if (state == '1') 
{ 
myservo.write(0); 
delay(1000); 
Serial.println("Door UnLocked"); 
digitalWrite(10,HIGH);
} 
}
