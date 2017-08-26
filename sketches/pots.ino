// Raw potentiometer value viewer

// Constants
const int POT_PIN = 0;                  // Pot connected to analog pin 0
const int SERIAL_PORT_RATE = 9600;


void setup()                            // Run once, when the sketch starts
{
    Serial.begin(SERIAL_PORT_RATE);     // Starts communication with the serial port
}

void loop()                             // Run over and over again
{
    int nValue = analogRead(POT_PIN);
    Serial.println(nValue);
}
