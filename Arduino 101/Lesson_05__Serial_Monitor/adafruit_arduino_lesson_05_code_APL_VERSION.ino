/*
Arduino Course, Main_Track, Lesson 5: Serial_Monitor
Shows Serial_Monitor data flow from IDE to Arduino: input to Arduino.
This adapted from the Adafruit Arduino Lesson 5.
$Id: Arduino_lesson_05_serial_monitor_APL_VERSION.ino,v 1.17 2014/04/05 15:09:11 gralimj1 Exp gralimj1 $
 */

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  setColor(0, 0, 0); // Set initial condition
  Serial.begin(9600);
  if (Serial.available()) {  // Wait until serial line available.
    delay (200);
  }
  Serial.println ("Enter LED color: r, g, b");
  Serial.println ("  'd' to make all dark; 'w' to make white; no quote."); 
  Serial.println ("Remember to 'Enter' or click 'Send'.");
  Serial.println ("All other characters ignored.");

}

void loop()
{
  char ch = Serial.read();

  if (ch == 'r' || ch == 'R')
  {
    setColor(16, 0, 0);  // red
    Serial.print("Turned on LED ");
    Serial.println("red");
  }
  if (ch == 'g' || ch == 'G')
  {
    setColor(0, 16, 0);  // green?
    Serial.print("Turned on LED ");
    Serial.println("green");
  }
    if (ch == 'b' || ch == 'B')
    {
      setColor(0, 0, 16);  // blue?
      Serial.print("Turned on LED ");
      Serial.println("blue");
    }
    if (ch == 'w' || ch == 'W')
    {
      setColor(16, 16, 16); 
      Serial.println("Turned all LED's ON" );
    }
  if (ch == 'd' || ch == 'D')
  {
    setColor(0, 0, 0);
    Serial.println("Turned all LED's OFF");
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}





