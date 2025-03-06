int ulp = 2; //digital
int ulp2 = 3; // digital pin
int ulpLed = 4; //digital pin
void setup() {
  pinMode(ulp, INPUT);
  pinMode(ulp2, INPUT);
  pinMode(ulpLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(ulp);
  int Sw2Level = digitalRead(ulp2);
  if (SwLevel == LOW && Sw2Level == LOW)
    digitalWrite(ulpLed, HIGH);
  else
    digitalWrite(ulpLed, LOW);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
}
