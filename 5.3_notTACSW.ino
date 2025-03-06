int ulp = 2; //digital
int ulpLed = 3; //digital pin
void setup() {
  pinMode(ulp, INPUT);
  pinMode(ulpLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(ulp);
  if (SwLevel == LOW) 
    digitalWrite(ulpLed, LOW);
  else
    digitalWrite(ulpLed, HIGH);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
  delay(30);
}
