int name = 2; //digital
int nameLed = 3; //digital pin
void setup() {
  pinMode(name, INPUT);
  pinMode(nameLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SwLevel = digitalRead(name);
  if (SwLevel == LOW) 
    digitalWrite(nameLed, LOW);
  else
    digitalWrite(nameLed, HIGH);
  Serial.print("Switch: ");
  Serial.println(SwLevel);
  delay(30);
}