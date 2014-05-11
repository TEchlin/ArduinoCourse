/*
    Adafruit Arduino - Lesson 9. Sensing Light - LEDs
 As modified by MJG for the APL course.
 $Id: Adafruit_09_APL_a.ino,v 1.6 2014/03/04 00:20:49 gralimj1 Exp gralimj1 $
 */

int lightPin = 0;
int lightMin = 340; // The smallest value measured
int lightMax = 890; // The largest value measured
int redPin = 8;
int yellowPin = 6;
int greenPin = 4;
float potMax = 1023.0;  // The largest value possible
float potMin = 0.0;     // The smallest value possible
float numLEDs = 3.0;    // How many LEDs we have.
int stepSize = int(potMax/(numLEDs + 1.0)); 

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  all_off;
  Serial.begin(9600); 
}

void loop()
{
  int reading = analogRead(lightPin);
  int compensatedReading = map (reading, lightMin, lightMax, potMin, potMax);
  if (true)
  {
    Serial.print("reading := ");
    Serial.print(reading);
    Serial.print(";  compensatedReading := ");
    Serial.print(compensatedReading);
    Serial.println();
  }
  if (compensatedReading >= stepSize) {
    digitalWrite(greenPin,HIGH);
    if (compensatedReading >= (stepSize<<1)) {
      digitalWrite(yellowPin,HIGH);
      if (compensatedReading >= (3*stepSize)) {
        digitalWrite(redPin,HIGH);
      }
    }
  }
  delay (300);
  all_off ();
}

void all_off () {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}



