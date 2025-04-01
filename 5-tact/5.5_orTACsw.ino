int name = 2; //digital
int nameLed = 4; //digital pin
void setup() {
  pinMode(name, INPUT);
  pinMode(nameLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(name);
  if (SwLevel == HIGH)
    digitalWrite(nameLed, HIGH);
  else
    digitalWrite(nameLed, LOW);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
}
