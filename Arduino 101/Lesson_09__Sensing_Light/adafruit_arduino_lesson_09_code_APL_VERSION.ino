/*
 Adafruit Arduino - Lesson 9. Sensing Light - LEDs Shows a
 photo resistor can control a red, yellow and green LED,
 with more LEDs lit the brighter the light.  Also shows
 Serial_Monitor from Arduino to IDE; "const" and "byte".
 This inspired by the Adafruit Arduino Lesson 9.
 $Id: arduino_lesson_09_sensing_light_APL_VERSION.ino,v 1.13 2014/04/05 19:30:44 gralimj1 Exp gralimj1 $
 */

const byte lightPin = 0;
const int lightMin = 275; // The smallest value measured
const int lightMax = 902; // The largest value measured
const byte redPin = 8;
const byte yellowPin = 6;
const byte greenPin = 4;
const float senseMax = 1023.0;  // The largest value possible
const float senseMin = 0.0;     // The smallest value possible
const float numLEDs = 3.0;      // How many LEDs we have.
const int stepSize = int(senseMax/(numLEDs + 1.0)); 

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
  int compensatedReading
    = map (reading, lightMin, lightMax, senseMin, senseMax);
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




