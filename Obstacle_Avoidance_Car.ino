// Obstacle Avoidance Car

#include <AFMotor.h>

#define Trigger_pin A5
#define Echo_pin A4

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR12_1KHZ);
AF_DCMotor motor4(4, MOTOR12_1KHZ);

float distance;
unsigned long duration;

// Code in the void setup runs only once
// Used for initialising stuff
void setup()
{
  pinMode(Trigger_pin, OUTPUT);
  pinMode(Echo_pin, INPUT);
  Serial.begin(9600);
}

// Code in the void loop runs forever until arduino powered off
void loop()
{
  digitalWrite(Trigger_pin, LOW);
  delayMicroseconds(15);
  digitalWrite(Trigger_pin, HIGH); //Sending the ultrasonic wave to measure distance
  delayMicroseconds(10);
  digitalWrite(Trigger_pin, LOW);
  delayMicroseconds(10);
  duration = pulseIn(Echo_pin, HIGH, 30000); // Getting the duration for the wave to comeback
  distance = (duration * 0.017); // Calculating the distance

  // If the echo does not return or if the distance is exactly 15
  if (duration == 0)
  {
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }

  // If the distance measured is greater than 15
  else if (distance >= 15.0)
  {
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

  }

  // If obstacle is detected
  else if (distance < 15.0)
  {
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);

    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);

    delay(300);

    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }

  // no valid response
  else
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
}