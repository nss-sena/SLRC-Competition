

//Define the sensor pins
#define S1Trig A4
#define S2Trig A2
#define S3Trig A0
#define S1Echo A5
#define S2Echo A3
#define S3Echo A1

const int in1 = 9;

const int in2 = 8;

const int in3 = 4;

const int in4 = 3;

const int enA = 5;

const int enB = 6;


#define PWM 100

//Set the speed of the motors

#define DIS 15
  

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
  
  if (FrontSensor() < DIS && RightSensor () < DIS && LeftSensor()< DIS) //obstacle infront of all 3 sides
  { 
  
    Stop();
    Serial.println("Stop");
    delay(100);
    //then reverse
    reverse();
    Serial.println("reverse");
    delay(300);
    
  //then reverse
  }

  else if (FrontSensor()< DIS && RightSensor()<DIS && LeftSensor()>DIS)//obstacle on right and front sides
  {
    Stop();
    Serial.println("Stop");
    delay(100);
    Serial.println("left");
    turn_left();
    //turn left side

  }

  else if (FrontSensor()<DIS&& RightSensor()> DIS && LeftSensor()<DIS) //obstacle on left and front sides
  {
    Stop();
    Serial.println("Stop");
    delay(100);
    turn_right();
    Serial.println("right");
    //turn right side
  }

  else if (FrontSensor()<DIS && RightSensor()> DIS && LeftSensor()>DIS) //obstacle on front sides
  {
    Stop();
    Serial.println("Stop");
    delay(100);
    turn_right();
    Serial.println("right");
    // then turn right
  }

  else if (FrontSensor()>DIS && RightSensor()> DIS && LeftSensor()<DIS) //obstacle on left sides
  {
    Stop();
    Serial.println("Stop");
    delay(100);
    turn_right();
    Serial.println("right");
    // then turn right & then forward
    delay(180);
    forward();
    Serial.println("forward");
  }

  else if (FrontSensor()>DIS && RightSensor()< DIS && LeftSensor()>DIS) //obstacle on right sides

  {
    Stop();    
    Serial.println("Stop");
    delay(100);
    turn_left();
    Serial.println("right");
    // then turn left & then right

    delay(180);
    forward();
    Serial.println("forward");
  }
  else
  {
    forward();
  }

}

//Get the sensor values
long LeftSensor()
{
  long dur;

  digitalWrite(S1Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);  
  dur = pulseIn(S1Echo ,HIGH);

  return (dur/50); //convert distance to cm

}
//Get the sensor values frontSensor
long FrontSensor()
{
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

long RightSensor()
{
  long dur;
  digitalWrite(S3Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S3Trig, LOW);
  dur = pulseIn(S3Echo,HIGH);

  return (dur/62); //convert distance to cm

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

void turn_left()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);
  analogWrite(enB, PWM);

}

void turn_right()
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
