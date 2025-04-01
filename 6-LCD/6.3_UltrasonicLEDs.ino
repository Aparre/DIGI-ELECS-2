#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object with I2C address 0x27 and 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address is 0x27 for most LCDs

// Define pins for the Trigger and Echo of the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

// Variables to store the duration and calculated distance
long duration;
float Adistance;
int distance;
int prevDistance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Set LED pins as OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  // Ensure all LEDs are OFF initially
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  // Display a welcome message
  lcd.setCursor(0, 0);  // Set cursor to top-left corner
  lcd.print("Distance Sensor");
  delay(2000);  // Wait for 2 seconds

}

void loop() {
  // Send a pulse to the ultrasonic sensor to trigger it
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // Send a 10-microsecond pulse
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (distance = time * speed of sound / 2)
  // Speed of sound is 343 m/s (or 0.0344 cm/µs)
  distance = duration * 0.0344 / 2;
 
  prevDistance == distance;
  if (distance != prevDistance) {
    // Clear the previous display
    lcd.clear();
    lcd.setCursor(0, 0);  // Set cursor to top-left corner
    lcd.print(" Distance: ");
     lcd.setCursor(5, 1);
    lcd.print(distance);
    lcd.print(" cm");
    // Wait for a moment before the next measurement
    delay(500);  // Delay for half a second (500 milliseconds)
  }

  // Light up the LEDs based on the distance
  if (distance >= 0 && distance < 5) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }


  if (distance >= 0 && distance < 21) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }

  if (distance >= 0 && distance < 41) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

  if (distance >= 0 && distance < 61) {
    digitalWrite(led4, HIGH);
  } else {
    digitalWrite(led4, LOW);
  }

  if (distance >= 0 && distance < 81) {
    digitalWrite(led5, HIGH);
    Serial.print(5);
  } else {
    digitalWrite(led5, LOW);
  }

  delay(30);

    
}
