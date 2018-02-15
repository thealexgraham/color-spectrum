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

#define GREENPIN_2 6
#define REDPIN_2 5
#define BLUEPIN_2 3

#define INPUT_SIZE 255
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

    String setName = String("AT+NAMEArduino\r\n"); //Setting name as 'MyBTBee'
    BTSerial.print(setName);

    delay(500);
    while (BTSerial.available()) {
        Serial.write(BTSerial.read());
    }
    analogWrite(11, 100);
    analogWrite(10, 100);
    analogWrite(9, 100);
}

char inData[INPUT_SIZE];
byte idx = 0;
// 1:g:90&1:r:60
void loop()
{
    int b;

    if(BTSerial.available() > 0)      // Send data only when you receive data:
    {
        byte inByte = BTSerial.read();
        if (inByte == '\n') {
            inData[idx] = 0;
            handleCommand(inData);
            // Reset the array
            idx = 0;
            memset(&inData[0], 0, sizeof(inData));
        } else {
            inData[idx++] = inByte;
        }
     }
}


void handleCommand(char input[]) {

    // Read each command pair
    char* command = strtok(input, "&");
    while (command != '\0')
    {
        // Split the command in two values
        char* separator = strchr(command, ':');
        if (separator != '\0')
        {
            // Actually split the string in 2: replace ':' with 0
            *separator = '\0';
            int lane = atoi(command);
            ++separator;
            char* next = strchr(separator, ':');
            *next = '\0';
            char* color = separator;
            ++next;
            int value = atoi(next);
            char buffer[255];
            sprintf(buffer,"ID: %d, color: %s, value: %d\n\n", lane, color, value);
            Serial.print(buffer);

            setColor(lane,color[0],value);
        }
        // Find the next command in input string
        command = strtok('\0', "&");
    }
}

void setColor(int lane, char color, int value) {
    analogWrite(getPin(lane,color), value);
}

int getPin(int lane, char color) {
    if (lane == 1) {
        switch (color) {
            case 'r':
                return REDPIN;
                break;
            case 'g':
                return GREENPIN;
                break;
            case 'b':
                return BLUEPIN;
                break;
        }
    } else {
        switch (color) {
            case 'r':
                return REDPIN_2;
                break;
            case 'g':
                return GREENPIN_2;
                break;
            case 'b':
                return BLUEPIN_2;
                break;
        }
    }
}
void handleString(String str) {
    analogWrite(GREENPIN, str.toInt());
}

void handleData(char data) {
    //Serial.print(data);          //Print Value inside data in Serial monitor
    //Serial.print("\n");
    if(data == '1')              // Checks whether value of data is equal to 1
        analogWrite(GREENPIN, 90);   //If value is 1 then LED turns ON
    else if(data == '0')         //  Checks whether value of data is equal to 0
        analogWrite(GREENPIN, 0);    //If value is 0 then LED turns OFF
    else if(data == '\n')
        Serial.print("Doing it");
}


//test = Serial.readStringUntil('\n');
//Serial.print(test);
//handleString(test);

