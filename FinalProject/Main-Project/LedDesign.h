/*
 * This is where most of the flashing LEDs happen.
 * It starts with a print statement with startLED() and goes on from there.
*/
int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};
int numLeds = 9;
int numOnLeds = 3;

int fifty = 50;
int hundred = 100;
int threeHundred = 300;
int thousand = 1000;
int thousandAndHalf = 1500;
int twoThousand = 2000;

void startLed(){
  Serial.println("Flashing now...");
}

//Flashes two LEDs
void flashing(){
    for (int i=1 ; i<20 ; i = i + 1){
      digitalWrite(nine, HIGH);
      digitalWrite(ten, HIGH);
      delay(hundred);
      digitalWrite(nine, LOW);
      digitalWrite(ten, LOW);
      delay(hundred);
    }
  }

//Turns on random LED and then turns it off
void randomLED(){
      int randNumber = random(5, 14);
      Serial.println(randNumber);
      digitalWrite(randNumber, HIGH);
      delay(thousandAndHalf);
    }

//Turns on random LED and then turns it off
void manyRandomLED(){
  
  for(int i = 0; i< 10; i++){
      int randNumber = random(5, 14);
      Serial.println(randNumber);
      digitalWrite(randNumber, HIGH);
      delay(thousand);
      digitalWrite(randNumber, LOW);
  }
}

//This is a common LED concept
void chasingLED(){
  for(int j=0; j<20; j++){
    for(int i=5; i<=13; i++)
    {
      digitalWrite(i,HIGH);
      delay(fifty);
      digitalWrite(i,LOW);
      delay(fifty);
    }
  }
} 

//This is a common LED concept
void reverseChasingLED(){
  for(int j=0; j<20; j++){
    for(int i=13; i>=5; i--)
    {
      digitalWrite(i,HIGH);
      delay(fifty);
      digitalWrite(i,LOW);
      delay(fifty);
    }
  }
} 

//turns all LEDS off and on
void allFlashing(){
  for(int i = 0; i < 5; i++){
     digitalWrite(thirteen, LOW);
     digitalWrite(twelve, LOW);
     digitalWrite(eleven, LOW);
     digitalWrite(ten, LOW);
     digitalWrite(nine, LOW);
     digitalWrite(eight, LOW);
     digitalWrite(seven, LOW);
     digitalWrite(six, LOW);
     digitalWrite(five, LOW);
     delay(hundred);
     digitalWrite(thirteen, HIGH);
     digitalWrite(twelve, HIGH);
     digitalWrite(eleven, HIGH);
     digitalWrite(ten, HIGH);
     digitalWrite(nine, HIGH);
     digitalWrite(eight, HIGH);
     digitalWrite(seven, HIGH);
     digitalWrite(six, HIGH);
     digitalWrite(five, HIGH);
     delay(hundred);
     }
  }
  
//odd pinouts off and even pinouts on then the opposite
void opposite(){
  for (int i=1 ; i<20 ; i = i + 1){
    digitalWrite(five, HIGH);
    digitalWrite(six, LOW);
    digitalWrite(seven, HIGH);
    digitalWrite(eight, LOW);
    digitalWrite(nine, HIGH);
    digitalWrite(ten, LOW);
    digitalWrite(eleven, HIGH);
    digitalWrite(twelve, LOW);
    digitalWrite(thirteen, HIGH);
    delay(hundred);
    
    digitalWrite(five, LOW);
    digitalWrite(six, HIGH);
    digitalWrite(seven, LOW);
    digitalWrite(eight, HIGH);
    digitalWrite(nine, LOW);
    digitalWrite(ten, HIGH);
    digitalWrite(eleven, LOW);
    digitalWrite(twelve, HIGH);
    digitalWrite(thirteen, LOW);
    delay(hundred);
    }
  }

/*
 * I wish this was taught in first uear program with bit counters with LEDs.
 * It is a visual way to learn about bit counters. 
 * It is taught in my eletronics program but not in my programming program.
 */
void binaryCounter(){
   for (int count = 0 ; count < 300 ; count = count + 1){
    if((count % 2) > 0) { digitalWrite(thirteen, HIGH); } else { digitalWrite(thirteen, LOW); }
    if((count % 4) > 1) { digitalWrite(twelve, HIGH); } else { digitalWrite(twelve, LOW); }
    if((count % 8) > 3) { digitalWrite(eleven, HIGH); } else { digitalWrite(eleven, LOW); }
    if((count % 16) > 7) { digitalWrite(ten, HIGH); } else { digitalWrite(ten, LOW); }
    if((count % 32) > 15) { digitalWrite(nine, HIGH); } else { digitalWrite(nine, LOW); } 
    if((count % 64) > 31) { digitalWrite(eight, HIGH); } else { digitalWrite(eight, LOW); } 
    if((count % 128) > 65) { digitalWrite(seven, HIGH); } else { digitalWrite(seven, LOW); } 
    if((count % 256) > 127) { digitalWrite(six, HIGH); } else { digitalWrite(six, LOW); } 
    if((count % 512) > 255) { digitalWrite(five, HIGH); } else { digitalWrite(five, LOW); } 
    delay(hundred); 
   }
}  

