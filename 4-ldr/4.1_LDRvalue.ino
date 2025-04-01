int nat = A0;                   //store analog pin A0 to variable nat
void setup() {
  pinMode(nat, INPUT);          //initializing nat in input mode
  Serial.begin(9600);           //initializing serial monitor with 9600 baud
}

void loop() {
  int natIn = analogRead(nat);  //read and store the nat value in natIn 
  int natIN = natIn/4;          //compute the value for natIN
  //4 is used as 1024/4 = 256 which is the maximum values to be in analog pins(0 - 1023) and digital pins(0 - 255)
  Serial.println(natIN);        //print out the natIN value in the serial monitor
  delay(30);                    //wait for 30 milliseconds to run the code again
}
