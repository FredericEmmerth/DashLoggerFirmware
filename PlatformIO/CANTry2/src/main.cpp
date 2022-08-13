// Demo for Teensy 4.x CAN1, CAN2 and CAN3

// CRX3 (#30), CTX3 (#31)

//-----------------------------------------------------------------
// CAN3 is configured in CAN2.0B.
//-----------------------------------------------------------------

#ifndef __IMXRT1062__
  #error "This sketch should be compiled for Teensy 4.x"
#endif

//-----------------------------------------------------------------

#include <ACAN_T4.h>

//-----------------------------------------------------------------

void setup () {
  pinMode (LED_BUILTIN, OUTPUT) ;
  Serial.begin (9600) ;
  while (!Serial) {
    delay (50) ;
    digitalWrite (LED_BUILTIN, !digitalRead (LED_BUILTIN)) ;
  }
  Serial.println ("CAN1-CAN2-CAN3 test") ;
  ACAN_T4_Settings settings (500 * 1000) ;
  Serial.print ("CAN Root Clock frequency: ") ;
  Serial.print (getCANRootClockFrequency ()) ;
  Serial.println (" Hz") ;
  Serial.print ("CAN Root Clock divisor: ") ;
  Serial.println (getCANRootClockDivisor ()) ;
  Serial.print ("Bitrate prescaler: ") ;
  Serial.println (settings.mBitRatePrescaler) ;
  Serial.print ("Propagation Segment: ") ;
  Serial.println (settings.mPropagationSegment) ;
  Serial.print ("Phase segment 1: ") ;
  Serial.println (settings.mPhaseSegment1) ;
  Serial.print ("Phase segment 2: ") ;
  Serial.println (settings.mPhaseSegment2) ;
  Serial.print ("RJW: ") ;
  Serial.println (settings.mRJW) ;
  Serial.print ("Triple Sampling: ") ;
  Serial.println (settings.mTripleSampling ? "yes" : "no") ;
  Serial.print ("Actual bitrate: ") ;
  Serial.print (settings.actualBitRate ()) ;
  Serial.println (" bit/s") ;
  Serial.print ("Exact bitrate ? ") ;
  Serial.println (settings.exactBitRate () ? "yes" : "no") ;
  Serial.print ("Distance from wished bitrate: ") ;
  Serial.print (settings.ppmFromWishedBitRate ()) ;
  Serial.println (" ppm") ;
  Serial.print ("Sample point: ") ;
  Serial.print (settings.samplePointFromBitStart ()) ;
  Serial.println ("%") ;

  uint32_t errorCode = ACAN_T4::can3.begin (settings) ;
  if (0 == errorCode) {
    Serial.println ("can3 ok") ;
  }else{
    Serial.print ("Error can3: 0x") ;
    Serial.println (errorCode, HEX) ;
  }
  delay (2) ;
}

//-----------------------------------------------------------------

void loop () {
  CANMessage message ;
//--- CAN3 receive
  if (ACAN_T4::can3.receive (message)) {
    Serial.println("Message Recieved");
  }
}