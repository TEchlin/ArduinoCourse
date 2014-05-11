/*
Arduino Course, Main_Track, Lesson 8: Analog Inputs
Shows a pot can control a red, yellow and green LED, with more
LEDs lit the "higher" a pot is set.
This inspired by the Adafruit Arduino Lesson 8, the main
thread.
$Id: arduino_lesson_08b_analog_input_APL_VERSION.ino,v 1.12 2014/04/05 17:18:18 gralimj1 Exp gralimj1 $
*/
const int potPin = 0;
const int redPin = 8;
const int yellowPin = 6;
const int greenPin = 4;
const float potMax = 1023.0; // The largest value possible
const float numLEDs = 3.0; // How many LEDs we have.
const int stepSize = int(potMax/(numLEDs + 1.0));
void setup()
{
pinMode(redPin, OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode(greenPin, OUTPUT);
all_off;
}
void loop()
{
int reading = analogRead(potPin);
if (reading >= stepSize) {
digitalWrite(greenPin,HIGH);
if (reading >= (stepSize<<1)) {
digitalWrite(yellowPin,HIGH);
if (reading >= (3*stepSize)) {
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
