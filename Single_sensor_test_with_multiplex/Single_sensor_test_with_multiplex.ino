// Tests the whole system of 4 with the multiplexor

#include <Wire.h>
#include <Adafruit_VL6180X.h> // REMEMBER TO DOWNLOAD THIS LIBRARY

#define Multiplex 0x70
#define IRSensor 0x29

Adafruit_VL6180X sensor = Adafruit_VL6180X();

////////////////////////// SELECT BETWEEN 0-3 //////////////////////////

const uint8_t port = 2; //choose port from 0-3 //////////////////////////

void TCASelect(uint8_t i) {
  if (i > 3) return; // if invalid input

  Wire.beginTransmission(Multiplex);
  Wire.write(1 << i);
  Wire.endTransmission();

  Serial.print("Selecting Port: ");
  Serial.println(i);
}

void setup() {
  TCASelect(port);

  Serial.begin(115200);
  Serial.println("Starting Setup!");

  // wait for serial port to open on native usb devices
  while (!Serial) {
    delay(1);
  }

  sensor.begin();

  if (! sensor.begin()) {
    Serial.print("Failed to find sensor ");
    Serial.println(port);
    //while (1); // halts if not found
  }

  Serial.print("Sensor ");
  Serial.print(port);
  Serial.println(" found!");

  delay(2000);
}

void loop() {
  //TCASelect(port);

  float lux = sensor.readLux(VL6180X_ALS_GAIN_5);

  Serial.print("Lux: "); Serial.println(lux);

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
