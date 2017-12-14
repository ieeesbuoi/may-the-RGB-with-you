// led rgb
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// sensor 1
int trigPin1 = 2; // yellow
int echoPin1 = 3; // green

// sensor 2
int trigPin2 = 4; // yellow
int echoPin2 = 5; // green

// sensor 3
int trigPin3 = 6; // yellow
int echoPin3 = 7; // green

//comment this line if using a Common Cathode LED
#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600); // Starts the serial communication
}
 
void loop() {

  /******** RGB LED **********/
  int r = getDistance(trigPin1, echoPin1) ;
  int g = getDistance(trigPin2, echoPin2);
  int b = getDistance(trigPin3, echoPin3);

  
  setColor(r, g, b);
  
}

int getDistance(int trigPin, int echoPin) {

  long duration;
  int distance;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration*0.034/2;
  Serial.println(distance);
  distance *= 10;
  if (distance > 255)
    distance = 255;
  return distance;
}


void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
