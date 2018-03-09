# SerialPixels
Control microcontroller-attached addressable LEDs from your PC over USB Serial

A pair of programs for controlling RBG LEDs connected to a USB-Serial attached microcontroller (tested with an Adafruit Trinket M0) from a Windows PC. The Windows program (SerialPixelsPC), written in C#, has a button to load available serial ports which can then be chosen from a combobox. A second button allows the selection of a colour from a colour palette dialogue. The R, G and B values for that colour are transmitted over USB serial to the microcontroller (running SerialPixelsMicrocontroller), which then sets the LEDs to the appropriate colour.

Currently the programs are in a working but not at all efficient or resilient state, and are very buggy. Not recommended for use at all.

- SerialPixelsPC is very messily coded.  SerialPixelsTrinketM0 is, as far as I can tell, mostly OK.
- SerialPixelsMicrocontroller currently only supports RGB LEDs. I'll hopefully add support of RGBW at some point.
- Some of the colours in the dialog are not shown correctly. This is because the returned colour in C# is in RGBA (red/green/blue/alpha) format, whereas the microcontroller script only handles RGB. At some point I'll see if there's a decent way to convert this so that the LED output is a bit more representative of what is chosen in the dialog box.
- 
