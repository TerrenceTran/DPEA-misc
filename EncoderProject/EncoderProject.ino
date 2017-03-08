// inslude the SPI library:
#include <SPI.h>

const int slaveSelectPin = 23;
 int recievedVal16;
 int recievedVal16B;
 int recievedVal16C;
 int recievedVal16D;
// binary  --- B11110000
// Hex   0x7F

void setup() {
  // setup code, to run once:
  SPI.begin();
  pinMode(slaveSelectPin, OUTPUT);   //SS
  pinMode(50, INPUT_PULLUP);   //MISO
  pinMode(51, OUTPUT);         //MOSI
  pinMode(52, OUTPUT);       // SCLK   
  Serial.begin(38400);
  SPI.begin();
  
}

void loop() {
  SPI.beginTransaction(SPISettings(1000000,MSBFIRST,SPI_MODE1));
  digitalWrite(slaveSelectPin, LOW);
  delayMicroseconds(30);
  recievedVal16 = SPI.transfer16(0xf0f0);
  recievedVal16B  = SPI.transfer16(0xf0f0);
  recievedVal16C  = SPI.transfer16(0xf0f0);
  recievedVal16D  = SPI.transfer16(0xf0f0);
  SPI.endTransaction();
  digitalWrite(slaveSelectPin, HIGH);
  Serial.print("Count =  ");
  Serial.print(recievedVal16, DEC);
  Serial.print("  ");
  Serial.print(recievedVal16B, DEC);
  Serial.print("  ");
  Serial.print(recievedVal16C, DEC);
  Serial.print("  ");
  Serial.println(recievedVal16D, DEC);
  delay(500);
}
