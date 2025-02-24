/*
 * This is where most of the flashing LEDs happen.
 * It starts with a print statement with startLED() and goes on from there.
 */
void startLed(){
  Serial.println("Flashing now...");
}

//Flashes two LEDs
void flashing(){
    for (int i=1 ; i<20 ; i = i + 1){
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      delay(100);
    }
  }

//Turns on random LED and then turns it off
void randomLED(){
      int randNumber = random(5, 14);
      Serial.println(randNumber);
      digitalWrite(randNumber, HIGH);
      delay(1500);
    }

//Turns on random LED and then turns it off
void manyRandomLED(){
  
  for(int i = 0; i< 10; i++){
      int randNumber = random(5, 14);
      Serial.println(randNumber);
      digitalWrite(randNumber, HIGH);
      delay(1000);
      digitalWrite(randNumber, LOW);
  }
}

//This is a common LED concept
void chasingLED(){
  for(int j=0; j<20; j++){
    for(int i=5; i<=13; i++)
    {
      digitalWrite(i,HIGH);
      delay(50);
      digitalWrite(i,LOW);
      delay(50);
    }
  }
} 

//This is a common LED concept
void reverseChasingLED(){
  for(int j=0; j<20; j++){
    for(int i=13; i>=5; i--)
    {
      digitalWrite(i,HIGH);
      delay(50);
      digitalWrite(i,LOW);
      delay(50);
    }
  }
} 

//turns all LEDS off and on
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
  }
  
//odd pinouts off and even pinouts on then the opposite
void opposite(){
  for (int i=1 ; i<20 ; i = i + 1){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(100);
    
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(100);
    }
  }

/*
 * I wish this was taught in first uear program with bit counters with LEDs.
 * It is a visual way to learn about bit counters. 
 * It is taught in my eletronics program but not in my programming program.
 */
void binaryCounter(){
   for (int count = 0 ; count < 300 ; count = count + 1){
    if((count % 2) > 0) { digitalWrite(13, HIGH); } else { digitalWrite(13, LOW); }
    if((count % 4) > 1) { digitalWrite(12, HIGH); } else { digitalWrite(12, LOW); }
    if((count % 8) > 3) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); }
    if((count % 16) > 7) { digitalWrite(10, HIGH); } else { digitalWrite(10, LOW); }
    if((count % 32) > 15) { digitalWrite(9, HIGH); } else { digitalWrite(9, LOW); } 
    if((count % 64) > 31) { digitalWrite(8, HIGH); } else { digitalWrite(8, LOW); } 
    if((count % 128) > 65) { digitalWrite(7, HIGH); } else { digitalWrite(7, LOW); } 
    if((count % 256) > 127) { digitalWrite(6, HIGH); } else { digitalWrite(6, LOW); } 
    if((count % 512) > 255) { digitalWrite(5, HIGH); } else { digitalWrite(5, LOW); } 
    delay(100); 
   }
}  

// Same as before but reversed.
void reverseBinaryCounter(){
   for (int count = 0 ; count < 300 ; count = count + 1){
    if((count % 2) > 0) { digitalWrite(5, HIGH); } else { digitalWrite(5, LOW); }
    if((count % 4) > 1) { digitalWrite(6, HIGH); } else { digitalWrite(6, LOW); }
    if((count % 8) > 3) { digitalWrite(7, HIGH); } else { digitalWrite(7, LOW); }
    if((count % 16) > 7) { digitalWrite(8, HIGH); } else { digitalWrite(8, LOW); }
    if((count % 32) > 15) { digitalWrite(9, HIGH); } else { digitalWrite(9, LOW); } 
    if((count % 64) > 31) { digitalWrite(10, HIGH); } else { digitalWrite(10, LOW); } 
    if((count % 128) > 65) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); } 
    if((count % 256) > 127) { digitalWrite(12, HIGH); } else { digitalWrite(12, LOW); } 
    if((count % 512) > 255) { digitalWrite(13, HIGH); } else { digitalWrite(13, LOW); } 
    delay(100); 
   }
}  

// Two LEDs flashing back and forth like a cop car.
void sirens(){
    for (int i=1 ; i<20 ; i = i + 1){
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(12, LOW);    // turn the LED on (HIGH is the voltage level)
      delay(100);               // delay in ms
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // delay in ms
      } 
  }

// Based on my LED layout - it lights up one type of color at a time
void colored(){
  for(int c = 13; c >=11; c--){
    digitalWrite(c, HIGH);
    digitalWrite(c-3, HIGH);
    digitalWrite(c-6, HIGH);
    delay(1000); 
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
    delay(1000); 
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
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    delay(1000); 
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(300); 
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delay(1000);
    } 
  }

/*
 * Color coded issues.
 * Red refers to error. 
 */
void error(){
  digitalWrite(11, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(5, HIGH);
  delay(2000); 
  } 
   
/*
 * Color coded issues.
 * Yellow is for caution
 */
void caution(){
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  delay(2000); 
  }
  
/*
 * Color coded issues.
 * Green for good
 */
void good(){
  digitalWrite(13, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(7, HIGH);
  delay(2000); 
  }  


/*
 * Turns all LEDS off and on
 * Variable timimng is adjusting the delays
 */
void differentFlash(int timing){
  for(int i = 0; i < 5; i++){
     digitalWrite(13, HIGH);
     digitalWrite(12, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(10, HIGH);
     digitalWrite(9, HIGH);
     digitalWrite(8, HIGH);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     delay(timing);
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(9, LOW);
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     delay(timing);
     }
  }  
  
/*
 * This happens at the end with turning all the LEDs off. 
 * You do not want to continue on random LEDs on
 */
void clearing(){
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
  
/*
 * This happens at the all choice options because I do not want the print line.
 * This happens at the end with turning all the LEDs off. 
 * You do not want to continue on random LEDs on
 */
void otherClearing(){
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
   digitalWrite(10, LOW);
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);
   digitalWrite(7, LOW);
   digitalWrite(6, LOW);
   digitalWrite(5, LOW);
  }
