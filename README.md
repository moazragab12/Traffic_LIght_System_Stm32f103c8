# Traffic Light System for STM32F103C8

A simple and effective embedded system project that simulates a traffic light with pedestrian crossing, built for the STM32F103C8 microcontroller using the C language.

## Overview

This project implements a traffic light controller that allows pedestrians to cross the road safely. When a pedestrian presses a button, the system waits a few milliseconds, then blinks the yellow LEDs to warn both cars and pedestrians, providing time for everyone to get ready before the light changes.

## Features

- **Pedestrian Button**: Pedestrians can request to cross by pressing a button.
- **Yellow LED Blinking**: Yellow LEDs blink to give a transition warning before the red/green change.
- **Interrupt-Driven**: Button presses are handled using hardware interrupts for responsiveness.
- **STM32F103C8**: Designed specifically for this popular ARM Cortex-M3 microcontroller.
- **Embedded C**: All logic is implemented in C for maximum performance and portability.

## Hardware Requirements

- STM32F103C8 ("Blue Pill") microcontroller board
- LEDs (Red, Yellow, Green) for both vehicle and pedestrian signals
- Push button for pedestrian crossing request
- Resistors for LEDs and button
- Breadboard and jumper wires for prototyping
- Power supply (typically via USB or 5V/3.3V adapter)

## Software Requirements

- STM32CubeIDE or Keil uVision (or any preferred ARM IDE)
- STM32 HAL libraries (usually included with IDE)
- ST-Link programmer/debugger (if flashing directly to hardware)

## Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/moazragab12/Traffic_LIght_System_Stm32f103c8.git
   ```

2. **Open the project** in your preferred STM32 IDE.

3. **Connect the hardware** as per the schematic (see `docs/` or source comments for pin configuration).

4. **Build and flash** the code to your STM32F103C8 board.

5. **Test** by pressing the pedestrian button and observing the LED sequence.

## Project Structure

- `src/` - Source code files
- `inc/` - Header files
- `README.md` - Project documentation (this file)

## How It Works

1. **Normal Operation**: Vehicles have a green light; pedestrians have a red light.
2. **Pedestrian Request**: When the button is pressed, after a short delay, yellow LEDs blink for both directions.
3. **Transition**: Vehicle light turns red, pedestrian light turns green, allowing safe crossing.
4. **Reset**: After a set time, the system returns to normal operation.

## Topics & Concepts

- Embedded C programming
- STM32 HAL/LL drivers
- Hardware interrupts
- State machines for embedded systems

## License

This project is open source. See the repository for license information.

---

> **Created by [moazragab12](https://github.com/moazragab12)**
