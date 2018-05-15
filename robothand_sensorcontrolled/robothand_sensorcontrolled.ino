
#include <Servo.h> // servo library

int sensorPin = A0; // incoming analog signal from sensor to pin A0
int sensorReadValue = 0; // reads the value coming from the sensor at pin A0
int finger1ServoPin = 3; // PWM pin 9 will be used to control servo
int finger2ServoPin = 9;
int finger3ServoPin = 6;
int finger4ServoPin = 5;
int finger5ServoPin = 10;
int finger1Closed = 90;
int finger2Closed = 0;
int finger3Closed = 180;
int finger4Closed = 180;
int finger5Closed = 0;
int finger1Open = 0;
int finger2Open = 180;
int finger3Open = 0;
int finger4Open = 0;
int finger5Open = 180;

Servo finger1Servo; // names the servo
Servo finger2Servo;
Servo finger3Servo;
Servo finger4Servo;
Servo finger5Servo;

void setup() {

  finger1Servo.attach(finger1ServoPin); // attach servo to fingerServoPin
  finger2Servo.attach(finger2ServoPin);
  finger3Servo.attach(finger3ServoPin);
  finger4Servo.attach(finger4ServoPin);
  finger5Servo.attach(finger5ServoPin);
  Serial.begin(9600);


}

void loop() {

  sensorReadValue = analogRead(sensorPin); // reading from pin A0
  Serial.println(sensorReadValue);

 
  if(50 < sensorReadValue < 140){ // if the sensor value is greater than 140 servo moves to 0 degrees which is finger closed position
    finger1Servo.write(finger1Closed);
    finger2Servo.write(finger2Closed);
    finger3Servo.write(finger3Open);
    finger4Servo.write(finger4Closed);
    finger5Servo.write(finger5Closed);

    if (sensorReadValue >= 140){  
    finger1Servo.write(finger1Closed);
    finger2Servo.write(finger2Closed);
    finger3Servo.write(finger3Closed);
    finger4Servo.write(finger4Closed);
    finger5Servo.write(finger5Closed);
    }

    if (sensorReadValue <= 50){ //if sensor value is less than 50 servo moves to 180 degrees, finger open position
    finger1Servo.write(finger1Open);
    finger2Servo.write(finger2Open);
    finger3Servo.write(finger3Open);
    finger4Servo.write(finger4Open);
    finger5Servo.write(finger5Open);
    }
  }
  
  



  


  
  delay(200);

  
}
