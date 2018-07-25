/*************************************************** 
  This is an example sketch for our MP3 Module
  http://www.sgbotic.com/index.php?dispatch=products.view&product_id=2731
 
  Written by KC for SGBotic.  
  BSD license, all text above must be included in any redistribution

=====================================================


 Wiring:
 
 MP3 module:          Arduino Mega
 ===================================
 Rx   ------> Pin 14 (Tx3)
 Tx   ------> Pin 15 (Rx3)
 Vcc  ------> 3.3V or 5V
 GND  ------> GND
 
 ****************************************************/
 
#include <SGBotic_YX_MP3.h>
#include <SoftwareSerial.h>

SGBotic_YX_MP3 mp3 = SGBotic_YX_MP3(&Serial3);

void setup() {
  Serial.begin(9600);
  Serial.println("SGBotic Mini MP3 Module test sketch using Mega"); //Support Mega, Micro, Leonardo, etc
  mp3.begin(9600);
  delay(1000);      //MP3 module initialization
}

void loop() {
  mp3.setVolume(30);   // value: 0 to 30
  delay(100);          //short delay is required for MP3 player to execute command
  mp3.play(4, 1);    //play track 4 in folder "01". Folder name in two digit format: 01, 02, 03 ...
  delay(5000); 
  mp3.play(1, 2);    //play track 1 in folder "02". Folder name in two digit format: 01, 02, 03 ...
  delay(5000); 
  
  
  //mp3.repeatFolder(1);  //repeat all tracks in folder 01
  //mp3.reset();
  //mp3.pause();
  //mp3.stop()
  //mp3.sleep();
  //mp3.next();       // next track
  //mp3.prev();       // previous track
}
