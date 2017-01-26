// I2C Digital Potentiometer
// by Nicholas Zambetti <http://www.zambetti.com>
// and Shawn Bonkowski <http://people.interaction-ivrea.it/s.bonkowski/>
// Variable pot tester for console 12

#include <Wire.h>

// I2C Address of device
#define DEFAULT_ADDRESS  0x28  // A0,A1 & A2 are connected to GND

// Command definitions
#define WRPOT0 0xA9
#define WRPOT1 0xAA
#define WRBOTH 0xAF

// Common WIPER values
#define WIPER_MAX  0x00 // 0
#define WIPER_MID  0x20 // 32
#define WIPER_MIN  0x3F // 63
#define WIPER_MUTE 0x40 // 64


void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

// this loop runs through values 0-64 to sweep the pot from high to low (low pin and sweeper pin)
void loop() {
  for (uint8_t i = 0; i<32; i++) {
  Wire.beginTransmission(DEFAULT_ADDRESS); // transmit to device 
  Wire.write((uint8_t)WRPOT0);   // A9 = write to pot 0 only, AF = both pots
  
  // Bits 0 through 5 of the register are used to set the position on the resistor array
  // Bit 6 is used to set the wiper position to the mute position and bit 7 is a don’t care
  // If the value of bit 6 is set equal to 1, regardless of all other bit values, 
  // the wiper position of the respective potentiometer will be set to the mute position.

  // WRITE IN uint8_t !!! values from 0-64
  
  Wire.write((uint8_t)i);      // sends potentiometer value byte 
  
  Wire.endTransmission();     // stop transmitting

  delay(10*(32/(i+1)));
  }
}

/* hard setting values just for confirmation
void loop() {
  Wire.beginTransmission(DEFAULT_ADDRESS); // transmit to device 
  Wire.write((uint8_t)WRPOT0);   // A9 = write to pot 0 only, AF = both pots
  
  // Bits 0 through 5 of the register are used to set the position on the resistor array
  // Bit 6 is used to set the wiper position to the mute position and bit 7 is a don’t care
  // If the value of bit 6 is set equal to 1, regardless of all other bit values, 
  // the wiper position of the respective potentiometer will be set to the mute position.

  // WRITE IN uint8_t !!! values from 0-64
  
  Wire.write((uint8_t)WIPER_MID);      // sets potentiometer value to max (between Low and Wiper 42.7k)
   
  Wire.endTransmission();     // stop transmitting

  delay(2000);
  
////////////////////////////////////////////////////////////////////////////

  Wire.beginTransmission(DEFAULT_ADDRESS); // transmit to device 
  Wire.write((uint8_t)WRPOT0);   // A9 = write to pot 0 only, AF = both pots
  
  // Bits 0 through 5 of the register are used to set the position on the resistor array
  // Bit 6 is used to set the wiper position to the mute position and bit 7 is a don’t care
  // If the value of bit 6 is set equal to 1, regardless of all other bit values, 
  // the wiper position of the respective potentiometer will be set to the mute position.

  // WRITE IN uint8_t !!! values from 0-64
  
  Wire.write((uint8_t)WIPER_MUTE);      // sends potentiometer value byte 
   
  Wire.endTransmission();     // stop transmitting

  delay(2000);

  ////////////////////////////////////////////////////////////////////////////

  Wire.beginTransmission(DEFAULT_ADDRESS); // transmit to device 
  Wire.write((uint8_t)WRPOT0);   // A9 = write to pot 0 only, AF = both pots
  
  // Bits 0 through 5 of the register are used to set the position on the resistor array
  // Bit 6 is used to set the wiper position to the mute position and bit 7 is a don’t care
  // If the value of bit 6 is set equal to 1, regardless of all other bit values, 
  // the wiper position of the respective potentiometer will be set to the mute position.

  // WRITE IN uint8_t !!! values from 0-64
  
  Wire.write((uint8_t)WIPER_MAX);      // sends potentiometer value byte 
   
  Wire.endTransmission();     // stop transmitting

  delay(2000);
}
*/
