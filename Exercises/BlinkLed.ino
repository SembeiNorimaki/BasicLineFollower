// define constants
const int PIN_LED = 13;

void setup() {
  // define pins as INPUT or OUTPUT
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // Turn ON the LED
  digitalWrite(PIN_LED, HIGH);
  // Wait 1 second (1s = 1000ms)
  delay(1000);
  // Turn OFF the LED
  digitalWrite(PIN_LED, LOW);
  // Wait 1 second
  delay(1000);  
}