// Same as before but reversed.
void reverseBinaryCounter(){
   for (int count = 0 ; count < 300 ; count = count + 1){
    if((count % 2) > 0) { digitalWrite(five, HIGH); } else { digitalWrite(five, LOW); }
    if((count % 4) > 1) { digitalWrite(six, HIGH); } else { digitalWrite(six, LOW); }
    if((count % 8) > 3) { digitalWrite(seven, HIGH); } else { digitalWrite(seven, LOW); }
    if((count % 16) > 7) { digitalWrite(eight, HIGH); } else { digitalWrite(eight, LOW); }
    if((count % 32) > 15) { digitalWrite(nine, HIGH); } else { digitalWrite(nine, LOW); } 
    if((count % 64) > 31) { digitalWrite(ten, HIGH); } else { digitalWrite(ten, LOW); } 
    if((count % 128) > 65) { digitalWrite(eleven, HIGH); } else { digitalWrite(eleven, LOW); } 
    if((count % 256) > 127) { digitalWrite(twelve, HIGH); } else { digitalWrite(twelve, LOW); } 
    if((count % 512) > 255) { digitalWrite(thirteen, HIGH); } else { digitalWrite(thirteen, LOW); } 
    delay(hundred); 
   }
}  

// Two LEDs flashing back and forth like a cop car.
void sirens(){
    for (int i=1 ; i<20 ; i = i + 1){
      digitalWrite(thirteen, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(twelve, LOW);    // turn the LED on (HIGH is the voltage level)
      delay(hundred);               // delay in ms
      digitalWrite(thirteen, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(twelve, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(hundred);               // delay in ms
      } 
  }

// Based on my LED layout - it lights up one type of color at a time
void colored(){
  for(int c = 13; c >=11; c--){
    digitalWrite(c, HIGH);
    digitalWrite(c-3, HIGH);
    digitalWrite(c-6, HIGH);
    delay(thousand); 
    digitalWrite(c, LOW);
    digitalWrite(c-3, LOW);
    digitalWrite(c-6, LOW);
  }
}

// Based on my LED layout - it lights up one type of color at a time - reversed order
void otherColored(){
  for(int c = 5; c <=7; c++){
    digitalWrite(c, HIGH);
    digitalWrite(c+3, HIGH);
    digitalWrite(c+6, HIGH);
    delay(thousand); 
    digitalWrite(c, LOW);
    digitalWrite(c+3, LOW);
    digitalWrite(c+6, LOW);
  }
}

/*
 * Basic idea for street lights - depending on how LEDs are setp.
 * This could be part of a larger program for an intersecgtion.
 */
void streetLights(){
  for(int i = 0; i< 3; i++){
    digitalWrite(thirteen, HIGH);
    digitalWrite(eleven, LOW);
    delay(thousand); 
    digitalWrite(twelve, HIGH);
    digitalWrite(thirteen, LOW);
    delay(threeHundred); 
    digitalWrite(eleven, HIGH);
    digitalWrite(twelve, LOW);
    delay(thousand);
    } 
  }

/*
 * Color coded issues.
 * Red refers to error. 
 */
void error(){
  digitalWrite(eleven, HIGH);
  digitalWrite(eight, HIGH);
  digitalWrite(five, HIGH);
  delay(twoThousand); 
  } 
   
/*
 * Color coded issues.
 * Yellow is for caution
 */
void caution(){
  digitalWrite(twelve, HIGH);
  digitalWrite(nine, HIGH);
  digitalWrite(six, HIGH);
  delay(twoThousand); 
  }
  
/*
 * Color coded issues.
 * Green for good
 */
void good(){
  digitalWrite(thirteen, HIGH);
  digitalWrite(ten, HIGH);
  digitalWrite(seven, HIGH);
  delay(twoThousand); 
  }  


/*
 * Turns all LEDS off and on
 * Variable timimng is adjusting the delays
 */
void differentFlash(int timing){
  for(int i = 0; i < 5; i++){
     digitalWrite(thirteen, HIGH);
     digitalWrite(twelve, HIGH);
     digitalWrite(eleven, HIGH);
     digitalWrite(ten, HIGH);
     digitalWrite(nine, HIGH);
     digitalWrite(eight, HIGH);
     digitalWrite(seven, HIGH);
     digitalWrite(six, HIGH);
     digitalWrite(five, HIGH);
     delay(timing);
     digitalWrite(thirteen, LOW);
     digitalWrite(twelve, LOW);
     digitalWrite(eleven, LOW);
     digitalWrite(ten, LOW);
     digitalWrite(nine, LOW);
     digitalWrite(eight, LOW);
     digitalWrite(seven, LOW);
     digitalWrite(six, LOW);
     digitalWrite(five, LOW);
     delay(timing);
     }
  }  
  
/*
 * This happens at the end with turning all the LEDs off. 
 * You do not want to continue on random LEDs on
 */
void clearing(){
   for (int i = 0; i < numLeds; i++) {
      pinMode(ledPins[i], OUTPUT);
      digitalWrite(ledPins[i], LOW);
   }
   Serial.println("All Flashing Done...\n");
   }
  
/*
 * This happens at the all choice options because I do not want the print line.
 * This happens at the end with turning all the LEDs off. 
 * You do not want to continue on random LEDs on
 */
void otherClearing(){
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // Make sure LEDs are off initially
  }
  }
