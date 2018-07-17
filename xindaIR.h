
/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef xindaIR_h
#define xindaIR_h

#include "Arduino.h"

#define button_UP 0xFF629D 
#define button_DOWN 0xFFA857
#define button_LEFT 0xFF22DD
#define button_RIGHT 0xFFC23D
#define button_OK 0xFF02FD
#define button_0 0xFF4AB5
#define button_1 0xFF6897
#define button_2 0xFF9867
#define button_3 0xFFB04F
#define button_4 0xFF30CF
#define button_5 0xFF18E7
#define button_6 0xFF7A85
#define button_7 0xFF10EF
#define button_8 0xFF38C7
#define button_9 0xFF5AA5
#define button_STAR 0xFF42BD
#define button_HASH 0xFF52AD

#define bitCheck 0xFF0005
#define zeroCheck 0x000500

#define IRdigitalInput 3

#define minShortSig 800
#define maxShortSig 1500
#define minLongSig 1300
#define maxLongSig 2400
#define minButtonPress 2400
#define maxButtonPress 3000
#define minSigStart 4000
#define maxSigStart 5500
#define stackArraySize 12

#define sigStart 3
#define buttonPress 2
#define longSig 1
#define shortSig 0
#define failedSig 7
/*
extern volatile unsigned char timeWriteIndicator = 0;
extern volatile unsigned long timeArray[stackArraySize];
*/void interruptForOpticalSignal();



class xindaIR 
{
  public:
    xindaIR(unsigned char pin);
    void xindaIR_Setup();
    void readIRstack();
    char getIRmsg();
    
    bool isButtonPressed = 0 ;
    char isRepeat = 0 ;
    
    
    
  private:

    byte _timeDecoder(unsigned int sigLength);
    
    unsigned char _timeReadIndicator = 0;
    
    unsigned int _timeDifference = 0;

    unsigned long _msg = 0 ;
     
    
    unsigned char _pin;

};



#endif
