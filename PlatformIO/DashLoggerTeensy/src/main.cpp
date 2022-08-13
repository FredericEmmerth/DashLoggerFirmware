// Test Teensy SDIO with write busy in a data logger demo.
//
// The driver writes to the uSDHC controller's FIFO then returns
// while the controller writes the data to the SD.  The first sector
// puts the controller in write mode and takes about 11 usec on a
// Teensy 4.1. About 5 usec is required to write a sector when the
// controller is in write mode.

#include "SdFat.h"
#include "RingBuf.h"
#include <ACAN_T4.h>

// Use Teensy SDIO
#define SD_CONFIG  SdioConfig(FIFO_SDIO)

// Interval between points for 15 ksps.
#define LOG_INTERVAL_USEC 66

// ############# Loop Time / Data Rate Calculation #############################
// The maximum Message Frequency on the CAN Bus is 15kHz
// The Message Buffer Depth of the CAN Hardware is 6
// Therefore, it has to be emptied at a Frequency of 15kHz / 6 = 2.5kHz
// A Message Line in the ASC CANoe Format has about 100 Characters (bytes)
// Up to three CAN Channels have to be logged.
// This results in a Data Rate of : 
// 2500 BufferReads/s * 6 Messages * 100 Bytes * 3 Channels = 4,5 MB/s
// This Data Rate is achievable using the Teensy internal SD in FIFO SDIO Mode.

/* Size to log at 4,5 MB/s for 30min ~ 8,1GB */
#define LOG_FILE_SIZE (uint64_t)4500000 * 1800

/* Use 256 KB for Buffering.
 This means Messages can be buffered for 256K / 4,5 MB/s ~ 57ms */
#define RING_BUF_CAPACITY 256000
#define LOG_FILENAME "GFRLog.asc"

SdFs sd;
FsFile file;

// RingBuf for File type FsFile.
RingBuf<FsFile, RING_BUF_CAPACITY> rb;

void logData() {
  // Initialize the SD.
  if (!sd.begin(SD_CONFIG)) {
    sd.initErrorHalt(&Serial);
  }
  // Open or create file - truncate existing file.
  if (!file.open(LOG_FILENAME, O_RDWR | O_CREAT | O_TRUNC)) {
    Serial.println("open failed\n");
    return;
  }
  // File must be pre-allocated to avoid huge
  // delays searching for free clusters.
  if (!file.preAllocate(LOG_FILE_SIZE)) {
     Serial.println("preAllocate failed\n");
     file.close();
     return;
  }
  // initialize the RingBuf.
  rb.begin(&file);
  Serial.println("Type any character to stop");

  // Max RingBuf used bytes. Useful to understand RingBuf overrun.
  size_t maxUsed = 0;

  // Min spare micros in loop.
  int32_t minSpareMicros = INT32_MAX;

  // Start time.
  uint32_t logTime = micros();
  Serial.println(logTime);
  // Log data until Serial input or file full.
  while (!Serial.available()) {
    // Amount of data in ringBuf.
    size_t n = rb.bytesUsed();
    if ((n + file.curPosition()) > (LOG_FILE_SIZE - 20)) {
      Serial.println("File full - quitting.");
      break;
    }
    if (n > maxUsed) {
      maxUsed = n;
    }
    if (n >= 512 && !file.isBusy()) {
      // Not busy only allows one sector before possible busy wait.
      // Write one sector from RingBuf to file.
      if (512 != rb.writeOut(512)) {
        Serial.println("writeOut failed");
        break;
      }
    }
    // Time for next point.
    logTime += LOG_INTERVAL_USEC;
    Serial.println(micros());
    int32_t spareMicros = logTime - micros();
    if (spareMicros < minSpareMicros) {
      minSpareMicros = spareMicros;
    }
    if (spareMicros <= 0) {
      Serial.print("Rate too fast ");
      Serial.println(spareMicros);
      break;
    }
    // Wait until time to log data.
    while (micros() < logTime) {}

    // Print adc into RingBuf.
    CANMessage message ;
    int counter = 0;
    //--- CAN3 receive
    while(ACAN_T4::can3.receive(message) != false) {
      rb.print(message.id,HEX);
      rb.print(",");
      rb.print(millis());
      rb.print(",");
      rb.print(message.data64,HEX);
      rb.println();
      counter++;
    }

    Serial.print("MsgCnt:");
    Serial.println(counter);
    

    if (rb.getWriteError()) {
      // Error caused by too few free bytes in RingBuf.
      Serial.println("WriteError");
      break;
    }
  }
  // Write any RingBuf data to file.
  rb.sync();
  file.truncate();
  file.rewind();
  // Print first twenty lines of file.
  for (uint8_t n = 0; n < 20 && file.available();) {
    int c = file.read();
    if (c < 0) {
      break;
    }
    Serial.write(c);
    if (c == '\n') n++;
  }
  Serial.print("fileSize: ");
  Serial.println((uint32_t)file.fileSize());
  Serial.print("maxBytesUsed: ");
  Serial.println(maxUsed);
  Serial.print("minSpareMicros: ");
  Serial.println(minSpareMicros);
  file.close();
}

void clearSerialInput() {
  for (uint32_t m = micros(); micros() - m < 10000;) {
    if (Serial.read() >= 0) {
      m = micros();
    }
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  // Go faster or log more channels.  ADC quality will suffer.
  // analogReadAveraging(1);
  
  Serial.println ("CAN3 Init") ;
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

void loop() {
  clearSerialInput();
  logData();

  while(1);
}
