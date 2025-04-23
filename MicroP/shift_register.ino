const int latch_pin = 10;
const int clock_pin = 13;
const int data_pin = 11;
const int pinA = A0;
int x;
int change;

void setup() {
  pinMode(latch_pin,OUTPUT);
  pinMode(clock_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  pinMode(pinA,INPUT);
  Serial.begin(9600);
}

void loop() {
  int pin4S = digitalRead(pinA);
  Serial.print(pin4S);
  

  if (pin4S == HIGH) {
    Serial.print("Hyes");
    change = change + 1;
    
  }
  if (change >= 5) {
    change = 0;
  }
  Serial.print("  Change : ");
  Serial.print(change);

  
  x = x + change;
  if (x >= 256) {
    x = 0;
  }
  Serial.print("  X : ");
  Serial.println(x);

  shiftOut(data_pin, clock_pin, MSBFIRST, x);
  digitalWrite(latch_pin,HIGH);
  digitalWrite(latch_pin,LOW);
  delay(1000);
}
