/*
 * Global variables: Include files and variables such as objects, string and bool.
 * This help with functions, so that the setup and main loop are much smaller.
 * Assembly langauge is not included here, go to #include "DataSort.h".
  */

#include "QuickFlash.h"
#include "LedDesign.h"
#include "DataSort.h"
#include "Led.cpp"

Led led;
Output output;

int num7 = 1;       //for assembly
int num8 = 2;       //for assembly
String inputString = "";      // a String to hold incoming data
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
 * The user input into this function and then the choice is made.
 * The reason I use else if is because it gave me some more flexibility.
 * Also, I cannot use strings with case statements.
 */
void choices(){
  
   if(inputString == "flash\n"){
      startLed();
      flashing();
      clearing();
   }
   
   else if(inputString == "random led\n"){
       startLed(); 
       randomLED();
       clearing();
   }

   else if(inputString == "many random leds\n"){
       startLed(); 
       manyRandomLED();
       clearing();
   }
   
   else if(inputString == "chasing\n"){
        startLed();
        chasingLED();
        clearing();
   }

    else if(inputString == "reverse chasing\n"){
        startLed();
        reverseChasingLED();
        clearing();
   }
   else if(inputString == "all flash\n"){
        startLed();
        allFlashing();
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
   
   else if(inputString == "colored\n"){
        startLed();
        colored();   
        clearing();
   }  

   else if(inputString == "other colored\n"){
        startLed();
        otherColored();   
        clearing();
   }  
   
   else if(inputString == "random choice\n"){
      randomChoice();
   }
   
   else if(inputString == "random choices\n"){
      //Random is random from 2 - 7
      int randomChoices = rand()%(6-2+2)+2;
      Serial.print("Loops: ");
      Serial.println(randomChoices);
      Serial.print("\n");
      randomChoice(randomChoices);
   }

   else if(inputString == "street lights\n"){
      startLed();
      streetLights();
      clearing();
   }

   else if(inputString == "error\n"){
      startLed();
      error();
      clearing();
   }

   else if(inputString == "caution\n"){
      startLed();
      caution();
      clearing();
   }
   
   else if(inputString == "good\n"){
      startLed();
      good();
      clearing();
   }
   
   else if(inputString == "many choices\n"){
      manyChoices();
   }
   
   else if(inputString == "fast flash\n"){
      startLed();
      differentFlash(100);
      clearing();
   }

   else if(inputString == "medium flash\n"){
      startLed();
      differentFlash(1000);
      clearing();
   }
   
   else if(inputString == "slow flash\n"){
      startLed();
      differentFlash(2000);
      clearing();
   }
   
   else if(inputString == "data\n"){
      led.dataCounterIncrease();
      double badCounter = led.badCounterNum();
      double goodCounter = output.goodCounterNum();
      int dataInfo = led.dataCounterNum();
      overallData(badCounter, goodCounter, dataInfo);
   }
   
   else if(inputString == "assembly\n"){
      assemblySetup();
   }

   else if(inputString == "assembly2\n"){
      assemblySetup(num1, num2);
      num1++;
      num2++;
   }
   
   else{
       led.badCounterIncrease();
       Serial.print("Bad Inputs: ");
       Serial.println(led.badCounter);
       Serial.println("Not An Option...\nTry Again...\n");
   }
 }
  
