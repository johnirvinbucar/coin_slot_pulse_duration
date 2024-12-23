# Coin Slot Pulse Duration Detection (ESP32)

This project is designed to detect the duration of a pulse from a coin slot sensor connected to an **ESP32**. The code measures the time in milliseconds between the falling edge (coin detected) and the rising edge (coin processed) of the pulse from the coin slot.

# Features:
- Detects pulse duration from a coin slot sensor.
- Uses the **ESP32** microcontroller.
- **Internal pull-up resistor** enabled on the GPIO pin used to detect the pulse.
- Outputs the pulse duration in milliseconds to the **Serial Monitor**.
  
# Hardware Setup:
- **ESP32 Board** (38-pin model or any variant).
- **Coin Slot Sensor**: A coin slot sensor that pulls the input pin `LOW` when a coin is inserted and `HIGH` when no coin is detected.
- **GPIO Pin**: The coin slot sensor is connected to GPIO pin **5** of the ESP32 (you can change this in the code if needed).
- **Resistor**: Internal pull-up resistor is used for the sensor input pin.

# Pin Configuration:
- **coinSlotPin (GPIO 5)**: This pin is connected to the coin slot sensor.
  - **INPUT_PULLUP** mode is used, which means the pin is pulled `HIGH` when no pulse is detected and goes `LOW` when a coin is inserted.

# Code Explanation:
- **Pulse Detection**: The code detects when the coin slot sensor pin goes from `HIGH` to `LOW` (falling edge) to start the pulse. It then measures how long the pulse stays `LOW` and stops timing when the pin returns to `HIGH` (rising edge).
- **Pulse Duration Output**: The pulse duration is printed in milliseconds on the **Serial Monitor**.
- **Single Pulse Detection**: The code processes one pulse at a time, calculates its duration, and waits for the next pulse.

# Circuit Diagram:
You can connect the coin slot sensor's output to GPIO pin **5** (or the pin of your choice). The sensor should have a pull-down resistor or use the **internal pull-up resistor** of the ESP32 to detect the state change (from `HIGH` to `LOW`).

# Requirements:
- **ESP32** board (with Arduino IDE support).
- **Arduino IDE** installed with **ESP32** board support.

3. Select your ESP32 board from the Tools menu:
   - Board: `ESP32 Dev Module` (or your specific ESP32 board).
   - Port: Choose the correct serial port.

4. Upload the code to your ESP32 board.

5. Open the **Serial Monitor** in the Arduino IDE to view the pulse duration in milliseconds.

### Example Output:
Pulse duration: 100 ms Pulse duration: 98 ms Pulse duration: 105 ms


 
