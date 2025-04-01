// if the knob turn is reversed or not following the chosen side to turn you can:
// exchange min1 to max1 or exchange the 5v and gnd connection of the potentiometer

int nat = A0;                   //store analog pin A0 to variable nat
int natled = 3;                 //set digital pin 3 for led
//choose digital pin with ~ or capable for sending PWM signals
void setup() {
  pinMode(nat, INPUT);          //initializing nat in input mode
  pinMode(natled, OUTPUT);      //initializing nat in output mode
  Serial.begin(9600);           //initializing serial monitor with 9600 baud
}

void loop() {
  int natIn = analogRead(nat);  //read and store the nat value in natIn
  /*  map(variable, min1, max1, min2, max2);
      variable     = refers to the value measured to be mapped
      min1 , max1  = refers to the minimum and maximum value of the actual measured value
      min2 , max2  = refers to the minimum and maximum value of the value to be outptted by the map

      the map() function will correlate the values from the reference(actual) to the outputted, not only the
      range(min2, max2) are the outputted values and exceeding the range(min1, max1) results to exceeding the values for 
  */
  int natIN = map(natIn, 0, 1023, 0, 255);
  digitalWrite(natled, natIN);  //write the mapped value of natIN to the LED
  Serial.println(natIN);        //print out the natIN value in the serial monitor, which indicates the brightness of the LED
  delay(30);                    //wait for 30 milliseconds to run the code again
}
