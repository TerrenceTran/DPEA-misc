// Tests the whole system of 4 with the multiplexor

#include <Wire.h>
#include <Adafruit_VL6180X.h> // REMEMBER TO DOWNLOAD THIS LIBRARY

#define Multiplex 0x70
#define IRSensor 0x29

Adafruit_VL6180X sensor = Adafruit_VL6180X();
//Adafruit_VL6180X s1 = Adafruit_VL6180X();
//Adafruit_VL6180X s2 = Adafruit_VL6180X();
//Adafruit_VL6180X s3 = Adafruit_VL6180X();

////////////////////////// SELECT BETWEEN 0-3 //////////////////////////

void TCASelect(uint8_t i) {
  if (i > 3) return; // if invalid input

  Wire.beginTransmission(Multiplex);
  Wire.write(1 << i);
  Wire.endTransmission();

  Serial.print("Selecting Port: ");
  Serial.println(i);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Setup!");

  for (int i = 0; i < 4; i++) {
    TCASelect(i);
    if (! sensor.begin()) {
      Serial.print("Failed to find sensor ");
      Serial.println(i);
      //while (1);
    }

    Serial.print("Sensor ");
    Serial.print(i);
    Serial.println(" found!");
  }
  delay(2000);
}

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
