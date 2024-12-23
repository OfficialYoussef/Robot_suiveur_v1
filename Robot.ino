#define IR_SENSOR_RIGHT 11 // Pin for the right IR sensor
#define IR_SENSOR_LEFT 12 // Pin for the left IR sensor
#define MOTOR_SPEED 195 // Motor speed value

const int ENABLE_RIGHT_MOTOR = 6;
const int RIGHT_MOTOR_PIN1 = 7;
const int RIGHT_MOTOR_PIN2 = 8;
// Define pin numbers for the right motor

const int ENABLE_LEFT_MOTOR = 5;
const int LEFT_MOTOR_PIN1 = 9;
const int LEFT_MOTOR_PIN2 = 10;
// Define pin numbers for the left motor

void setup() {
  // Adjust the frequency of PWM control
  TCCR0B = TCCR0B & B11111000 | B00000010;

  // Setup the motor control pins
  setupMotorPins();

  // Set IR sensors as input
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  // Stop both motors initially
  rotateMotor(0, 0);
}

void loop() {
  // Read the IR sensors
  int rightIRValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRValue = digitalRead(IR_SENSOR_LEFT);

  // Robot logic for movement based on IR sensor input
  if (rightIRValue == LOW && leftIRValue == LOW) {
    // If both sensors detect the line, move forward
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  } else if (leftIRValue == LOW && rightIRValue == HIGH) {
    // If only the left sensor detects the line, turn right
    rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
  } else if (rightIRValue == LOW && leftIRValue == HIGH) {
    // If only the right sensor detects the line, turn left
    rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
  } else {
    // If neither sensor detects the line, stop the motors
    rotateMotor(0, 0);
  }
}

void rotateMotor(int rightSpeed, int leftSpeed) {
  // Set the direction and speed of the motors
  setMotorDirection(RIGHT_MOTOR_PIN1, RIGHT_MOTOR_PIN2, rightSpeed);
  setMotorDirection(LEFT_MOTOR_PIN1, LEFT_MOTOR_PIN2, leftSpeed);
  analogWrite(ENABLE_RIGHT_MOTOR, abs(rightSpeed));
  analogWrite(ENABLE_LEFT_MOTOR, abs(leftSpeed));
}

void setupMotorPins() {
  // Configure the motor pins as output
  pinMode(ENABLE_RIGHT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
  pinMode(ENABLE_LEFT_MOTOR, OUTPUT);
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
}

void setMotorDirection(int pin1, int pin2, int speed) {
  // Determine motor direction based on speed
  if (speed < 0) {
    // Reverse direction if speed is negative
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  } else if (speed > 0) {
    // Forward direction if speed is positive
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  } else {
    // Stop the motor if speed is zero
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
}
