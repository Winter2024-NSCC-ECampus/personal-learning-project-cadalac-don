/*
 * Global variables: Include files and variables such as objects, strings and bool.
 * This help with functions, so that the setup and main loop are much smaller.
 * Assembly langauge is not included here, go to #include "DataSort.h".
 */

#include "QuickFlash.h"
#include "LedDesign.h"
#include "DataSort.h"
#include "Sleeping.h"
#include "Led.cpp"

Led led;
Output output;

int num7 = 1;       //for assembly
int num8 = 2;       //for assembly

String inputString = "";
String flash = "flash\n";
String oneRandomLED = "random led\n";
String manyRandomLEDs = "many random leds\n";
String chasing = "chasing\n";
String reverseChasing = "reverse chasing\n";
String allFlash = "all flash\n";
String opposites = "opposite\n";
String binaryCounters = "binary counter\n";
String reverseBinaryCounters = "reverse binary counter\n";
String siren = "sirens\n";
String colorSystem = "colored\n";
String otherColoredSystem = "other colored\n";
String oneRandomChoice = "random choice\n";
String otherRandomChoices = "random choices\n";
String streetLight = "street lights\n";
String errors = "error\n";
String cautioner = "caution\n"; 
String goodToGo = "good\n";
String manyChoicesToDo = "many choices\n";
String fastFlash = "fast flash\n";
String mediumFlash = "medium flash\n";
String slowFlash = "slow flash\n";

String dataInfo = "data\n";
String assemblyOne = "assembly\n";
String assemblyTwo = "assembly input\n";
String adding = "adding\n";
String voltageDivider = "voltage divider\n";
String controlInput = "switch input\n";
String sleepingOne = "sleep\n";

bool stringComplete = false;  // whether the string is complete

/*
 * Setting up the program with the outputs and baud rate.
 * I test the LEDs too.
 */
void setup() {
  inputString.reserve(200);
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
    
    char inChar = (char)Serial.read();
    inputString += inChar;
    
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
  
   if(inputString == flash){
      startLed();
      flashing();
      clearing();
   }
   
   else if(inputString == oneRandomLED){
       startLed(); 
       randomLED();
       clearing();
   }

   else if(inputString == manyRandomLEDs){
       startLed(); 
       manyRandomLED();
       clearing();
   }
   
   else if(inputString == chasing){
        startLed();
        chasingLED();
        clearing();
   }

    else if(inputString == reverseChasing){
        startLed();
        reverseChasingLED();
        clearing();
   }
   else if(inputString == allFlash){
        startLed();
        allFlashing();
        clearing();
   }
   
   else if(inputString == opposites){
        startLed();
        opposite();  
        clearing();
   }
   
   else if(inputString == binaryCounters){
        startLed();
        binaryCounter();
        clearing();
   }
   else if(inputString == reverseBinaryCounters){
        startLed();
        reverseBinaryCounter();    
        clearing();
   }
   
   else if(inputString == siren){
        startLed();
        sirens();   
        clearing();
   }  
   
   else if(inputString == colorSystem){
        startLed();
        colored();   
        clearing();
   }  

   else if(inputString == otherColoredSystem){
        startLed();
        otherColored();   
        clearing();
   }  
   
   else if(inputString == oneRandomChoice){
      randomChoice();
   }
   
   else if(inputString == otherRandomChoices){
      //Random is random from 2 - 7
      int randomChoices = rand()%(6-2+2)+2;
      Serial.print("Loops: ");
      Serial.println(randomChoices);
      Serial.print("\n");
      randomChoice(randomChoices);
   }

   else if(inputString == streetLight){
      startLed();
      streetLights();
      clearing();
   }

   else if(inputString == errors){
      startLed();
      error();
      clearing();
   }

   else if(inputString == cautioner){
      startLed();
      caution();
      clearing();
   }
   
   else if(inputString == goodToGo){
      startLed();
      good();
      clearing();
   }
   
   else if(inputString == manyChoicesToDo){
      manyChoices();
   }
   
   else if(inputString == fastFlash){
      startLed();
      differentFlash(hundred);
      clearing();
   }

   else if(inputString == mediumFlash){
      startLed();
      differentFlash(thousand);
      clearing();
   }
   
   else if(inputString == slowFlash){
      startLed();
      differentFlash(twoThousand);
      clearing();
   }
   
   else if(inputString == dataInfo){
      led.dataCounterIncrease();
      double badCounter = led.badCounterNum();
      double goodCounter = output.goodCounterNum();
      int dataInfo = led.dataCounterNum();
      overallData(badCounter, goodCounter, dataInfo);
   }
   
   else if(inputString == assemblyOne){
      assemblySetup();
      assemblySetup(num1, num2);
      num1++;
      num2++;
   }
  
   else if(inputString == assemblyTwo){
      assemblySetup(num1, num2);
      num1++;
      num2++;
   }
   
   else if(inputString == adding){
      numOne();      
      num1++;
      num2++;
   }

   else if(inputString == voltageDivider){
      Serial.println("Voltage Input Reader From Voltage Divider");
      voltageReader();
      Serial.println("Reading done...\n");
   }

   else if(inputString == controlInput){
      Serial.println("Switch Input Reader From Switch");
      switchInput();
      Serial.println("Reading done...\n");
   }

   else if(inputString == sleepingOne){
      Serial.println("Sleep for 4 seconds...");
      sleepingTimeOne();
      Serial.println("Sleep for 16 seconds...");
      sleepingTimeTwo();
   }
   
   else{
       led.badCounterIncrease();
       Serial.print("Bad Inputs: ");
       Serial.println(led.badCounter);
       Serial.println("Not An Option...\nTry Again...\n");
   }
 }
  
