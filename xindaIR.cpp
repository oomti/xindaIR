/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "xindaIR.h"

volatile unsigned char timeWriteIndicator = 0;
volatile unsigned long timeArray[stackArraySize];

xindaIR::xindaIR(unsigned char pin)
{
  pinMode(pin, INPUT);
  _pin = pin ;
}

void xindaIR::readIRstack() {
  while (timeWriteIndicator!=(_timeReadIndicator)) {   
    _timeDifference=timeArray[(_timeReadIndicator+1)%stackArraySize]-timeArray[_timeReadIndicator];
    
    if (abs(_timeDifference)<7000) {
        (_timeDecoder(_timeDifference));            
    } 

    _timeReadIndicator=(_timeReadIndicator+1)%stackArraySize;
  }
}

byte xindaIR::_timeDecoder(unsigned int sigLength) {
  if ((minShortSig<sigLength)&&(maxShortSig>sigLength)) {

     _msg=_msg<<1;
     return 0;
  }
  if ((minLongSig<sigLength)&&(maxLongSig>sigLength)) {

     _msg=_msg<<1;
     _msg++;
     if (((bitCheck&_msg)==bitCheck)&&((zeroCheck&~_msg)==zeroCheck)) {
          Serial.println(_msg,HEX);
          isButtonPressed = true;
     }
     return 1;
  }
  if ((minButtonPress<sigLength)&&(maxButtonPress>sigLength)) {
    
     return 2;
     isRepeat++;
  }
  if ((minSigStart<sigLength)&&(maxSigStart>sigLength)) {

     _msg=0;
     isRepeat=0;
     return 3;
  }
  return 7;
}

void xindaIR::xindaIR_Setup() {
  attachInterrupt(digitalPinToInterrupt(_pin), interruptForOpticalSignal, RISING);
}

void interruptForOpticalSignal() {
  timeWriteIndicator=(timeWriteIndicator+1)%stackArraySize;
  timeArray[timeWriteIndicator]=micros();
  
}

char xindaIR::getIRmsg() {
  switch (_msg) {
    case button_UP:
      return 88;
    break;
    
    case button_DOWN:
      return 22;
    break;
    
    case button_LEFT:
      return 44;
    break;
    
    case button_RIGHT:
      return 66;
    break;
    
    case button_OK:
      return 55;
    break;
    
    case button_0:
      return 0;
    break;
    
    case button_1:
      return 1;
    break;
    
    case button_2:
      return 2;
    break;
    
    case button_3:
      return 3;
    break;
    
    case button_4:
      return 4;
    break;
    
    case button_5:
      return 5;
    break;
    
    case button_6:
      return 6;
    break;
    
    case button_7:
      return 7;
    break;
    
    case button_8:
      return 8;
    break;
    
    case button_9:
      return 9;
    break;
    
    case button_STAR:
      return 11;
    break;
    
    case button_HASH:
      return 33;
    break;
    
    default:
      return 99;
    break; 
  }
    
}






