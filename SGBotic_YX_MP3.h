/*************************************************** 
  This is a library for our MP3 Module (DEV-02731)
  http://www.sgbotic.com/index.php?dispatch=products.view&product_id=2731
  
  Written by KC for SGBotic.com
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include "Arduino.h"
#ifdef __AVR__
  #include <SoftwareSerial.h>
#endif

//#define YX_MP3_DEBUG 

//control commands
#define YX_MP3_NEXT 0x01
#define YX_MP3_PREV 0x02
#define YX_MP3_PLAYTRACK 0x03
#define YX_MP3_INCVOLUME 0x04
#define YX_MP3_DECVOLUME 0x05
#define YX_MP3_SETVOLUME 0x06
#define YX_MP3_REPEATTRACK 0x08
#define YX_MP3_SETDEVICE 0x09
#define YX_MP3_SLEEP 0x0A
#define YX_MP3_WAKE 0x0B
#define YX_MP3_RESET 0x0C
#define YX_MP3_PLAY 0x0D
#define YX_MP3_PAUSE 0x0E
#define YX_MP3_PLAYTRACKFOLDER 0x0F
#define YX_MP3_STOP 0x16
#define YX_MP3_REPEATFOLDER 0x17
#define YX_MP3_RANDOMPLAY 0x18
#define YX_MP3_REPEATCURRENT 0x19
#define YX_MP3_SETDAC 0x1A
//Query commands
#define YX_MP3_GETDEVICE 0x3F
#define YX_MP3_ACKERROR 0x40
#define YX_MP3_ACKFEEDBACK 0x41
#define YX_MP3_GETSTATUS 0x42
#define YX_MP3_GETVOLUME 0x43
#define YX_MP3_GETEQ 0x44
#define YX_MP3_GETTOTALTRACKUSBROOT 0x47
#define YX_MP3_GETTOTALTRACKSDROOT 0x48
#define YX_MP3_GETTRACKUSB 0x4B
#define YX_MP3_GETTRACKSD 0x4C
#define YX_MP3_GETTOTALTRACKFOLDER 0x4E
#define YX_MP3_GETTOTALFOLDER 0x4F

#define YX_MP3_STARTCODE 0x7E
#define YX_MP3_ENDCODE 0xEF
#define YX_MP3_VERSION 0xFF
#define YX_MP3_PACKETSIZE 0x06

class SGBotic_YX_MP3 {
 public:
 
#ifdef __AVR__
  SGBotic_YX_MP3(SoftwareSerial *);
#endif
  SGBotic_YX_MP3(HardwareSerial *);

    void begin(uint16_t baud);
    void writePacket(uint8_t cmd, uint8_t feedback, uint16_t packet);
    void setVolume(uint16_t volume);
    void play();
    void play(uint16_t track);
    void play(uint8_t track, uint8_t folder);
    void repeat(uint16_t track);
    void repeatFolder(uint16_t track);
    void reset();
    void pause();
    void next();
    void prev();
    void stop();
    void sleep();

 private: 
    
  Stream *mySerial;
   
#ifdef __AVR__
  SoftwareSerial *swSerial;
#endif
  HardwareSerial *hwSerial;
  
};
