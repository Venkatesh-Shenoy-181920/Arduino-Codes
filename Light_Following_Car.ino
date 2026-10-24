/*Light Following Car Code 
In case the robot is not reacting to light or highly sensitive then adjust your LDR sensor*/

#include<AFMotor.h> 

#define M1 A1


AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(M1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int MSensor = digitalRead(M1);


Serial.print("MSensor");
Serial.println(MSensor);


if((MSensor == 1)) { 
  //MOVE FORWARD
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  motor4.setSpeed(200);
  motor4.run(FORWARD);
  
} 

else{
  //STOP
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
delay(50);
}
