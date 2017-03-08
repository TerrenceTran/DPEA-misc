void setup() {
  pinMode(69, OUTPUT);
  pinMode(68, OUTPUT);
  Serial.begin(9600);

  digitalWrite(68, HIGH);
  analogWrite(69, 170);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println(analogWrite(255));
  //Serial.println(analogRead(255));

}
