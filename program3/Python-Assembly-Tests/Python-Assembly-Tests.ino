extern "C" int addNumbers(int a, int b); 

/*
 * https://www.linuxjournal.com/article/8497
 * https://docs.python.org/3/extending/extending.html#a-simple-example
 */

#include "python.py";

int num1 = 5;
int num2 = 6;
int num3; 

void setup() {
  Serial.begin(9600);
  assemblySetup();
}


void loop() {
  return;
}

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
  }  
