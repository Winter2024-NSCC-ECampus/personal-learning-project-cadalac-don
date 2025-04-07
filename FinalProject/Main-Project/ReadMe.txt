Install program onto the Arduino.

You can use the serial monitor in the Arduino IDE to keep track of the print lines and sent lines to the Arduino. 

Otherwise, you can use a RS232 attachment and use PuTTy or equivalent.

Personal preference for Putty setup:
- Connection type to "Serial" at the programmed baud speed rate. In my example, it is 9600. Typically, it will default to 9600.
	Adjust the COM1 to the correct COM Port. If you are unsure, you can go to the Arduino IDE to find out what COM Ports are active.
- If you adjust the program to take input, this step is important to do. Otherwise, you can skip this step.
	Click "Terminal" and check the box for "Implicit CR in every LF". Also, "Force on" the "Local echo". 
- Adjust "The Function keys and keypad" under "Keyboard" to Linux. Otherwise, you may get a strange output.
- Click on "Open" to start the program. 

Other files are connect to the main INO File for a working program.