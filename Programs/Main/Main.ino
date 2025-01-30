/*
 * Global variables: Include files and variables such as objects, string and bool.
 * This help with functions, so that the setup and main loop are much smaller.
 *
  */

#include "QuickFlash.h"
#include "ledDesign.h"
#include "DataSort.h"
#include "LED.cpp"

LED led;
Output output;

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

/*
 * Setting up the program with the outputs and baud rate.
 * I test the LEDs too.
 */
void setup() {
  startSetup();
  quickFlash();
}

/* 
 *  Main - this loops forever.
 *  There is a button to restart the program on the Arduino.
 */
void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
   output.allCounterIncrease();
        
   //OutPut the choice then to the function of choices based on input    
   Serial.print(inputString);
   Serial.print("Input Count: ");
   Serial.println(output.goodCounter);
   choices();
    
   // clear the string and waits for input
   inputString = "";
   stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    // add it to the inputString:
    inputString += inChar;
    
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

/*
 * The user input into this fubnction and then the choice is made.
 * The reason I use else if is because it gave me some more flexibility that I need.
 */
void choices(){
  
   if(inputString == "flash\n"){
      startLed();
      flashing();
      clearing();
   }
   
   else if(inputString == "random\n"){
       startLed(); 
       randomLED();
       clearing();
   }

   else if(inputString == "many random\n"){
       startLed(); 
       manyRandomLED();
       clearing();
   }
   
   else if(inputString == "chasing\n"){
        startLed();
        chasingLED();
        clearing();
   }
   
   else if(inputString == "all flash"){
        startLed();
        allFlashing();
        clearing();
   }
   
   else if(inputString == "reverse chasing\n"){
        startLed();
        reverseChasingLED();
        clearing();
   }
   
   else if(inputString == "opposite\n"){
        startLed();
        opposite();  
        clearing();
   }
   
   else if(inputString == "binary counter\n"){
        startLed();
        binaryCounter();
        clearing();
   }
   else if(inputString == "reverse binary counter\n"){
        startLed();
        reverseBinaryCounter();    
        clearing();
   }
   
   else if(inputString == "sirens\n"){
        startLed();
        sirens();   
        clearing();
   }  
   
   else if(inputString == "data\n"){
      led.dataCounterIncrease();
      double badCounter = led.badCounterNum();
      double goodCounter = output.goodCounterNum();
      int dataInfo = led.dataCounterNum();
      overallData(badCounter, goodCounter, dataInfo);
   }
       
   else{
       led.badCounterIncrease();
       Serial.print("Bad Inputs: ");
       Serial.println(led.badCounter);
       Serial.println("Not An Option...\nTry Again...\n");
   }
 }
  
