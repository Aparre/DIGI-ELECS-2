// the setup function runs once when you press reset or power the board
const int led = 13; //For accessing LED_BUILTIN
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT); //pag na-comment to ng part na to 0 na lalabas sa serial
  Serial.begin(9600);
}
// the loop function runs over and over again forever
void loop() {
  int ledState = digitalRead(led);
  if (ledState == HIGH) {
    digitalWrite(led, LOW);          //set the led to LOW state or OFF state
  }
  else {
    digitalWrite(led, HIGH);         //set the led to HIGH state or ON state   
  }
  Serial.println(ledState);          //print out the value of ledState in the serial monitor
  delay(1000);                       //wait for 1s
}
