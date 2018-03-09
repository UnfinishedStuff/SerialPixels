#include <FastLED.h>

//This is neccessary to get Serial working properly on the Trinket M0
#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  // Required for Serial on Zero based boards
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif

// Define the number of LEDs on the device here
#define NUM_LEDS 1
//Set up the array which holds data on the LEDs
CRGB leds[NUM_LEDS];

//Define the data pin for the LEDs, required for ALL types of LED
#define DATA_PIN    7
//Define the clock pin, required for some (e.g. DotStars) but not others (e.g. Neopixels)
#define CLOCK_PIN   8

//A string for storing serial data once it has been read.  
//Expected to be three ints between 0-255 separated by commas
String incomingData;
//An int to hold the location of the first comma in incomingData
int firstComma;
//An int to hold the location of the second comma in incomingData
int secondComma;
//An int to hold the length of incomingData
int dataLength;
//Three ints for holding values for red, green and blue values respectively
int red, green, blue;

void setup() 
    {
    //Start the serial comms
    Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
    
    //**IMPORTANT!**  Uncomment ONE of these according to whether you're using
    //NeoPixels or Dotstars.
    FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
    //FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    }

void loop() 
{
    //If the board has recieved serial data
    while (Serial.available() > 0) 
    {
        incomingData += (char)Serial.read();
    }
    if (incomingData != "")
    {
        //Get the length of the String in incomingData
        dataLength = incomingData.length();
        //Find the first comma
        firstComma = incomingData.indexOf(",");
        //Find the second comma
        secondComma = incomingData.indexOf(",", firstComma+1);

        //Convert everything from the start of incomingData to the first comma to an int, 
        //set as the value for red
        red =   incomingData.substring(0, firstComma).toInt();
        //Convert the value between the first and second commas to an int, set as green
        green = incomingData.substring(firstComma+1, secondComma).toInt();
        //Set everything after the second comma to an int, set as blue
        blue =  incomingData.substring(secondComma+1, dataLength).toInt();

        //Set the first LED to the values for red, green and blue
        leds[0].setRGB(red, green, blue);
        //Show the LEDs
        FastLED.show();
    }
    //Blank incoming data to make sure there's not carry-over between messages
    incomingData = "";
    //slight pause
    delay(50);
}

