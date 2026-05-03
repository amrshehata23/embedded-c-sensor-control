# System Logic

## Overview
This document explains the control logic used in the Embedded C Sensor Control project.

The system simulates a basic embedded control system using temperature and light sensor values. Based on these values, the program controls a fan and an LED.

The system also uses hysteresis to prevent fast ON/OFF switching when sensor values are close to the threshold.

## Inputs

| Input | Description |
|---|---|
| Temperature | Simulated temperature value in degrees Celsius |
| Light value | Simulated analog light sensor value |

## Outputs

| Output | Description |
|---|---|
| Fan | Turns on when temperature is high |
| LED | Turns on when light level is low |
| Temperature warning | Triggered when temperature is above the warning limit |
| Low light warning | Triggered when light level is below the warning limit |

## Temperature Control Logic

The fan uses hysteresis:

```text
Fan ON  when temperature > 28.0°C
Fan OFF when temperature < 27.0°C

This prevents the fan from switching ON and OFF too quickly when the temperature is around 28°C.

Light Control Logic

The LED also uses hysteresis:

LED ON  when light value < 400
LED OFF when light value > 450

This prevents unstable LED switching when the light value is near the threshold.

Program Flow
Start program
      ↓
Initialize system state
      ↓
Initialize statistics
      ↓
Read simulated sensor sample
      ↓
Update temperature control
      ↓
Update light control
      ↓
Update statistics
      ↓
Print system status
      ↓
Repeat for next sample
      ↓
Print final summary
Statistics

At the end of the simulation, the program prints:

Average temperature
Maximum temperature
Minimum temperature
Average light value
Maximum light value
Minimum light value
Number of high temperature warnings
Number of low light warnings
Engineering Relevance

This logic is similar to basic embedded systems used in:

smart home systems
automotive sensor monitoring
environmental control
actuator control
microcontroller programming
mechatronics systems
Future Improvements
Replace simulated values with real ADC readings
Add state machine design
Add error handling for sensor faults
Add motor control logic
Add serial communication
Add unit tests
