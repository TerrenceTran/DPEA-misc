#define RED 8
#define BLUE 23
#define GREEN 24

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

}

int i = 0;

void loop() {
  analogWrite(RED, i);
  analogWrite(BLUE, i);
  analogWrite(GREEN, i);
  i++;
  delay(10);
  if(i == 255) i=0;

}
