#define RED 8
#define BLUE 10
#define GREEN 24

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

}

int i = 0;

void loop() {
  analogWrite(RED, i);
  analogWrite(BLUE, 255);
  analogWrite(GREEN, 255);
  i++;
  delay(1*i);
  if(i == 255) i=0;

}
