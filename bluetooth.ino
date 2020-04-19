int speedPin1 = 6; // H-bridgke enable pin for speed control
int speedPin2 = 9; // H-bridge enable pin for speed control
int motor1APin = 5; // H-bridge leg 1
int motor2APin = 3; // H-bridge leg 2
int motor4APin = 10; // H-bridge leg 4
int motor3APin = 11; // H-bridge leg 3
int speed_value_motor1; // value for motor speed
int speed_value_motor2; // value for motor
byte state;
const int BTState = 1;
int vSpeed = 200;   // Default speed, from 0 to 255
void setup() {
  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  pinMode(motor1APin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
  pinMode(motor3APin, OUTPUT);
  pinMode(motor4APin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  if (digitalRead(BTState) == LOW) {
    state = 'S';
  }
  if (Serial.available() > 0) {
    state = Serial.read();
    speedcontrol();
    switch (state) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'H':
        spinright();
        break;
      case 'J':
        spinleft();
        break;
      case 'S':
        stoppen();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
}

void forward() {

  if (state = 'F') {
    digitalWrite(motor1APin, LOW);
    digitalWrite(motor2APin, HIGH);
    digitalWrite(motor3APin, LOW);
    digitalWrite(motor4APin, HIGH);
    analogWrite(speedPin1, vSpeed);
    analogWrite(speedPin2, vSpeed);
  }
}
void backward() {

  if (state = 'B') {
    digitalWrite(motor1APin, HIGH);
    digitalWrite(motor2APin, LOW);
    digitalWrite(motor3APin, HIGH);
    digitalWrite(motor4APin, LOW);
    analogWrite(speedPin1, vSpeed);
    analogWrite(speedPin2, vSpeed);
  }
}
void speedcontrol() {
  if (state == '1') {
    vSpeed = 100;
  }
  else if (state == '2') {
    vSpeed = 180;
  }
  else if (state == '3') {
    vSpeed = 200;
  }
  else if (state == '4') {
    vSpeed = 255;
  }
}
void spinright() {
  if (state = 'H') {
    digitalWrite(motor1APin, LOW);
    digitalWrite(motor2APin, HIGH);
    digitalWrite(motor3APin, HIGH);
    digitalWrite(motor4APin, LOW);
    analogWrite(speedPin1, vSpeed);
    analogWrite(speedPin2, vSpeed);
  }
}
void spinleft() {
  if (state = 'J') {
    digitalWrite(motor1APin, HIGH);
    digitalWrite(motor2APin, LOW);
    digitalWrite(motor3APin, LOW);
    digitalWrite(motor4APin, HIGH);
    analogWrite(speedPin1, vSpeed);
    analogWrite(speedPin2, vSpeed);
  }
}
void left(){
  Serial.print("why");
  if (state = 'L') {
    Serial.print("why");
    digitalWrite(motor1APin, LOW);
    digitalWrite(motor2APin, HIGH);
    digitalWrite(motor3APin, LOW);
    digitalWrite(motor4APin, HIGH);
    analogWrite(speedPin1, 255);
    analogWrite(speedPin2, 10);
  }
}
void right(){
  Serial.print("why");
  if (state = 'R') {
    digitalWrite(motor1APin, LOW);
    digitalWrite(motor2APin, HIGH);
    digitalWrite(motor3APin, LOW);
    digitalWrite(motor4APin, HIGH);
    analogWrite(speedPin1, 10);
    analogWrite(speedPin2, 255);
  }
}
void stoppen(){
  if (state = 'S') {
    digitalWrite(motor1APin, LOW);
    digitalWrite(motor2APin, LOW);
    digitalWrite(motor3APin, LOW);
    digitalWrite(motor4APin, LOW);
    analogWrite(speedPin1, 0);
    analogWrite(speedPin2, 0);
  }
}
