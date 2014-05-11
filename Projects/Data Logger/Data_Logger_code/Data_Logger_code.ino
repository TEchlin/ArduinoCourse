// Data Logger project code for the JHU/APL Arduino class May 2014
//
//
// This data logger code is a combination of existing programs:
// TC_74_Test (temperature sensor), ds1307 (real-time clock), and
// datalogger (SD card)

// include the I2C bus library
#include <Wire.h>

// include the real-time clock library
#include <RTClib.h>

 // include the SD library:
#include <SD.h>

// set up SD card variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
const int chipSelect = 10;    

RTC_DS1307 rtc;



	/* source of TC74 code:
	http://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ */

	int address1 = 72;  //decimal address of temp sensor A0
	int address2 = 73;  //decimal address of temp sensor A1
	int address3 = 74;  //decimal address of temp sensor A2
	 
// Here begins the setup routine for data logger program.  It is only executed once per startup
void setup () {	
	  Serial.begin(9600);
	  Wire.begin();     // create a wire object

          rtc.begin();
           
          if (! rtc.isrunning()) {
              Serial.println("RTC is NOT running!");
              
          // following line sets the RTC to the date & time this sketch was compiled
          rtc.adjust(DateTime(__DATE__, __TIME__));
          

  }
  // For the SD memory card: On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  pinMode(10, OUTPUT);     // used for CS on SD memory card.  Change this to 53 on a mega

  Serial.print("Initializing SD card...");
  
    // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized via SD.begin."); 
  
}
	 
// Here begins the main loop for data logger program.  This loop executes continuously.
void loop() {

  // make a string for assembling the data to log:
  String dataString = "";
  	    
  //get and display the time
    DateTime now = rtc.now();


    Serial.print("Date/Time: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    //now read the temp sensor
   
          int c1 = read_temp(address1);
	  
	  Serial.print("Temp: ");
	  Serial.print(c1);
          dataString += String(c1);
          
	    
	  Serial.println("C");

          
    // and make an entry to the data log file on the SD card

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
   
    dataFile.print(now.unixtime());
    dataFile.print(",");
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.print("Logfile entry: "); 
    Serial.print(now.unixtime());
    Serial.print(",");
    Serial.println(dataString);
    Serial.println();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt"); 

  } 
          
	  delay(2000);  
} /* end of main loop */
	 
// Subroutine to read temperature
int read_temp(int address) {
	  //start the communication with IC with the address xx
	  Wire.beginTransmission(address); 
	  //send a bit and ask for register zero
	  Wire.write(0);
	  //end transmission
	  Wire.endTransmission();
	  //request 1 byte from address xx
	  Wire.requestFrom(address, 1);
	  //wait for response
	  while(Wire.available() == 0);
	  //put the temperature in variable c
	  int c = Wire.read();   
	  return c;
}


