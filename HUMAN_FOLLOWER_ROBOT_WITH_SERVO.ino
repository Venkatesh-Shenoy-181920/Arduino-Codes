// HUMAN FOLLOWER ROBOT WITH SERVO MOTOR
// CREATED BY S. VENKATESH SHENOY
//CREATED ON 04/10/2023
// VERSION 2

 #include<Servo.h>
 #include<NewPing.h>
 #include<AFMotor.h>

 #define MAX_DISTANCE 200     // MAXIMUM PING DISTANCE 
 #define RIGHT A0             // RIGHT IR SENSOR CONNECTED TO A0 ANALOG PIN
 #define LEFT A1              // LEFT IR SENSOR CONNECTED TO A1 ANALOG PIN
 #define TRIGGER_PIN A2       // TRIGGER OF ULTRASONIC SENSOR CONNECTED TO A2 ANALOG PIN 
 #define ECHO_PIN A3          // ECHO PIN OF ULTRASONIC SENSOR CONNECTED TO A4 ANALOG PIN

 unsigned int distance=0;     // VARIABLE TO STORE ULTRASONIC SENSOR DISTANCE:
 unsigned int RIGHT_Value=0;  // VARIABLE TO STORE RIGHT IR SENSOR VALUE:
 unsigned int LEFT_Value=0;   // VARIABLE TO STORE LEFT IR SENSOR VALUE:

 NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
 Servo S1;
 int pos= 0;
 
 AF_DCMotor MOTOR1(1,MOTOR12_1KHZ);
 AF_DCMotor MOTOR2(2,MOTOR12_1KHZ);
 AF_DCMotor MOTOR3(3,MOTOR34_1KHZ);
 AF_DCMotor MOTOR4(4,MOTOR34_1KHZ);

 void setup() {
     S1.attach(9);            // SERVO ATTACHED TO PIN 9
     pinMode(RIGHT, INPUT);  
     pinMode(LEFT, INPUT);
     for (int pos=90; pos <=180; pos +=1);
    {
      S1.write(i);
      delay(15);
    }
     for(int pos=180; pos >=0; pos -=1);{
     S1.write(i);
     delay(15);
    }
    Serial.begin(9600);
  }

 void loop() 
 {
  delay(50);
  distance=sonar.ping_cm();
  Serial.print("distance");
  Serial.println(distance);

  RIGHT_Value = digitalRead(RIGHT);    // READ VALUE FROM IR SENSOR ON THE RIGHT
  LEFT_Value = digitalRead(LEFT);      // READ VALUE FROM IR SENSOR ON THE LEFT

  Serial.print("RIGHT");
  Serial.println(RIGHT);
  Serial.print("LEFT");
  Serial.println(LEFT);

  if ((RIGHT_Value==1) && (LEFT_Value==1) && (distance < 20))
  {
    MOTOR1.setSpeed(150);
    MOTOR1.run(FORWARD);
    MOTOR2.setSpeed(150);
    MOTOR2.run(FORWARD);
    MOTOR3.setSpeed(150);
    MOTOR3.run(FORWARD);
    MOTOR4.setSpeed(150);
    MOTOR4.run(FORWARD);
  }
  
    if ((RIGHT_Value==1) && (LEFT_Value==0))
    {
       MOTOR1.setSpeed(150);
       MOTOR1.run(BACKWARD);
       MOTOR2.setSpeed(150);
       MOTOR2.run(BACKWARD);
       MOTOR3.setSpeed(150);
       MOTOR3.run(FORWARD);
       MOTOR4.setSpeed(150);
       MOTOR4.run(FORWARD);
    }
    else if((RIGHT_Value==0) && (LEFT_Value==0))
  {
     MOTOR1.setSpeed(0);
     MOTOR1.run(RELEASE);
     MOTOR2.setSpeed(0);
     MOTOR2.run(RELEASE); 
     MOTOR3.setSpeed(0);
     MOTOR3.run(RELEASE);
     MOTOR4.setSpeed(0);
     MOTOR4.run(RELEASE);
  }
    if ((RIGHT_Value==0) && (LEFT_Value==1))
    {
       MOTOR1.setSpeed(150);
       MOTOR1.run(FORWARD);
       MOTOR2.setSpeed(150);
       MOTOR2.run(FORWARD);
       MOTOR3.setSpeed(150);
       MOTOR3.run(BACKWARD);
       MOTOR4.setSpeed(150);
       MOTOR4.run(BACKWARD);
    }
    else if((RIGHT_Value==0) && (LEFT_Value==0))
  {
     MOTOR1.setSpeed(0);
     MOTOR1.run(RELEASE);
     MOTOR2.setSpeed(0);
     MOTOR2.run(RELEASE); 
     MOTOR3.setSpeed(0);
     MOTOR3.run(RELEASE);
     MOTOR4.setSpeed(0);
     MOTOR4.run(RELEASE);
  }
 }
