/*
  Monkey Couch Guardian
  Turns on cymbal-banging toy monkey when PIR motion sensor detects motion.
  
  R. Berardino - Took this off Make: Magazine's Weekend Projects Website
  R. Berardino - 04/25/14 - Added Serial Debugging and improved robustness
                            after IG Demo (Got stuck in "Demo Mode" and activated
                            even with PIR unplugged)
*/
#define DEBUG_ON 1


// pin 8 activates the relay which switches on monkey 
// Note: old version used 13 which was a bad idea due to
// unintended consequence was always putting pirState in HIGH state
const int monkeySwitch = 8;

// pin 12 is input for PIR sensor
const int pirInput = 12;

// initialize variables
int pirState = LOW;

// *** Debug Mode Veriable ***
int debugMode = 1; // 0 == OFF | 1 == ON

void setup() 
{

  if(debugMode == DEBUG_ON)
  {
    Serial.begin(9600);
  } 
  // initialize monkeySwitch as an output.
  pinMode(monkeySwitch, OUTPUT);     
  // initialize pirInput 12 as an input.
  pinMode(pirInput, INPUT);
  // waits for 15 seconds to allow PIR sensor to settle down
  delay(15000);
  
}

void loop()
{
  //read PIR value
  pirState = digitalRead(pirInput); 

  //check to see if PIR senses motion
  if (pirState == HIGH)
  {
    if(debugMode == DEBUG_ON)
    {
      Serial.println("You Have Awoken The Monkey!");
      delay(100);
    }
    
    //turn on monkey
    digitalWrite(monkeySwitch, HIGH);
    //monkey runs for 5 seconds
    delay(5000);
    //turn off monkey for 10 seconds so it doesn't activite itself
    digitalWrite(monkeySwitch, LOW);
    delay(10000);
  }
  else
  {
    if(debugMode == DEBUG_ON)
    {
      Serial.println("The Monkey Sleeps!");
      delay(100);
    }
  }

}
