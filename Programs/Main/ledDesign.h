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
      digitalWrite(randNumber, LOW);
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
