int ulp = 2; //digital
int ulpLED = 3; //digital pin
void setup() {
  pinMode(ulp, INPUT);
  pinMode(ulpLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(ulp);
  if (SwLevel == HIGH) 
    digitalWrite(ulpLED, LOW);
  else
    digitalWrite(ulpLED, HIGH);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
}