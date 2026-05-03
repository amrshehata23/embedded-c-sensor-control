# Embedded C Sensor Control

## Overview
This project demonstrates basic embedded C programming concepts for sensor reading, actuator control and threshold-based system logic.

The project simulates a simple microcontroller-style control system that reads temperature and light sensor values, controls a fan and an LED, and prints warning messages depending on sensor conditions.

The goal is to show structured C programming for embedded systems and mechatronics applications.

## Main Features
- Simulated temperature sensor reading
- Simulated light sensor reading
- Fan control based on temperature threshold
- LED control based on light threshold
- Warning detection
- Threshold-based control logic
- Structured C functions
- Microcontroller-style program flow

## Technologies Used
- C Programming
- Embedded C Concepts
- Sensor Logic
- Actuator Control
- Threshold Control
- Mechatronics
- Microcontroller-Style Programming

## Repository Structure

```text
embedded-c-sensor-control/
│
├── README.md           # Project documentation
├── sensor_control.c    # Main C source code
├── system_logic.md     # Explanation of system logic
└── requirements.md     # Required software
ystem Concept
Temperature Sensor Input
        ↓
Threshold Check
        ↓
Fan Control

Light Sensor Input
        ↓
Threshold Check
        ↓
LED Control
Control Logic
Temperature Control

If the temperature is higher than the limit, the fan turns on.

temperature > 28.0°C → Fan ON
temperature <= 28.0°C → Fan OFF
Light Control

If the light value is lower than the limit, the LED turns on.

light_value < 400 → LED ON
light_value >= 400 → LED OFF
Project Purpose

The purpose of this project is to demonstrate basic embedded C logic in a simple and understandable way.

It connects:

C programming
sensor values
threshold logic
actuator control
embedded systems thinking
mechatronics applications
What I Learned
How to structure an embedded-style C program
How to use functions for different system parts
How to simulate sensor readings
How threshold logic controls actuators
How C can be used in embedded and mechatronics systems
How to document a technical C project
Possible Applications
Embedded systems basics
Sensor control systems
Smart home systems
Mechatronics projects
Microcontroller programming
Automotive sensor monitoring concepts
Future Improvements
Connect the logic to real microcontroller hardware
Add more sensors
Add motor control logic
Add state machine design
Add unit tests
Add serial communication concept
Add safety error handling
Project Status

This project was created as an Embedded C portfolio project for sensor control and microcontroller-style programming.
