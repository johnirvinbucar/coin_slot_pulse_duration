/*
 * Coin Slot Pulse Duration Detection
 * 
 * This code is designed to detect the duration of a pulse from a coin slot
 * connected to an ESP32. The coin slot is assumed to use a normally 
 * open switch that pulls the input pin LOW when a coin is inserted. The code 
 * calculates how long the pulse lasts (in milliseconds) and prints the result 
 * to the Serial Monitor.
 * 
 * Pin Configuration:
 * - coinSlotPin (GPIO 5) connected to the coin slot sensor
 * - Internal pull-up resistor is enabled on the input pin (INPUT_PULLUP)
 * 
 * Pulse is detected by measuring the time between the rising (HIGH to LOW)
 * and falling (LOW to HIGH) edges of the signal.
 * 
 * Author: John Irvin Bucar
 * Date: 23/23/2024
 */

const int coinSlotPin = 4;  // Pin where the coin slot pulse is connected (with INPUT_PULLUP)
unsigned long pulseStartTime = 0;
unsigned long pulseEndTime = 0;
unsigned long pulseDuration = 0;  // Time in milliseconds

void setup() {
  Serial.begin(115200);                // Start the serial monitor
  pinMode(coinSlotPin, INPUT_PULLUP);  // Set the coin slot pin with internal pull-up resistor
}

void loop() {
  // Read the current state of the coin slot pin
  bool coinSlotState = digitalRead(coinSlotPin);

  // If the pulse starts (falling edge, LOW to HIGH transition), start timing the pulse
  if (coinSlotState == LOW && pulseStartTime == 0) {
    pulseStartTime = millis();  // Start timing the pulse
  }

  // If the pulse ends (rising edge, HIGH to LOW transition), calculate the pulse duration
  if (coinSlotState == HIGH && pulseStartTime != 0) {
    pulseEndTime = millis();                        // Stop timing the pulse
    pulseDuration = pulseEndTime - pulseStartTime;  // Calculate the pulse duration
    Serial.print("Pulse duration: ");
    Serial.print(pulseDuration);
    Serial.println(" ms");

    // Reset pulseStartTime for the next pulse
    pulseStartTime = 0;
  }
}
