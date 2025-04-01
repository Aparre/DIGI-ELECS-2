int nat = A0;                   //store analog pin A0 to variable nat
int natled = 2;                 //digital pin 2 for LED
int x = 940;                    //lower boundary of when the LDR is lit
int y = 980;                    //higher boundary of when the LDR is shaded

void setup() {
  pinMode(nat, INPUT);          //initializing nat in input mode
  pinMode(natled, OUTPU);       //initializing natled in output mode
  Serial.begin(9600);           //initializing serial monitor with 9600 baud
}

void loop() {
  int natIn = analogRead(nat);      //read and store the nat value in natIn 
  natIn = constrain(natIn, x, y);   //use constrain to limit the value given by the variable any excess will be cut-off
  natIN = map(natIn, x, y, 0, 255); //use map to correlate the value into the PWM signal values
  Serial.println(natIN);            //print out the natIN value in the serial monitor
  delay(30);                        //wait for 30 milliseconds to run the code again
}
