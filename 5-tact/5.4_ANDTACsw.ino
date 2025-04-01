int name = 2; //digital
int name2 = 3; // digital pin
int nameLed = 4; //digital pin
void setup() {
  pinMode(name, INPUT);
  pinMode(name2, INPUT);
  pinMode(nameLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(name);
  int Sw2Level = digitalRead(name2);
  if (SwLevel == HIGH && Sw2Level == HIGH)
    digitalWrite(nameLed, HIGH);
  else
    digitalWrite(nameLed, LOW);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
}
