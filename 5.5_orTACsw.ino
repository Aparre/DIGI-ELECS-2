int ulp = 2; //digital
int ulpLed = 4; //digital pin
void setup() {
  pinMode(ulp, INPUT);
  pinMode(ulpLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(ulp);
  if (SwLevel == LOW)
    digitalWrite(ulpLed, HIGH);
  else
    digitalWrite(ulpLed, LOW);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
}
