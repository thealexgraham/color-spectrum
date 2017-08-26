#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define BLUEPIN 9
#define REDPIN 10
#define GREENPIN 11

#define BLUEPIN_2 3
#define REDPIN_2 5
#define GREENPIN_2 6
 
#define FADESPEED 10     // make this higher to slow down
 
void setup() {
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(REDPIN_2, OUTPUT);
    pinMode(GREENPIN_2, OUTPUT);
    pinMode(BLUEPIN_2, OUTPUT);
    Serial.begin(9600);   //Sets the baud for serial data transmission                               

}
 
 
void loop() {
    int r = 256.0;
    int g = 50.0;
    int b = 256.0;
    float adjust = 0.9;
    //Serial.print(ceil(r*adjust));
//  analogWrite(REDPIN_2, ceil(r * adjust));
//  analogWrite(GREENPIN_2, round(g * adjust));
//  analogWrite(BLUEPIN_2, round(b * adjust));
    for (float x = 0; x < 1.0; x = x + 0.001) { 
        adjust = x;
        analogWrite(REDPIN_2, ceil(r * adjust));
        analogWrite(GREENPIN_2, round(g * adjust));
        analogWrite(BLUEPIN_2, round(b * adjust));
        delay(FADESPEED);
    } 
    for (float x = 1.0; x > 0.01; x = x - 0.001) { 
        adjust = x;
        analogWrite(REDPIN_2, ceil(r * adjust));
        analogWrite(GREENPIN_2, round(g * adjust));
        analogWrite(BLUEPIN_2, round(b * adjust));
        delay(FADESPEED);
    } 
//  // fade from blue to violet
//  for (r = 0; r < 256; r++) { 
//    analogWrite(REDPIN, r);
//    delay(FADESPEED);
//    analogWrite(REDPIN_2, abs(r - 256));
//    delay(FADESPEED);
//  } 
//  // fade from violet to red
//  for (b = 255; b > 0; b--) { 
//    analogWrite(BLUEPIN, b);
//    delay(FADESPEED);
//    analogWrite(GREENPIN_2, abs(b - 256));
//    delay(FADESPEED);
//  } 
//  // fade from red to yellow
//  for (g = 0; g < 256; g++) { 
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//    analogWrite(BLUEPIN_2, abs(g - 128));
//    delay(FADESPEED);
//  } 
//  // fade from yellow to green
//  for (r = 255; r > 0; r--) { 
//    analogWrite(REDPIN, r);
//    delay(FADESPEED);
//    analogWrite(REDPIN_2, abs(r - 128));
//    delay(FADESPEED);
//  }
//  // fade from green to teal
//  for (b = 0; b < 256; b++) { 
//    analogWrite(BLUEPIN, b);
//    delay(FADESPEED);
//    analogWrite(BLUEPIN_2, abs(b - 128));
//    delay(FADESPEED);
//  } 
//  // fade from teal to blue
//  for (g = 255; g > 0; g--) { 
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//    analogWrite(GREENPIN_2, abs(g - 128));
//    delay(FADESPEED);
//  } 
}
