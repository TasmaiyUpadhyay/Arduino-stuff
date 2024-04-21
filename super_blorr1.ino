// Define the pins
const int triggerPin = 2; // Pin connected to the trigger pin of the ultrasonic sensor
const int led1Pin = 8;    // Pin connected to the first LED
const int led2Pin = 9;    // Pin connected to the second LED
const int led3Pin = 10;   // Pin connected to the third LED

void setup() {
  // Initialize the pinMode for each pin
  pinMode(triggerPin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  long duration, distance;

  // Generate a pulse to trigger the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the duration of the pulse from the echo pin
  duration = pulseIn(triggerPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Determine the range of distance and control the LEDs accordingly
  if (distance < 20) {
    // Short range, turn on the first LED
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  } else if (distance >= 20 && distance < 50) {
    // Medium range, turn on the second LED
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
  } else {
    // Long range, turn on the third LED
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
  }

  // Wait for a short duration before taking the next measurement
  delay(100);
}
