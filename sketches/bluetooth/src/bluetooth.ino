/*
* Bluetooh Basic: LED ON OFF - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* Download the App : https://github.com/Mayoogh/Arduino-Bluetooth-Basic
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/
#include <SoftwareSerial.h>
#include "OSC/OSCBundle.h"

#define GREENPIN 11
#define REDPIN 10
#define BLUEPIN 9

#define GREENPIN_2 16
#define REDPIN_2 15
#define BLUEPIN_13
char data = 0;            //Variable for storing received data

SoftwareSerial BTSerial(13,12);

void setup()
{

    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(REDPIN_2, OUTPUT);
    pinMode(GREENPIN_2, OUTPUT);

    Serial.begin(9600);   //Sets the baud for serial data transmission

    BTSerial.begin(9600);
    BTSerial.print("AT\r\n"); // Check Status

    delay(500);

    while (BTSerial.available()) {
        Serial.write(BTSerial.read());
    }

    String setName = String("AT+NAME=TheEyes\r\n"); //Setting name as 'MyBTBee'
    BTSerial.print(setName);

    delay(500);
    while (BTSerial.available()) {
        Serial.write(BTSerial.read());
    }
    analogWrite(GREENPIN, 90);
}

String str;
void loop()
{
    int b;
     if(Serial.available() > 0)      // Send data only when you receive data:
     {
        data = Serial.read();        //Read the incoming data & store into data
        str = Serial.readString();
        Serial.println(str);
        //Serial.print(data);          //Print Value inside data in Serial monitor
        //Serial.print("\n");
        //if(data == '1')              // Checks whether value of data is equal to 1
        //    analogWrite(GREENPIN, 90);   //If value is 1 then LED turns ON
        //else if(data == '0')         //  Checks whether value of data is equal to 0
        //    analogWrite(GREENPIN, 0);    //If value is 0 then LED turns OFF
        //else if(data == '\n')
        //    Serial.print("Doing it");
        //    Serial.print(str);
     }
}
