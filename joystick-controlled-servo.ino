//www.elegoo.com
//2018.12.19
#include <Servo.h>
Servo myservo;

#define servo_pin 9

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

bool pressed = false;
bool waiting = true;
bool locked  = false;

void setup(){
  myservo.attach(servo_pin);
  myservo.write(90);// move servos to center position -> 90°
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
} 
void loop(){
  if(waiting){
    if(digitalRead(SW_pin) == 0){
      locked  = !locked;
      pressed = true;
      waiting = false;
    } else {
      pressed = false;
    }
  } else {
    if(digitalRead(SW_pin) == 1) {
      waiting = true;
    } else {
      waiting = false;
    }
  }

  if(!locked){
    myservo.write(analogRead(Y_pin)*180.0/1023.0);
  }
//   

}
