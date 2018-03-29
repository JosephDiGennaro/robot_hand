#include <Servo.h> //includes servo library

int fingerPotPin = A0; // pin recieving potentiometer information
int thumbPotPin = A1;
int servoPos;   //servo position to be determined in code by the potentiometer
int thumbServoPin = 9;
int fingerServoPin = 10;
int readValueFinger;
int readValueThumb;
int writeValueFinger;//servo position to be determined in code by the potentiometer
int writeValueThumb;

Servo thumbServo; //name servos
Servo fingerServo; //single servo controlling 4 fingers


void setup() {

  thumbServo.attach(thumbServoPin);
  fingerServo.attach(fingerServoPin);
  Serial.begin(9600); //starts serial monitor 
  

}

void loop() {

  readValueFinger = analogRead(fingerPotPin); //reading from potentiometer
  readValueThumb = analogRead(thumbPotPin);
  Serial.print("finger potentiometer reading: ");
  Serial.println(readValueFinger);
  Serial.print("thumb potentiometer reading: ");
  Serial.println(readValueThumb);
  delay(10);
  writeValueFinger = map(readValueFinger, 0, 1023, 0, 180); //creates relationship between potentiometer and servo position
  fingerServo.write(writeValueFinger); //moves servo
  writeValueThumb = map(readValueThumb, 0, 1023, 0, 140);
  thumbServo.write(writeValueThumb);
  Serial.print("thumb servo position: ");
  Serial.println(writeValueThumb);
  Serial.print("finger servo postition: ");
  Serial.println(writeValueFinger);
  delay(10);

}
