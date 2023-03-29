#define IR_SENSOR_PIN_1 A0 // Connect the IR sensor array to Analog pin 0
#define IR_SENSOR_PIN_2 A1 // Connect the IR sensor array to Analog pin 1
#define IR_SENSOR_PIN_3 A2 // Connect the IR sensor array to Analog pin 2
#define IR_SENSOR_PIN_4 A3 // Connect the IR sensor array to Analog pin 3
#define IR_SENSOR_PIN_5 A4 // Connect the IR sensor array to Analog pin 4
#define IR_SENSOR_PIN_6 A5 // Connect the IR sensor array to Analog pin 5
#define IR_SENSOR_PIN_7 A6 // Connect the IR sensor array to Analog pin 6
#define IR_SENSOR_PIN_8 A7 // Connect the IR sensor array to Analog pin 7

int leftMotor = 9; // set the pins for left and right motors
int rightMotor = 10;
int leftSensor = A0; // set the pins for left and right IR sensors
int rightSensor = A1;
int threshold = 500; // set the threshold value for sensor readings


int sensorThreshold = 100; // Adjust this value based on the lighting conditions in your arena
int sensorValues[8]; // Array to store the IR sensor values
int arrowIndex = -1; // Index of the detected arrow
int arrowDirection = 0; // Direction of the detected arrow (-1 for left, 0 for straight, 1 for right)

void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}
void loop() {
  // read the sensor values
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  // adjust the robot's movement based on sensor readings
  if (leftValue > threshold && rightValue > threshold) {
    // both sensors detect an object, move forward
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  } else if (leftValue > threshold && rightValue < threshold) {
    // only left sensor detects an object, turn right
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
  } else if (leftValue < threshold && rightValue > threshold) {
    // only right sensor detects an object, turn left
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
  } else {
    // no sensors detect an object, stop
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
  }
     
  // check for the exit patch
  if (analogRead(exitSensor) > threshold) {
    // exit patch detected, stop the robot
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    break;
  }

  void climbRamp() {
  // move forward until the robot reaches the ramp
  while (analogRead(frontSensor) < threshold) {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  }

  // start climbing the ramp
  while (analogRead(frontSensor) > threshold && analogRead(rampSensor) < threshold) {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  }

  // stop the robot once it reaches the top of the ramp
  digitalWrite(leftMotor, LOW);
  digitalWrite(rightMotor, LOW);
}
void followArrows() {
  // move forward until the first arrow is detected
  while (analogRead(frontSensor) < threshold) {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  }

  // follow the arrows until the exit patch is detected
  while (analogRead(exitSensor) < threshold) {
    int arrowDistance = 0;
    int arrowWidth = 0;
    int arrowHead = 0;
    int arrowTail = 0;

    // detect the arrow and extract its dimensions
    while (arrowDistance < 30) {
      digitalWrite(leftMotor, HIGH);
      digitalWrite(rightMotor, HIGH);
      arrowDistance = analogRead(frontSensor);
    }
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    
}
