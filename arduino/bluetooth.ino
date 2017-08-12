/*
* Bluetooh Basic: LED ON OFF - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* Download the App : https://github.com/Mayoogh/Arduino-Bluetooth-Basic
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/
#include <SoftwareSerial.h>

#define GREENPIN 11
#define REDPIN 10
#define BLUEPIN 9

#define GREENPIN_2 16
#define REDPIN_2 15
#define BLUEPIN_13
char data = 0;            //Variable for storing received data
void setup()
{
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(REDPIN_2, OUTPUT);
    pinMode(GREENPIN_2, OUTPUT);
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
    analogWrite(GREENPIN, 90);
    String setName = String("AT+NAME=Arduino\r\n"); //Setting name as 'MyBTBee'
    Serial.print(setName);
}
void loop()
{
  int b;
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      // fade from green to teal
    for (b = 0; b < 256; b++) { 
      analogWrite(BLUEPIN, b);
      delay(5);
    } 
    for (b = 255; b > 0; b--) { 
      analogWrite(BLUEPIN, b);
      delay(5);
    } 
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print("hi");          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == '1')              // Checks whether value of data is equal to 1
         analogWrite(GREENPIN, 90);   //If value is 1 then LED turns ON
      else if(data == '0')         //  Checks whether value of data is equal to 0
         analogWrite(GREENPIN, 0);    //If value is 0 then LED turns OFF
   }
}





