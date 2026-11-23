#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // Default I2C address 0x40

void setup() {
    Serial.begin(9600);           // Init serial for debugging
    pwm.begin();                  // Init PCA9685
    pwm.setPWMFreq(60);           // 60 Hz PWM frequency for servos
}

void loop() {
    // Servo 0 - Base (MG996R)
    int potValue0 = analogRead(A0);
    int servoPos0 = map(potValue0, 0, 1023, 125, 575);
    pwm.setPWM(0, 0, servoPos0);

    // Servo 1 - Shoulder (MG996R)
    int potValue1 = analogRead(A1);
    int servoPos1 = map(potValue1, 0, 1023, 125, 575);
    pwm.setPWM(1, 0, servoPos1);

    // Servo 2 - Elbow (MG996R)
    int potValue2 = analogRead(A2);
    int servoPos2 = map(potValue2, 0, 1023, 125, 575);
    pwm.setPWM(2, 0, servoPos2);

    // Servo 3 - Wrist Pitch (SG90)
    int potValue3 = analogRead(A3);
    int servoPos3 = map(potValue3, 0, 1023, 125, 575);
    pwm.setPWM(3, 0, servoPos3);

    // Servo 4 - Wrist Roll (SG90) — uses A6 since A4 is I2C SDA on Nano
    int potValue4 = analogRead(A6);
    int servoPos4 = map(potValue4, 0, 1023, 125, 575);
    pwm.setPWM(4, 0, servoPos4);

    // Servo 5 - Gripper (SG90) — uses A7 since A5 is I2C SCL on Nano
    int potValue5 = analogRead(A7);
    int servoPos5 = map(potValue5, 0, 1023, 125, 575);
    pwm.setPWM(5, 0, servoPos5);

    delay(20);   // ~50 Hz control loop update rate
}
