
#include <Servo.h> // servo library

int fingerSensorPin = A0; // incoming analog signal from sensor to pin A0
int fingerServoPin = 9; // PWN pin 9 will be used to control servo
int fingerReadValue = 0; // reads the value coming from the sensor at pin A0
int fingerWriteValue = 0; // writes servo position which will be determined by sensor signal

// make int for servo positions for more robust program

Servo fingerServo; // names the servo


void setup() {

  fingerServo.attach(fingerServoPin); // attach servo to fingerServoPin
  Serial.begin(9600);


}

void loop() {

  fingerReadValue = analogRead(fingerSensorPin); // reading from pin A0
  Serial.println(fingerReadValue);
  if(fingerReadValue >= 140){ // if the sensor value is greater than 140 servo moves to 0 degrees which is finger closed position
    fingerServo.write(0);
    }
  
  else if(fingerReadValue <= 50){ //if sensor value is less than 50 servo moves to 180 degrees, finger open position
    fingerServo.write(180);
    }

  
  delay(400);

  
}
