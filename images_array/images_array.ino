#include "FastLED.h"       // Fastled library to control the LEDs

// How many leds are connected?
#define NUM_LEDS 256  //using 16x16 neomatrix

// Define the Data Pin
#define DATA_PIN 13  // Connected to the data pin of the first LED strip

// Define the array of leds
CRGB leds[NUM_LEDS];
//http://tomeko.net/online_tools/file_to_hex.php?lang=en
//https://sourceforge.net/projects/lcd-image-converter/

// Create array and store it in Flash memory


const long imageone[] PROGMEM =    //converter used  https://sourceforge.net/projects/lcd-image-converter/  Works! was bmp
{
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xf80305, 0x83365c, 0x355998, 0xa52744, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xfe0000, 0xc6182a, 0x2062a8, 0x026fbe, 0x644474, 0xf70406, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xf70406, 0x644474, 0x026fbe, 0x046ebd, 0x46518b, 0xbd1d31, 0xf70306, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xa92640, 0x265fa3, 0x0070c0, 0x0070c0, 0x026fbe, 0x644474, 0xf70406, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xf70406, 0x644474, 0x026fbe, 0x2f5c9d, 0xa02a47, 0x365898, 0x7e3961, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xeb080e, 0x3a5694, 0x026fbe, 0x644474, 0xf70406, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xf70406, 0x644474, 0x026fbe, 0x3a5694, 0xeb080e, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xeb080e, 0x3a5694, 0x026fbe, 0x644474, 0xf70406, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xf70406, 0x644474, 0x026fbe, 0x3a5694, 0xeb080e, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xeb080e, 0x3a5694, 0x026fbe, 0x644474, 0xf70406, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xfa0204, 0xa22846, 0x674272, 0x893358, 0xf30508, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000
};

//const long imagetwo[] PROGMEM = 
const uint8_t imagetwo[] PROGMEM =     // http://tomeko.net/online_tools/file_to_hex.php?lang=en jpg mangled, gif mangled, bmp
{
0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x01, 0x00, 0x60, 
0x00, 0x60, 0x00, 0x00, 0xFF, 0xDB, 0x00, 0x43, 0x00, 0x06, 0x04, 0x05, 0x06, 0x05, 0x04, 0x06, 
0x06, 0x05, 0x06, 0x07, 0x07, 0x06, 0x08, 0x0A, 0x10, 0x0A, 0x0A, 0x09, 0x09, 0x0A, 0x14, 0x0E, 
0x0F, 0x0C, 0x10, 0x17, 0x14, 0x18, 0x18, 0x17, 0x14, 0x16, 0x16, 0x1A, 0x1D, 0x25, 0x1F, 0x1A, 
0x1B, 0x23, 0x1C, 0x16, 0x16, 0x20, 0x2C, 0x20, 0x23, 0x26, 0x27, 0x29, 0x2A, 0x29, 0x19, 0x1F, 
0x2D, 0x30, 0x2D, 0x28, 0x30, 0x25, 0x28, 0x29, 0x28, 0xFF, 0xDB, 0x00, 0x43, 0x01, 0x07, 0x07, 
0x07, 0x0A, 0x08, 0x0A, 0x13, 0x0A, 0x0A, 0x13, 0x28, 0x1A, 0x16, 0x1A, 0x28, 0x28, 0x28, 0x28, 
0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 
0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 
0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0xFF, 0xC0, 
0x00, 0x11, 0x08, 0x00, 0x10, 0x00, 0x10, 0x03, 0x01, 0x22, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 
0x01, 0xFF, 0xC4, 0x00, 0x16, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x07, 0xFF, 0xC4, 0x00, 0x1C, 0x10, 0x00, 0x02, 
0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
0x00, 0x03, 0x11, 0x41, 0x12, 0x31, 0x51, 0xFF, 0xC4, 0x00, 0x15, 0x01, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0xFF, 0xC4, 
0x00, 0x21, 0x11, 0x00, 0x01, 0x02, 0x05, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x01, 0x11, 0x41, 0x00, 0x02, 0x03, 0x12, 0x21, 0x05, 0x14, 0x23, 0x31, 0x51, 
0x24, 0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03, 0x11, 0x00, 0x3F, 0x00, 0xCF, 
0x2B, 0x42, 0xED, 0x8D, 0x42, 0xC5, 0xE2, 0xE4, 0x0D, 0x49, 0x4E, 0x18, 0x13, 0xEC, 0x6C, 0x21, 
0x9C, 0x91, 0xD4, 0x39, 0xC1, 0xB3, 0xC0, 0xE4, 0xBB, 0xD6, 0x42, 0xDE, 0x45, 0xDF, 0xED, 0x1A, 
0xB2, 0x12, 0xB4, 0x0D, 0x33, 0x84, 0xC0, 0x9A, 0xE9, 0x7B, 0x2E, 0x48, 0x54, 0xEB, 0x0C, 0xF1, 
0xFF, 0xD9
};


void setup() { 
FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);  // Init of the Fastled library
FastLED.setBrightness(15);
}

void loop() { 


// Put imageone first frame
for(int passtime = 0; passtime < 8; passtime++) { // Display it 8 times

FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(imageone[i]));  // Read array from Flash
  }

FastLED.show();
delay(500);

// Put imagetwo second frame
FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(imagetwo[i]));
  }

FastLED.show();
delay(400);



}

}