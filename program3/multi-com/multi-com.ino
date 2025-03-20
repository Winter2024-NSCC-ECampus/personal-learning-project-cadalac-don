extern "C" int addNumbers(int a, int b); 
#include "cpp.cpp"

cpp CPP;

int sensorPin = A0;
int sensorValue = 0;
int num1 = 5;
int num2 = 6;
int num3; 

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 1; // analog pin connected to X output
const int Y_pin = 2; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_pin));
  Serial.println(" | ");
  delay(200);
}

void voltageDivider(){
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(13, HIGH);
  Serial.println(sensorValue);
  // stop the program for <sensorValue> milliseconds:
  delay(100);
  // turn the ledPin off:
  digitalWrite(13, LOW);
  Serial.println(sensorValue);
  // stop the program for for <sensorValue> milliseconds:
  delay(100); 
  //gettingNumbers();
  }
  
void gettingNumbers(){
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
  CPP.datafile();
}
