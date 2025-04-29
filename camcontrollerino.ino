#include <Servo.h>

// pin defs
const int trigPin      = 10;
const int echoPin      =  9;
const int ledPin       = 11;
const int buzzerPin    = 13;
const int servoPin     =  6;
const int buttonPin    =  2; 

// threshold in inches
const float thresholdDistance = 8.0;

Servo cameraServo;
long   duration;
float  distanceInches;

bool servoActivated = false;
bool started        = false;

void setup() {
  pinMode(trigPin,   OUTPUT);
  pinMode(echoPin,   INPUT);
  pinMode(ledPin,    OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  cameraServo.attach(servoPin);
  cameraServo.write(0);
}

void loop() {
  // button and countdown
  if (!started) {
    if (digitalRead(buttonPin) == LOW) {
      delay(50);  // debounce
      if (digitalRead(buttonPin) == LOW) {
        servoActivated = false;  // reset servo

        // turn off LED during countdown
        digitalWrite(ledPin, LOW);

        // countdown 5→1
        for (int i = 5; i > 0; i--) {
          Serial.print("Starting in ");
          Serial.print(i);
          Serial.println("...");
          digitalWrite(buzzerPin, HIGH);
          delay(100);
          digitalWrite(buzzerPin, LOW);
          delay(900);
        }
        started = true;
        Serial.println("Go!");
      }
    }
    return;  // wait for button & countdown
  }

  // distance mesurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration       = pulseIn(echoPin, HIGH);
  distanceInches = duration * 0.034 / 2.0 / 2.54;

  Serial.print("Distance: ");
  Serial.print(distanceInches);
  Serial.println(" in");

  // alert and servo  
  if (distanceInches <= thresholdDistance) {
    digitalWrite(buzzerPin, HIGH);

    if (!servoActivated) {
      servoActivated = true;
      cameraServo.write(90);   // press
      delay(500);
      cameraServo.write(0);    // back home

      // keep LED on to indicate picture taken
      digitalWrite(ledPin, HIGH);

      // turn off buzzer after action
      digitalWrite(buzzerPin, LOW);

      // require button again for next picture
      started = false;
      Serial.println("Done. Press button to take another.");
    }
  } 
  else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
