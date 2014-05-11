/*
Adafruit Arduino - Lesson 3. RGB LED
 $Id: Adafruit_05_Mod_Serial_IO.ino,v 1.9 2014/03/03 13:38:55 gralimj1 Exp gralimj1 $
 */

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  Serial.begin(9600);
  setColor(0, 0, 0); // Set initial condition
  Serial.println("Enter LED color: r, g, b;");
  Serial.println ("  'd' to make all dark; w to make white"); 
}

void loop()
{
  if (Serial.available())
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
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}



