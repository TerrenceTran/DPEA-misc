// Tests the whole system of 4 LIDAR sensors with the multiplexor

#include <Wire.h>
#include <Adafruit_VL6180X.h> // REMEMBER TO DOWNLOAD THIS LIBRARY
extern "C" {
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}

#define Multiplex 0x70
#define IRSensor 0x29 // line not used, because address is default address declared in library

Adafruit_VL6180X sensor = Adafruit_VL6180X();

////////////////////////// SELECT BETWEEN 0-3 //////////////////////////

void TCASelect(uint8_t i) {
  if (i > 3) return; // if invalid input

  Wire.beginTransmission(Multiplex);
  Wire.write(1 << i);
  Wire.endTransmission();

  Serial.print("Selecting Port: ");
  Serial.println(i);
}

//////////////////////     Set Up       ///////////////////////////
/*  
 *  Initializes Serial and Wire
 *  Scans ports 0 - i for connection. Will not proceed unless they are detected
 */

void setup() {

  while (!Serial);
  delay(100);
  Wire.begin();

  Serial.begin(115200);
  Serial.println("Starting Setup!");

  for (uint8_t i = 0; i < 4; i++) {
    TCASelect(i);
    /*
        //////////////////// Insures Program Cannot Continue Until All Sensors Accounted For //////////////////////
        while (!sensor.begin()) {
          TCASelect(i); ///////////////// THIS WORKED?!?!!?!?/////////////////////////////
          sensor.begin();
          Serial.println("TRYING GDI");
          delay(250);
        }
        ////////////////////  Un Comment If Needed    ///////////////////////////////////////////////////////////
    */
    if (! sensor.begin()) {
      Serial.print("Failed to find sensor ");
      Serial.println(i);
      while (1); // Halts until all sensors found
    }

    Serial.print("Sensor ");
    Serial.print(i);
    Serial.println(" found!");
  }
  delay(1000);
}


////////////////////////////////////     LOOP      //////////////////////////////////////////
/*
 * Sequentailly scans devices from ports 0-i for their LIDAR readings
 */

void loop() {
  for (int i = 0; i < 4; i++) {

    TCASelect(i);
    uint8_t range = sensor.readRange();
    uint8_t status = sensor.readRangeStatus();

    if (status == VL6180X_ERROR_NONE) {
      Serial.print("Range: "); Serial.println(range);
    }

    // Some error occurred, print it out!

    if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
      Serial.println("System error");
    }
    else if (status == VL6180X_ERROR_ECEFAIL) {
      Serial.println("ECE failure");
    }
    else if (status == VL6180X_ERROR_NOCONVERGE) {
      Serial.println("No convergence");
    }
    else if (status == VL6180X_ERROR_RANGEIGNORE) {
      Serial.println("Ignoring range");
    }
    else if (status == VL6180X_ERROR_SNR) {
      Serial.println("Signal/Noise error");
    }
    else if (status == VL6180X_ERROR_RAWUFLOW) {
      Serial.println("Raw reading underflow");
    }
    else if (status == VL6180X_ERROR_RAWOFLOW) {
      Serial.println("Raw reading overflow");
    }
    else if (status == VL6180X_ERROR_RANGEUFLOW) {
      Serial.println("Range reading underflow");
    }
    else if (status == VL6180X_ERROR_RANGEOFLOW) {
      Serial.println("Range reading overflow");
    }
    delay(500);
  }
}
