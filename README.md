🚗 ESP32-Based Smart Parking Sensor System
This project is a smart parking sensor system developed using an ESP32 microcontroller, AJ-SR04M ultrasonic sensors, a Nextion display, and buzzers. The system measures distances around the vehicle and provides visual and audio feedback to the user.

📷 Project Overview
Distance measurements are taken from front, rear, left, and right directions.

The Nextion display allows the user to perform operations such as selecting a vehicle type, visualizing distance, and controlling the buzzer.

According to different distance ranges, both warning icons are shown on the screen, and various warning sounds are played via buzzers.

d

🧰 Hardware Used
Hardware	Description
ESP32 DevKit V1	Main controller
4x Ultrasonic Sensor (AJ-SR04M)	For distance measurements
Nextion NX4827T043_011	Touchscreen for user interface (UI)
4x Buzzer	Audio alerts from front, rear, left, and right
Jumper Wires	For connections
5V Power Supply	To power the ESP32 and sensors


🧠 Software Features
FreeRTOS-based task structure:

sensorTask: Periodically performs distance measurements.

pageTask: Listens to data from the Nextion display and handles page transitions.

displayTask: Updates the screen and buzzers according to measured distances.

Uses semaphores to synchronize data received via UART (Serial2).

The user can select a vehicle type from the Nextion screen and switch to parking mode.

---

## 🔧 Wiring Diagram (Pin Mapping)
ESP32 Pin	Connected Device
GPIO 21	Front sensor Trig
GPIO 25	Front sensor Echo
GPIO 18	Rear sensor Trig
GPIO 27	Rear sensor Echo
GPIO 33	Left sensor Trig
GPIO 32	Left sensor Echo
GPIO 19	Right sensor Trig
GPIO 26	Right sensor Echo
GPIO 15	Front Buzzer
GPIO 2	Rear Buzzer
GPIO 4	Right Buzzer
GPIO 16	Nextion RX (ESP32 TXD2)
GPIO 17	Nextion TX (ESP32 RXD2)


▶️ How to Use
Connect the ESP32 to your computer.

Upload the code using Arduino IDE or PlatformIO.

Load the .tft file to the Nextion display to set up the interface.

Make power connections to start the system.

Select a vehicle type on the screen and enter parking mode.

The sensors will activate, and distance measurements and alerts will begin.


---

🧩 Libraries
The project includes the following custom libraries (should be in your file structure):

UltrasonicSensor.h / .cpp – Distance measurement from sensors

Nextion.h / .cpp – Control of the Nextion display

Buzzer.h / .cpp – Buzzer control




📝 License
This project is open-source and free to use. Please give credit when sharing ⭐

---


Let me know if you'd like a more formal version or if you're preparing this for a portfolio, competition, or presentation..  
