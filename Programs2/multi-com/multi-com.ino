extern "C" int addNumbers(int a, int b); 
#include "cpp.cpp"

int num1 = 5;
int num2 = 6;
int num3; 

void setup() {
  Serial.begin(9600);
  while(!Serial);
  assemblySetup();
  Serial.println("");
}


void loop() {  
  Serial.println("Enter First Number: ");
  while(!Serial.available()){
  }
  num1 = Serial.parseInt();
  Serial.println(num1);
  Serial.end();
  Serial.begin(9600); 
  
  Serial.println("Enter Second Number: ");
  while(!Serial.available()){
  }
  num2 = Serial.parseInt();
  Serial.println(num2); 
  Serial.end();
  Serial.begin(9600);
  
  assemblySetup();
  Serial.println("");
}

void assemblySetup(){
  num3 = addNumbers(num1, num2);
  Serial.print("Sum of ");
  Serial.print(num1);
  Serial.print(" and ");
  Serial.print(num2);
  Serial.print(" is ");
  Serial.println(num3);

  num1++;
  num2++;
  num3 = addNumbers(num1, num2);
  Serial.print("Sum of ");
  Serial.print(num1);
  Serial.print(" and ");
  Serial.print(num2);
  Serial.print(" is ");
  Serial.println(num3);
  }  
