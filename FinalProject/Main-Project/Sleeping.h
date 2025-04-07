/*
 * I tried to mix sleep with other functionalities but all had issues.
 * I tried using the watchdog but I was only getting issues. It was not per my requirements, so I did not use it.
 * Variables before heading to sleep.
 */
#include <LowPower.h>

int forty = 40;

/* 
 *  I need a delay in order to print everything out in the buffer.
 *  Enter sleep mode for 4 seconds.
 */
void sleepingTimeOne(){
    Serial.println("Going to sleep...");
    delay(hundred);
    
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
    Serial.println("Woke up from sleep!\n");
    }

/* 
 *  I need a delay in order to print everything out in the buffer.
 *  Enter sleep mode for 8 seconds.
 *  My compiler does not like any double digit sleep duration even though the microchip is capable.
 *  The sleep was ont part of my requirements.
 */    
void sleepingTimeTwo(){
    Serial.println("Going to sleep...");
    delay(hundred);
    LowPower.powerDown(SLEEP_8S , ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S , ADC_OFF, BOD_OFF);
    Serial.println("Woke up after 16 seconds!\n");
    }
    
  
