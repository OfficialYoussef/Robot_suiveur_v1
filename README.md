# Robot_suiveur_v1
<p align="center">arduino schema </p>

![Add a heading(1)(1)](https://github.com/user-attachments/assets/3162da3e-3e53-4cbc-8781-257dacf18f74)
## Explanation of Key Points:

### IR Sensors:
- Detect the line.
- **LOW**: The sensor is on the line (black surface).
- **HIGH**: The sensor is off the line (white surface).

### Motor Control:
- **PWM Control**: `analogWrite` sets the speed of the motors.
- **Direction**: Controlled by `digitalWrite` for the motor pins.

### Movement Logic:
- If **both sensors detect the line** (`LOW`), the robot moves forward.
- If **one sensor is off the line** (`HIGH`), the robot turns to adjust.
- If **no sensor detects the line**, the robot stops.

### PWM Frequency:
- `TCCR0B` modifies the frequency for smoother motor control.
![WhatsApp Image 2024-12-23 at 10 33 14(1)](https://github.com/user-attachments/assets/f07820f5-8fd6-48fc-90ca-9b04fe36c076)
### [schema on pdf](https://github.com/user-attachments/files/18228821/Add.a.heading.pdf)
## 1. Matériel nécessaire :

- Arduino Uno R3
- 2 capteurs IR (pour détecter la ligne noire)
- 2 moteurs DC avec roues
- Module L298N (ou un autre driver moteur)
- Batterie (LiPo ou pack de piles)
- Châssis de robot
- Câbles de connexion<br>
# design 
![WhatsApp Image 2024-12-23 at 12 48 44](https://github.com/user-attachments/assets/4f667101-d84b-40e4-b840-aef2811db66f)
# Line Following Robot Code

This is an Arduino code for a basic line-following robot using two IR sensors and two DC motors.

### Pin Configuration:
- **IR Sensors**: 
  - Right sensor: Pin 11
  - Left sensor: Pin 12
- **Motors**: 
  - Right motor: 
    - Enable pin: Pin 6
    - Pin 1: Pin 7
    - Pin 2: Pin 8
  - Left motor: 
    - Enable pin: Pin 5
    - Pin 1: Pin 9
    - Pin 2: Pin 10

### Code:

```cpp
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
```
# linkedin team 
My team work, [@imane-el-amrani](https://www.linkedin.com/in/imane-el-amrani-0a4930330?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=ios_app)  [@zakaria-saide](https://www.linkedin.com/in/zakaria-saide/)  [@rachid-es-sennoun](http://www.linkedin.com/in/rachid-es-sennoun-43994b342)[@ Safae Erahouten](https://www.linkedin.com/in/safae-erahouten-80b240317/) [@me](https://www.linkedin.com/in/youssef-ayouji/)


