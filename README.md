# Smart Gas Safety System

An ESP32-based gas detection and alert prototype designed to monitor gas levels and trigger an automated safety response when an abnormal reading is detected.

## About the Project

The project combines an ESP32 microcontroller with a gas sensor, buzzer, and servo mechanism to create a simple automated safety system.

The main goal was to explore how sensor data can be processed by a microcontroller and converted into an immediate physical response.

## Features

- Gas level monitoring using an analog sensor
- Threshold-based detection
- Audible alert when an abnormal reading is detected
- Servo-based automated response
- Serial Monitor output for observing sensor readings
- Built using ESP32 and Arduino/C++

## Components

- ESP32
- MQ-6 gas sensor
- Servo motor
- Buzzer
- Connecting wires
- Power supply

## Technologies Used

- C++
- Arduino
- ESP32
- Embedded Systems
- Sensor Data Processing

## How It Works

The ESP32 continuously reads the sensor value and compares it with a predefined threshold.

When the reading crosses the threshold, the system enters an alert state and activates the buzzer and servo mechanism.

When the reading returns to the normal range, the system returns to its normal state.

## What I Learned

Through this project, I learned about:

- Working with ESP32 GPIO and ADC inputs
- Reading and processing sensor data
- Controlling servo motors
- Using threshold-based logic
- Interfacing hardware with Arduino/C++
- Building a simple real-world automation prototype

## Project Status

Completed prototype.

Future improvements could include better calibration, a more robust detection algorithm, a user interface for monitoring, and improved reliability testing.

## Author

**Ananya Saxena**

Computer Science (Data Science) Student