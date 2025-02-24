/*
 * Global variables: 
 * The top variables are for the assembly program.
 */
extern "C" int addNumbers(int a, int b); 
int num1 = 5;
int num2 = 6;
int num3; 
  
/*
 * Method overloading with one of the random choice loops.
 * There is a random number between two numbers.
 * Based on the random number, a switch-statment choice is made.
 * This is to showcase switch-statement and random numbers.
 */
void randomChoice(){
  
  int randomChoice = rand()%(5-1+1)+1;
  Serial.print("Choice: ");
  Serial.println(randomChoice);

  //case statement
  switch(randomChoice ){
    case 1:
      startLed();
      flashing();
      clearing();
      break;

    case 2:
       startLed(); 
       randomLED();
       clearing();
       break;
       
    case 3:
       startLed(); 
       manyRandomLED();
       clearing();
       break;
       
    case 4:
        startLed();
        chasingLED();
        clearing();
        break;
        
    case 5: 
        startLed();
        allFlashing();
        clearing();
        break;
        
    default:
      Serial.println("OH NO! No random choice!\n");
  }
}

/*
 * There is a random number between 1 to 5.
 * Based on the random number, a switch-statment choice is made.
 * This is to showcase switch-statement and random numbers.
 */
void randomChoice(int randomNum){
  
  int randomChoice = rand()%(5-1+1)+1;

  for(int i = 1; i <= randomNum; i++){

    randomChoice = rand()%(5-1+1)+1;
     Serial.print("Choice: ");
     Serial.println(randomChoice);
     
    //case statement
    switch(randomChoice){
      case 1:
        startLed();
        otherColored();
        clearing();
        break;
  
      case 2:
         startLed(); 
         randomLED();
         clearing();
         break;
         
      case 3:
         startLed(); 
         manyRandomLED();
         clearing();
         break;
         
      case 4:
          startLed();
          chasingLED();
          clearing();
          break;
          
      case 5: 
          startLed();
          allFlashing();
          clearing();
          break;
          
      default:
        Serial.println("OH NO! No many random choice!\n");
    }
  }
}

/*
 * This goes through most of the options all at once.
 * This will help for demos and overall flashing concepts.
 * This can be easily expands as other functions are added 
 */
void manyChoices(){
  
  startLed();
  flashing();
  otherClearing();
  
  randomLED();
  otherClearing();
  
  manyRandomLED();
  otherClearing();
    
  chasingLED();
  otherClearing();
  
  reverseChasingLED();
  otherClearing();
  
  allFlashing();
  otherClearing();
  
  opposite();  
  otherClearing();

  binaryCounter();
  otherClearing();

  reverseBinaryCounter();    
  otherClearing();

  sirens();   
  otherClearing();

  colored();   
  otherClearing();
  
  otherColored();   
  otherClearing();

  streetLights();
  otherClearing();

  error();
  otherClearing();
  
  caution();
  otherClearing();
  
  good();
  otherClearing();
  
  differentFlash(100);
  otherClearing();
  
  differentFlash(1000);
  otherClearing();
  
  differentFlash(2000);
  clearing();
  }

/*
 * This connects to the assembly program. 
 * The program sends two number in a register, which is added in assembly.
 * The numbers are in this class
 */
void assemblySetup(){
  num3 = addNumbers(num1, num2);
  Serial.print("Sum of ");
  Serial.print(num1);
  Serial.print(" and ");
  Serial.print(num2);
  Serial.print(" is ");
  Serial.println(num3);

  num1 = addNumbers(num3, num2);
  Serial.print("Sum of ");
  Serial.print(num3);
  Serial.print(" and ");
  Serial.print(num2);
  Serial.print(" is ");
  Serial.println(num1);
  Serial.println("");
  }

/*
 * This connects to the assembly program. 
 * The program sends two number in a register, which is added in assembly.
 * The numbers come from the .ino file
 */
void assemblySetup(int num4, int num5){
  int num6 = addNumbers(num4, num5);
  Serial.print("Sum of ");
  Serial.print(num4);
  Serial.print(" and ");
  Serial.print(num5);
  Serial.print(" is ");
  Serial.println(num6);
  Serial.println("");
  }
  
/*
 * Data is formulated and printed with good data and bad data.
 * This showcases passing variables and doing calculations.
 */
void overallData(double counter, double count, int dataInfo){
   double badData = (counter/count)*100;
   double goodData = 100.00-badData;

   Serial.print("Data Called ");
   Serial.print(dataInfo);
   Serial.println(" time(s)!");
   
   Serial.print("Bad Input Percentage: ");
   Serial.print(badData);
   Serial.println("%");

   Serial.print("Good Input Percentage: ");
   Serial.print(goodData);
   Serial.println("%\n");
}  

  
