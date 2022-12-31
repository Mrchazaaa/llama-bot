#include <Chrono.h>
#include <Servo.h>

#define SERVO_CONTROL_PIN 12
#define SERVO_TIMING_MS 5
#define SERVO_MIN 0
#define SERVO_MAX 65
#define SERVO_NEGATIVE_STEP -5
#define SERVO_POSITIVE_STEP 9

Chrono servoChrono; 
Servo servo;

int servoPosition = SERVO_MIN;
int servoDirection;

void ServoSetup() {
  servo.attach(SERVO_CONTROL_PIN);
}

void ServoControlLoop() {
  if (servoChrono.hasPassed(SERVO_TIMING_MS)) {
    servoChrono.restart();
    
    if (servoPosition >= SERVO_MAX) {
      servoDirection = SERVO_NEGATIVE_STEP;
    }
    if (servoPosition <= SERVO_MIN) {
      servoDirection = SERVO_POSITIVE_STEP;
    }

    servoPosition = servoPosition + servoDirection;
    servo.write(servoPosition);
  }
}
