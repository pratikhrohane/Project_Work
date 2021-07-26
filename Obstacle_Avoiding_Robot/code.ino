const int frontEchoPin = 7;
const int frontTriggerPin = 6;
const int leftEchoPin = 11;
const int leftTriggerPin = 10;
const int rightEchoPin = 9;
const int rightTriggerPin = 8;
const int motorL1 = 2;
const int motorL2 = 3;
const int motorR1 = 4;
const int motorR2 = 5;
volatile float maxFrontDistance = 25;
volatile float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm, rightDuration, rightDistanceCm;

void setup() {
  // serial
  Serial.begin(9600);
  // ultrasonic
  pinMode(frontTriggerPin, OUTPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(leftTriggerPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTriggerPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  // motors
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
}
void loop() {
  // front distance check
  checkFrontDistance();
  if (frontDistanceCm < maxFrontDistance) {
    checkLeftDistance();
    delay(20);
    checkRightDistance();
    delay(20);
    if (leftDistanceCm < rightDistanceCm)
      moveRight();
    else if (leftDistanceCm > rightDistanceCm) {
      moveLeft();
    }
  }
  else {
    moveForward();
  }
}
void checkFrontDistance() {
  digitalWrite(frontTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(frontTriggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(frontTriggerPin, LOW);
  frontDuration = pulseIn(frontEchoPin, HIGH);  
  frontDistanceCm = frontDuration * 10 / 292 / 2;  
  Serial.print("Distance: ");
  Serial.print(frontDistanceCm);
  Serial.println(" cm");
}
void checkLeftDistance() {
  digitalWrite(leftTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(leftTriggerPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(leftTriggerPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);  
  leftDistanceCm = leftDuration * 10 / 292 / 2;  
  Serial.print("Left distance: ");
  Serial.print(leftDistanceCm);
  Serial.println(" cm");
}
void checkRightDistance() {
  digitalWrite(rightTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(rightTriggerPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(rightTriggerPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);  
  rightDistanceCm = rightDuration * 10 / 292 / 2;  
  Serial.print("Right distance: ");
  Serial.print(rightDistanceCm);
  Serial.println(" cm");
}
void moveBackward() {
  Serial.println("Backward.");
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
}
void moveForward() {
  Serial.println("Forward.");
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
}
void moveLeft() {
  Serial.println("Left.");
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
}
void moveRight() {
  Serial.println("Right.");
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
}