/*
 * This sets up the ports and the communication rate.
 * This only happens once, so the main program can use it.
 * Serial Print Line tests to see if the output wors. If you do not see it, setting are wrong for the monitor.
 */
void startSetup(){  
  //initialize serial:
  Serial.begin(9600);
  Serial.println("Header file is attached...\nSetup is starting...");
  
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
  
}

/*  
 *   While this could be re-usuable, I only use it once in my program.
 *   This is to prove my output works by turning on LEDs.
 */
void quickFlash(){
  for(int i=13; i>=5; i--)
    {
      digitalWrite(i,HIGH);
      delay(50);
      digitalWrite(i,LOW);
      delay(50);
    }
  Serial.println("Setup is complete...\nWelcome...\nInput characters...\n");
}
