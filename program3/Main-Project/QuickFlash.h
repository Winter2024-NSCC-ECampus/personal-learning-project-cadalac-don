int five = 5;
int six = 6;
int seven = 7;
int eight = 8;
int nine = 9;
int ten = 10;
int eleven = 11;
int twelve = 12;
int thirteen = 13;
int SerialCom = 9600;

/*
 * This sets up the ports and the communication rate.
 * This only happens once, so the main program can use it.
 * Serial Print Line tests to see if the output wors. If you do not see it, setting are wrong for the monitor.
 */
void startSetup(){  
  //initialize serial:
  Serial.begin(SerialCom);
  Serial.println("Header file is attached...\nSetup is starting...");
  
  //pin setup
  pinMode(thirteen, OUTPUT);
  pinMode(twelve, OUTPUT);
  pinMode(eleven, OUTPUT);
  pinMode(ten, OUTPUT);
  pinMode(nine, OUTPUT);
  pinMode(eight, OUTPUT);
  pinMode(seven, OUTPUT);
  pinMode(six, OUTPUT);
  pinMode(five, OUTPUT);
}

/*  
 *   While this could be re-usuable, I only use it once in my program.
 *   This is to prove my output works by turning on LEDs.
 */
void quickFlash(){
  for(int i=13; i>=5; i--){
      digitalWrite(i,HIGH);
      delay(50);
      digitalWrite(i,LOW);
      delay(50);
  }
  Serial.println("Setup is complete...\nWelcome...\nInput characters...\n");
}
