

//Define the sensor pins
#define S1Trig A0 //right
#define S2Trig A2   // center
#define S3Trig A4 // left
#define S1Echo A1
#define S2Echo A3
#define S3Echo A5

const int in1 = 9;

const int in2 = 8;

const int in3 = 4;

const int in4 = 3;

const int enA = 5;

const int enB = 6;


#define PWM 85

//Set the speed of the motors




void setup() {
  Serial.begin(9600);
  
  //Set the Trig pins as output pins
  pinMode(S1Trig, OUTPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S3Trig, OUTPUT);
  
  //Set the Echo pins as input pins 
  pinMode(S1Echo, INPUT);
  pinMode(S2Echo, INPUT);
  pinMode(S3Echo, INPUT);
  

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop(){
  
  int centerSensor = sensorTwo();
  int leftSensor = sensorThree();
  int rightSensor = sensorOne();
// Check the distance using the IF condition
    if(13>=rightSensor){
     /* reverse();
      Serial.println("Reverse");
      delay(500);*/
      left();
      delay(300);
      Serial.println("Left 22");
      forward();
      Serial.println("forward new");
      }
     else if(13>=leftSensor){
      /*reverse();
      Serial.println("Reverse");
      delay(500);*/
      right();
      delay(180);
      Serial.println("Right");
      forward();
      }
  else if (17 >= centerSensor) {
    Stop();
    Serial.println("Stop");
    delay(200);
      if(rightSensor==leftSensor){
        reverse();
        Serial.println("Reverse");
        delay(1000);        
        if (leftSensor > rightSensor) {
        left();
        Serial.println("Left");
        delay(180);
        }
        else {
        right();
        Serial.println("Right");
        delay(180);
        }
      }
      else if (leftSensor > rightSensor) {
        left();
        Serial.println("Left");
        delay(180);
      } 
      else {
        right();
        Serial.println("Right");
        delay(180);
        }
     }
    
  Serial.println("Forward 22");
  forward();
}

//Get the sensor values
int sensorOne() {
  //pulse output
  long dur;
  digitalWrite(S1Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);

  dur = pulseIn(S1Echo ,HIGH);

  return (dur/62); //convert distance to cm
}

//Get the sensor values
int sensorTwo() {
  //pulse output
  long dur;
  digitalWrite(S2Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S2Trig, LOW);

  dur = pulseIn(S2Echo ,HIGH);

  return (dur/30); //convert distance to cm
}

//Get the sensor values
int sensorThree() {
  //pulse output
  long dur;
  digitalWrite(S3Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S3Trig, LOW);

  dur = pulseIn(S3Echo ,HIGH);

  return (dur/50); //convert distance to cm
}


/*******************Motor functions**********************/
void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, PWM);
  analogWrite(enB, PWM);

}

void left()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);
  analogWrite(enB, PWM);

}

void right()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, PWM);
  analogWrite(enB, PWM);

}

void reverse()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);
  analogWrite(enB, PWM);

}

void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  analogWrite(enA, LOW);
  analogWrite(enB, LOW);

}
