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

# linkedin team 
My team work, [@imane-el-amrani](https://www.linkedin.com/in/imane-el-amrani-0a4930330?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=ios_app)  [@zakaria-saide](https://www.linkedin.com/in/zakaria-saide/)  [@rachid-es-sennoun](http://www.linkedin.com/in/rachid-es-sennoun-43994b342)[@ Safae Erahouten](https://www.linkedin.com/in/safae-erahouten-80b240317/) [@me](https://www.linkedin.com/in/youssef-ayouji/)


