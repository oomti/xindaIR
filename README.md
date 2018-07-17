# xindaIR
This is a home project library for reading the xinda Infrared Transmitter on arduino


public functions and variables:
  class constructor:
  
    xindaIR(unsigned char pin);
    
  to initialize in the setup
  
    void xindaIR_Setup();
    
  call frequently to read from the FIFO stack
  
    void readIRstack();
    
  returns a value according to what button is pressed
  
    char getIRmsg();
    
  this value is true until button value is not read
  
    bool isButtonPressed ;
    
  a counter for how long the last button(signal cycles) have been pressed for
  
    char isRepeat = 0 ;
