/*
* Set the LED according to incoming OSC control
*/
#include <OSCBundle.h>
#include <OSCBoards.h>

#ifdef BOARD_HAS_USB_SERIAL
#include <SLIPEncodedUSBSerial.h>
//SLIPEncodedUSBSerial SLIPSerial( thisBoardsSerialUSB );
 SLIPEncodedSerial SLIPSerial(Serial);
#else
#include <SLIPEncodedSerial.h>
 SLIPEncodedSerial SLIPSerial(Serial);
#endif

#define GREENPIN 11

void LEDcontrol(OSCMessage &msg, int addressOffset)
{
    SLIPSerial.print("Got a message");
    if (msg.isInt(0))
    {
        analogWrite(GREENPIN,90);
    }
    else if(msg.isString(0))
    {
         int length=msg.getDataLength(0);
         if(length<5)
         {
           char str[length];
           msg.getString(0,str,length);
           if((strcmp("on", str)==0)|| (strcmp("On",str)==0))
           {
                analogWrite(GREENPIN,90);
           }
           else if((strcmp("Of", str)==0)|| (strcmp("off",str)==0))
           {
               analogWrite(GREENPIN,0);
           }
         }
    }

}


void setup() {
    pinMode(GREENPIN, OUTPUT);
    analogWrite(GREENPIN, 90);
    SLIPSerial.begin(9600);   // set this as high as you can reliably run on your platform
    delay(1000);
    Serial.print("hello");
}
//reads and dispatches the incoming message
void loop(){
  OSCMessage bundleIN;
  int size;
  char c;

  while(!SLIPSerial.endofPacket())
    if( (size =SLIPSerial.available()) > 0)
    {
       while(size--) {
          c = SLIPSerial.read();
          bundleIN.fill(c);
       }
    }
  Serial.print("ended!");

    bundleIN.route("/led", LEDcontrol);

}
