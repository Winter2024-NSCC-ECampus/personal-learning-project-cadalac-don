void overallData(double counter, double count, int dataInfo){
   double badData = (counter/count)*100;
   double goodData = 100.00-badData;

   Serial.print("Data Called ");
   Serial.print(dataInfo);
   Serial.println(" time(s)!");
   
   Serial.print("Bad Input Percentage: ");
   Serial.print(badData);
   Serial.println("%");

   Serial.print("Good Input Percentage: ");
   Serial.print(goodData);
   Serial.println("%\n");
}

/*
 * LEDs of a certain color
 * 7-Segment display
 * Do math option. Wait for input, do calculations and output.
 * Voltage divider
 * Else if into switch statements
 */
