// MOTOR A
#define enA 2
#define in1MotorA 3
#define in2MotorA 4

// MOTOR B
#define enB 7
#define in3MotorB 6
#define in4MotorB 5

// MOTOR C
#define enC 13
#define in1MotorC 12
#define in2MotorC 11

// MOTOR D
#define enD 8
#define in3MotorD 10
#define in4MotorD 9

// LIFT MOTOR
#define enT 46
#define in1MotorT 53
#define in2MotorT 52

void setupMotor() {
  pinMode(in1MotorA, OUTPUT);
  pinMode(in2MotorA, OUTPUT);
  pinMode(in3MotorB, OUTPUT);
  pinMode(in4MotorB, OUTPUT);
  pinMode(in1MotorC, OUTPUT);
  pinMode(in2MotorC, OUTPUT);
  pinMode(in3MotorD, OUTPUT);
  pinMode(in4MotorD, OUTPUT);
  pinMode(in1MotorT, OUTPUT);
  pinMode(in2MotorT, OUTPUT);
}

// All wheels move forward
void moveForward(int speedA, int speedB, int speedC, int speedD) 
{
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, HIGH);
  // Motor B
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, HIGH);
  // Motor C
  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, HIGH);
  // Motor D
  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, HIGH);
}

// All wheels move backward
void moveBackward(int speedA, int speedB, int speedC, int speedD)  
{
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, HIGH);
  digitalWrite(in2MotorA, LOW);
  // Motor B
  digitalWrite(in3MotorB, HIGH);
  digitalWrite(in4MotorB, LOW);
  // Motor C
  digitalWrite(in1MotorC, HIGH);
  digitalWrite(in2MotorC, LOW);
  // Motor D
  digitalWrite(in3MotorD, HIGH);
  digitalWrite(in4MotorD, LOW);
}

// Wheels A + D move forward, B + C stop
void moveForwardDiagonalRight(int speedA, int speedD)  
{
  analogWrite(enA, speedA);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, HIGH);
  // Motor B
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, LOW);
  // Motor C
  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, LOW);
  // Motor D
  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, HIGH);
}

// Wheels A + D stop, B + C back
void moveBackDiagonalRight(int speedB, int speedC)  
{
  analogWrite(enA, 0);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, 0);
  // Motor A
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, LOW);
  // Motor B
  digitalWrite(in3MotorB, HIGH);
  digitalWrite(in4MotorB, LOW);
  // Motor C
  digitalWrite(in1MotorC, HIGH);
  digitalWrite(in2MotorC, LOW);
  // Motor D
  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, LOW);
}

// Wheels A + D move forward, B + C stop
void moveBackDiagonalLeft(int speedA, int speedD)  
{
  analogWrite(enA, speedA);
  analogWrite(enD, speedD);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  // Motor A
  digitalWrite(in1MotorA, HIGH);
  digitalWrite(in2MotorA, LOW);
  // Motor B
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, LOW);
  // Motor C
  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, LOW);
  // Motor D
  digitalWrite(in3MotorD, HIGH);
  digitalWrite(in4MotorD, LOW);
}

// Wheels A + D stop, B + C move forward
void moveForwardDiagonalLeft(int speedB, int speedC)  
{
  analogWrite(enA, 0);
  analogWrite(enD, 0);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  // Motor A
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, HIGH);
  // Motor B
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, HIGH);
  // Motor C
  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, HIGH);
  // Motor D
  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, HIGH);
}

// Wheel A + D forward, B + C backward
void moveRight(int speedA, int speedB, int speedC, int speedD)
{
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, HIGH);
  // Motor B
  digitalWrite(in3MotorB, HIGH);
  digitalWrite(in4MotorB, LOW);
  // Motor C
  digitalWrite(in1MotorC, HIGH);
  digitalWrite(in2MotorC, LOW);
  // Motor D
  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, HIGH);
}

// Wheel A + D backward, B + C forward
void moveLeft(int speedA, int speedB, int speedC, int speedD) 
{
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, HIGH);
  digitalWrite(in2MotorA, LOW);
  // Motor B
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, HIGH);
  // Motor C
  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, HIGH);
  // Motor D
  digitalWrite(in3MotorD, HIGH);
  digitalWrite(in4MotorD, LOW);
}

// Wheel A + C backward, B + D forward
void rotateLeft(int speedA, int speedB, int speedC, int speedD)
{
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, HIGH);
  digitalWrite(in2MotorA, LOW);
  // Motor B
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, HIGH);
  // Motor C
  digitalWrite(in1MotorC, HIGH);
  digitalWrite(in2MotorC, LOW);
  // Motor D
  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, HIGH);
}

// Wheel A + C forward, B + D backward
void rotateRight(int speedA, int speedB, int speedC, int speedD) 
{
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  analogWrite(enC, speedC);
  analogWrite(enD, speedD);
  // Motor A
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, HIGH);
  // Motor B
  digitalWrite(in3MotorB, HIGH);
  digitalWrite(in4MotorB, LOW);
  // Motor C
  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, HIGH);
  // Motor D
  digitalWrite(in3MotorD, HIGH);
  digitalWrite(in4MotorD, LOW);
}

// All wheels turn off
void stopBot(int timer)    
{
  digitalWrite(in1MotorA, LOW);
  digitalWrite(in2MotorA, LOW);
  
  digitalWrite(in3MotorB, LOW);
  digitalWrite(in4MotorB, LOW);

  digitalWrite(in1MotorC, LOW);
  digitalWrite(in2MotorC, LOW);

  digitalWrite(in3MotorD, LOW);
  digitalWrite(in4MotorD, LOW);

  digitalWrite(in1MotorT, LOW);
  digitalWrite(in2MotorT, LOW);

  delay(timer);
}