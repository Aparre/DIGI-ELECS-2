int ulp = 2;
int ulpLed = 5;
int ulpState = 0;
int lastState;

void setup() {
  pinMode(ulp, INPUT);
  pinMode(ulpLed, OUTPUT);
  digitalWrite(ulpLed, LOW);
  Serial.begin(9600);
}

void loop() {
    int cState = digitalRead(ulp);
    if (lastState == 1 && cState == 0) {
        ulpState = !ulpState;
        digitalWrite(ulpLed, ulpState);

      // ALL OF THIS ARE FOR DEBUGGING PURPOSES
        Serial.print("cState: ");
        Serial.print(cState);
        Serial.print("  ");
        Serial.print("ulpState: ");
        Serial.print(ulpState);
        Serial.print("  ");
        Serial.print("ledout: ");
        Serial.print(ulpState);
        Serial.print("  ");
        
        lastState = !ulpState;
        Serial.print("lastState: ");
        Serial.println(lastState);
    }

    lastState = cState;
    delay(100);
}
