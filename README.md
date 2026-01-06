Arduino Sensor Hub

Overview
The Arduino Sensor Hub is a modular embedded systems project built using PlatformIO in Visual Studio Code. The system is designed to read data from multiple sensors, apply basic signal filtering, and stream structured data over the serial interface. The project emphasizes clean architecture, non-blocking execution, and scalability for future sensor expansion.

This repository serves as a portfolio-grade example of embedded programming using modern development tools.
I didnt have the aurdino board to test it.


Features

* Supports multiple analog sensors
* Moving average filtering to reduce signal noise
* Non-blocking timing using millis()
* Structured serial output suitable for logging and analysis
* Modular and extensible project layout



Technology Stack

* Programming Language: C++
* Framework: Arduino
* IDE: Visual Studio Code
* Build System: PlatformIO
* Supported Boards: Arduino Uno, Nano, Mega



Project Structure

arduino-sensor-hub/
├── src/
│   └── main.cpp        Core application logic
├── include/            Header file directory
├── lib/                Optional custom libraries
├── platformio.ini      PlatformIO configuration
└── README.md           Project documentation



Setup Instructions

1. Install Visual Studio Code
2. Install the PlatformIO IDE extension
3. Connect an Arduino board via USB
4. Clone this repository

git clone [https://github.com/yousifsarhan/arduino-sensor-hub.git](https://github.com/yousifsarhan/arduino-sensor-hub.git)
cd arduino-sensor-hub

5. Open the project folder in Visual Studio Code
6. Select the correct board in platformio.ini
7. Build and upload the project using PlatformIO
8. Open the serial monitor at 115200 baud



Serial Output Format

The sensor hub outputs comma-separated values over the serial interface.

Example output:

ms,A0_raw,A0_filt,A1_raw,A1_filt
1234,512,498,300,295

Field description:

* ms: milliseconds since system start
* raw: direct ADC reading
* filt: filtered sensor value

This format is compatible with spreadsheet software and external data processing tools.



Adding Sensors

To add additional analog sensors, update the analog pin array in the source code. The system automatically handles reading, filtering, and streaming without duplicating logic.


Potential Extensions

* Support for I2C sensors
* JSON-formatted serial output
* SD card data logging
* Wireless communication using ESP32
* Sensor calibration profiles



Use Cases

* Embedded systems coursework
* Sensor data logging
* IoT prototyping
* Engineering portfolio demonstration


Author

Yousif Sarhan
Bahrain
Information Technology and Multimedia Systems

GitHub: [https://github.com/yousifsarhan](https://github.com/yousifsarhan)
Portfolio: [https://yousifsarhan.github.io/computerscienceportfolio/](https://yousifsarhan.github.io/computerscienceportfolio/)


License

This project is released for educational and personal use.
