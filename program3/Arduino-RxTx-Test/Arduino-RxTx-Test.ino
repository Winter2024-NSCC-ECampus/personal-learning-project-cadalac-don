/*
 * Global variable
 * This help with functions, so that main loop is smaller
 */

String inputString = "";         // a String to hold incoming data
String flash = "flash\n";
String allFlash = "all flash\n";
String sortByColor = "color\n";
bool stringComplete = false;  // whether the string is complete
int count = 0;

//Setting up the program
void setup() {
  // initialize serial:
  Serial.begin(9600);
  
  //reserve 20 bytes for the inputString:
  inputString.reserve(20);

  //pin setup
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  
  // not necessary but flashes lights with delay, so we know it is working 
  // along with serial communication
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  Serial.println("Setup is complete...\nWelcome...\nInput characters...\n");
}

//main - loops forever
void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    count++;
    Serial.println(inputString + "Input count is " + count);

    //this going to the function of choices based on input
    choices();
    
   // clear the string:
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

//The input goes here and choices are made
void choices(){
   if(inputString == flash)
     flashing();
   
   else if(inputString == allFlash)
    allFlashing();

   else
       Serial.println("Not An Option...\nTry Again...\n");
  }
  
//Flashes the LEDs
void flashing(){
    Serial.println("Flashing now...");
    for (int i=1 ; i<20 ; i = i + 1){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(100);
    }
    Serial.println("Flashing stopped...\n");
  }

  void allFlashing(){
    for(int i = 0; i < 5; i++){
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(9, LOW);
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     delay(100);
     digitalWrite(13, HIGH);
     digitalWrite(12, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(10, HIGH);
     digitalWrite(9, HIGH);
     digitalWrite(8, HIGH);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     delay(100);
    }
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(9, LOW);
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
    Serial.println("All Flashing Done...\n");
  }
