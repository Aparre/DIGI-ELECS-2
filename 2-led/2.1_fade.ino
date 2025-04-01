int nat = 9;                  //digital pin 9 for led
int brightness = 0;           //varible for storing led brightness
int fadeAmount = 5;           // variable for incrementation of brightness value

void setup() {
  pinMode(nat, OUTPUT);       //setting the pin 9 to be output
  Serial.begin(9600);         // initializing serial monitor with 9600 baud
}

void loop() {
  //at first execution the brightness value is 0, then later be adjusted
  analogWrite(nat, brightness); 
  brightness = brightness + fadeAmount;   //computing the next value of brightness

  //condition for when the brightness value excceds 255 the fadeamount value is negated resulting in decreasing value of brightness
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; 
  }
  Serial.println(brightness);             //display the value of brightness 
  delay(30);                              // wait for 30 millisecond to run the code again
  // at this point the brightness value is being adjusted with respect to the computation in line 13
}
