/* 
 * Basic Setup for digital output.
 * We are setting RX and TX at a baud rate of 9600.
 * Test println to see if it works before going to main code.
 */
void setup() 
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup Complete");
}

/* 
 *  There are a few basic LED tests.
 *  also, this includes a few print out statements.
 *  Delay is in ms or 0.001 second - so delay(1000) is 1 second.
 */
void loop() 
{
  
  Serial.println("Test 0");
  //Turns on some lights then turns them off
  for (int i=1 ; i<20 ; i = i + 1){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(100);
    }
    
  Serial.println("Test 1");
  //Alternating flashing lights - fast paced
  for (int i=1 ; i<20 ; i = i + 1){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, LOW);    // turn the LED on (HIGH is the voltage level)
    delay(100);               // delay in ms
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // delay in ms
    } 

  Serial.println("Test 2");
  //Alternating flashing lights - slow paced
  for (int j=1 ; j<5 ; j = j + 1){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, LOW);    // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    }
    
  Serial.println("Test 3");
  //Binary Counter with LEDs
  for (int count = 0 ; count < 100 ; count = count + 1){
    if((count % 2) > 0) { digitalWrite(9, HIGH); } else { digitalWrite(9, LOW); }
    if((count % 4) > 1) { digitalWrite(10, HIGH); } else { digitalWrite(10, LOW); }
    if((count % 8) > 3) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); }
    if((count % 16) > 7) { digitalWrite(12, HIGH); } else { digitalWrite(12, LOW); }
    if((count % 32) > 15) { digitalWrite(13, HIGH); } else { digitalWrite(13, LOW); } 
    delay(100); 
    }
    
   Serial.println("Test 4");
   //Reverse Binary Counter with LEDs
   for (int count = 0 ; count < 100 ; count = count + 1){
    if((count % 2) > 0) { digitalWrite(13, HIGH); } else { digitalWrite(13, LOW); }
    if((count % 4) > 1) { digitalWrite(12, HIGH); } else { digitalWrite(12, LOW); }
    if((count % 8) > 3) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); }
    if((count % 16) > 7) { digitalWrite(10, HIGH); } else { digitalWrite(10, LOW); }
    if((count % 32) > 15) { digitalWrite(9, HIGH); } else { digitalWrite(9, LOW); } 
    delay(100); 
    }
    
  Serial.println("Test 5");
  //odd pinouts off and even pinouts on then the opposite
  for (int i=1 ; i<20 ; i = i + 1){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(100);
    }
}
