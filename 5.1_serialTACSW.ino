int name = A0;
void setup() {
  pinMode(name, INPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = analogRead(name);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
  delay(300);
}
