int nat = 9;        
int brightness = 0;  
int fadeAmount = 5; 

void setup() {
  pinMode(nat, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(nat, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  int natlevel = map(brightness, 0, 255, 0, 255);
  Serial.println(natlevel);
  delay(30);
}
