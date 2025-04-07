/*
 * Global variables: 
 * The top variables are for the assembly program.
 * The voltage divider
 * The switch
 */
extern "C" int addNumbers(int a, int b); 
int num1 = 5;
int num2 = 6;
int num3; 
int serialInput = 9600;
    
int sensorPin = A0;
int sensorValue = 0;

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 1; // analog pin connected to X output
const int Y_pin = 2; // analog pin connected to Y output  
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
  
  int delayInfo = 100;
  int longerDelay = 1000;
  int longestDelay = 2000;
  
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
  
  differentFlash(delayInfo);
  otherClearing();

  differentFlash(longerDelay);
  otherClearing();
  
  differentFlash(longestDelay);
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
  Serial.println("Other adding method...");
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
  
   double badData = (counter/count)*hundred;
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

/*
 * NumOne is getting numbers for inputto add.
 * This does not increase counter for additional inputs.
 */
void numOne(){
  
    Serial.println("Enter First Number: ");
    while(!Serial.available()){
    }
    int num1 = Serial.parseInt();
    Serial.println(num1);
    Serial.end();
    Serial.begin(serialInput); 
    
    Serial.println("Enter Second Number: ");
    while(!Serial.available()){
    }
    int num2 = Serial.parseInt();
    Serial.println(num2);
    Serial.end();
    Serial.begin(serialInput); 
    
    assemblySetup(num1, num2);
}

/*
 * Simple voltage divider with a photo-resister and regular resister.
 * Read voltage input at input A0 from middle of the two components.
 * Delay before entering while loop. I wanted to prove that I could do a while-loop.
 * Loop: leads voltage input, displays voltage value and an toggles LED.
 */
void voltageReader(){
  
  delay(thousand);
  int looper = 0;

  while(looper < 20){
    sensorValue = analogRead(sensorPin);
    digitalWrite(13, HIGH);
    Serial.println(sensorValue);
    delay(100);
    digitalWrite(13, LOW);
    Serial.println(sensorValue);
    delay(100); 
    looper++;
  }
}

/*
 * This is part of switch and uses a do-while for more theory concepts.
 * digitalRead(SW_pin) is 1 because it is high vs the analogRead is variable.
 * While it might be more ideal to start the switch info elsewhere: 
 *    But not needed. This is so pins could be reusable for other reasons.
 */
void switchInput(){
  int looper = 0;
  int delay2 = 400;
  delay(thousand);
  
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  do{
    Serial.print("Switch:  ");
    Serial.print(digitalRead(SW_pin));
    Serial.print(" | ");
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_pin));
    Serial.print(" | ");
    Serial.print("Y-axis: ");
    Serial.print(analogRead(Y_pin));
    Serial.println(" | ");
    delay(delay2);
    looper++;
  } while(looper < 30);
}

       
