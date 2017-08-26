// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define GREENPIN 11
#define REDPIN 10
#define BLUEPIN 9

#define GREENPIN_2 16
#define REDPIN_2 15
#define BLUEPIN_13
 
#define FADESPEED 10     // make this higher to slow down
 
void setup() {
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(REDPIN_2, OUTPUT);
    pinMode(GREENPIN_2, OUTPUT);
    //pinMode(BLUEPIN_2, OUTPUT);
}
 
 
void loop() {
    int r, g, b;
    analogWrite(REDPIN_2, 90);

    // fade from blue to violet
    for (r = 0; r < 90; r++) { 
        analogWrite(REDPIN, r);
        //analogWrite(REDPIN_2, abs(r - 90));
        delay(FADESPEED);

    }
    // fade from blue to violet
    for (r = 90; r > 0; r--) { 
        analogWrite(REDPIN, r);
        analogWrite(REDPIN_2, abs(r - 90));
        delay(FADESPEED);
    } 
    // fade from blue to violet
}
