# Smart Traffic Lights

A simple Arduino project that simulates a traffic light system using LEDs. This project demonstrates the use of basic electronic components to control lights in a sequence, replicating a real-world traffic signal system.

## Components

Below is the bill of materials (BOM) for this project:

| Name                                              | Quantity | Component      |
|:--------------------------------------------------|---------:|:---------------|
| U1                                                |        1 | ESP32S         |
| D5, D1, D8, D10                                   |        4 | Red LED        |
| D4, D2, D7, D11                                   |        4 | Yellow LED     |
| D6, D3, D9, D12                                   |        4 | Green LED      |
| R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12 |       12 | 220 Ω Resistor |

## Circuit Design

The image below shows the circuit design for this project. It includes wiring for LEDs representing red, yellow, and green lights, each connected to appropriate resistors to limit current and protect the components.

![Circuit Design](./circuit_design.png)

## How to Run

1. Connect the components as shown in the circuit design image.
2. Change the input pins respectively.
3. Upload the code to your Arduino/ESP.
4. The lights start to work automatically
5. You can change the green light time for each traffic light by inputting `green1: %d` or `green2: %d` respectively.

## Simulation Link

You can view and simulate this project on Tinkercad using the link below:

[Tinkercad Smart Traffic Lights Simulation](https://www.tinkercad.com/things/hdudYbIVgy7-daring-bombul)

