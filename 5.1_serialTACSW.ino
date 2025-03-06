int ulp = A0;
void setup() {
  pinMode(ulp, INPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = analogRead(ulp);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
  delay(300);
}
