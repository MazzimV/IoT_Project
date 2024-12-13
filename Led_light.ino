int redpin = 3;
int greenpin = 4;
int bluepin = 5;

int brightness = 255;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int step = 0; step <= 100; step++) {
    brightness = 255 - (step * 255 / 100);
    analogWrite(redpin, brightness);
    analogWrite(greenpin, brightness);
    analogWrite(bluepin, brightness);
    delay(36000); 
    Serial.println(brightness);
  }

  analogWrite(redpin, 0);
  analogWrite(greenpin, 0);
  analogWrite(bluepin, 0);

  while (true) {
  }
}
