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
my team work,[@imane-el-amrani](https://github.com/imane-el-amrani) .


