#define testPin 9

void setup() {
  pinMode(testPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(testPin));
}
