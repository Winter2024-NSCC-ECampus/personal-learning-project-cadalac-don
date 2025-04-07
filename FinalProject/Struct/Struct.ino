// Define a struct to hold the numbers
struct Numbers {
  //Minimum value: -2,147,483,648
  //Maximum value: 2,147,483,647
  long total;
  long newNumber;
};

Numbers myNumbers;  // Create an instance of the struct

void clearSerialBuffer() {
  // Discard all characters in the buffer
  while (Serial.available() > 0) {
    Serial.read();  // Read and discard characters
  }
}

void setup() {
  // Start Serial communication
  Serial.begin(9600);

  // Initialize the total to 0
  myNumbers.total = 0;

  Serial.println("Starting...\n\nEnter a number to add to the total...");
}

void loop() {
  /*
  If you try to store a number larger than the maximum value (32,767) or smaller than the minimum value (-32,768), the value will wrap around or overflow. 
  This means that if you exceed the maximum range, it will go back to the minimum value, and vice versa.
  For example, if you store a value larger than 2,147,483,647 in a long, it will wrap around to the negative side.
  */
  
  // Check if there is user input
  if (Serial.available() > 0) {
    // Read the input number from the Serial monitor
    myNumbers.newNumber = Serial.parseInt();  // Read an integer

    // Add the new number to the total
    myNumbers.total += myNumbers.newNumber;

    // Print the updated total
    Serial.print("New number added: ");
    Serial.println(myNumbers.newNumber);
    Serial.print("Updated total: ");
    Serial.println(myNumbers.total);

    // Clean the serial buffer to discard any leftover characters
    clearSerialBuffer();
    
    // Ask the user to enter another number
    Serial.println("\nEnter another number to add to the total...");
  }
}
