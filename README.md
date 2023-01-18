# xindaIR
This is a home project library for reading the xinda Infrared Transmitter on arduino with a photodetector.

The code is a result of manual reverse engineering the Xinda Infrared signal pattern.

This includes 
 
 - setting up an environment to record signals against time
 - identify signal patterns - encoded binary in signal length and special signals indicated with different signal length
 - manually encoding the binary code

When used with an infrared detector, the function would return a value according to the button pressed


public functions and variables:

  class constructor:
  
    xindaIR(unsigned char pin);
    
  to initialize in the setup:
  
    void xindaIR_Setup();
    
  call frequently to read from the FIFO stack to:
  
    void readIRstack();
    
  returns a value according to what button is pressed:
  
    char getIRmsg();
    
  this value is true until button value is not read:
  
    bool isButtonPressed ;
    
  a counter for how long the last button(signal cycles) have been pressed for:
  
    char isRepeat = 0 ;
