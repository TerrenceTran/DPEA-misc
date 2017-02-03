// Quick test program for 12pixel NeoPixel Ring Console 11

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// port of connection and number of pixels
#define PORT 8
#define NUMPIXELS 12

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, ADD TOGETHER AS NEEDED:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PORT, NEO_GRB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.show(); // show makes them show their current setting. by default this is off
}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for (int i = 0; i < 3 * NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    if (i < NUMPIXELS)
      ring.setPixelColor(i, ring.Color(0, 255, 0)); // Moderately bright green color.

    else if (i < 2 * NUMPIXELS)
      ring.setPixelColor(i - NUMPIXELS, ring.Color(0, 0, 255)); // Moderately bright green color.

    else
      ring.setPixelColor(i - 2 * NUMPIXELS, ring.Color(255, 0, 0)); // Moderately bright green color.

    ring.show(); // This sends the updated pixel color to the hardware.

    delay(75); // Delay for a period of time (in milliseconds).

  }

}
