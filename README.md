# PIC18F4580-LED-Project


## 💡 Project Description

This project demonstrates how to control eight LEDs connected to PORTD of a PIC18F4580 microcontroller using five push buttons connected to PORTB. Each button triggers a unique LED illumination pattern, showcasing different methods of LED control and digital input handling in embedded systems.

---

## 🛠️ Hardware Components

* PIC18F4580 Microcontroller
* 8 × Red LEDs
* 5 × Push Buttons
* 8 × 220Ω Current Limiting Resistors
* 5 × 10kΩ Pull-up Resistors
* 8MHz Crystal Oscillator
* 2 × 22pF Capacitors
* 5V Power Supply
* Breadboard and Connecting Wires

### Circuit Connections

#### LEDs

* RD0 → LED1
* RD1 → LED2
* RD2 → LED3
* RD3 → LED4
* RD4 → LED5
* RD5 → LED6
* RD6 → LED7
* RD7 → LED8

#### Push Buttons

* RB0 → Button 1
* RB1 → Button 2
* RB2 → Button 3
* RB3 → Button 4
* RB4 → Button 5

Each button is connected with a 10kΩ pull-up resistor to +5V and switches to GND when pressed.

---

## 💻 Software Requirements

* MPLAB X IDE
* XC8 Compiler
* PIC18F4580 Header File (`<pic18.h>`)
* Proteus Design Suite (Optional)

---

## 🚀 Project Operation

The microcontroller continuously monitors the state of five push buttons connected to PORTB.

When a button is pressed, the corresponding LED pattern is executed on PORTD.

---

## ✨ LED Patterns

| Button | Pattern Description                          |
| ------ | -------------------------------------------- |
| RB0    | Sequential LED Lighting (RD0 → RD7)          |
| RB1    | All LEDs Blink Together                      |
| RB2    | Alternating Pattern (0xAA ↔ 0x55)            |
| RB3    | Checkerboard Pattern (0xCC ↔ 0x33)           |
| RB4    | Diagonal Pattern (0x81 → 0x42 → 0x24 → 0x18) |

---

## 📂 Source Code

```c
#include <pic18.h>

// Delay function
void delay() {
    int i, j;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
        }
    }
}

// Pattern 1: Sequential lighting
void pattern1() {
    int i;
    for (i = 0; i < 8; i++) {
        LATD = 1 << i;
        delay();
    }
    LATD = 0x00;
}

// Pattern 2: Blink all LEDs
void pattern2() {
    LATD = 0xFF;
    delay();
    LATD = 0x00;
    delay();
    LATD = 0xFF;
    delay();
}

// Pattern 3: Alternating pattern
void pattern3() {
    LATD = 0xAA;
    delay();
    LATD = 0x55;
    delay();
    LATD = 0xAA;
    delay();
}

// Pattern 4: Checkerboard pattern
void pattern4() {
    LATD = 0xCC;
    delay();
    LATD = 0x33;
    delay();
    LATD = 0xCC;
    delay();
}

// Pattern 5: Diagonal pattern
void pattern5() {
    LATD = 0x81;
    delay();
    LATD = 0x42;
    delay();
    LATD = 0x24;
    delay();
    LATD = 0x18;
    delay();
    LATD = 0x00;
}

void main(void) {

    TRISB = 0xFF;
    TRISD = 0x00;

    ADCON1 = 0x0F;

    while (1) {

        if (PORTBbits.RB0 == 0) {
            pattern1();
        }

        else if (PORTBbits.RB1 == 0) {
            pattern2();
        }

        else if (PORTBbits.RB2 == 0) {
            pattern3();
        }

        else if (PORTBbits.RB3 == 0) {
            pattern4();
        }

        else if (PORTBbits.RB4 == 0) {
            pattern5();
        }

        else {
            LATD = 0x00;
        }
    }

    return;
}
```

---

## ▶️ Steps to Use

1. Create a new MPLAB X project.
2. Select PIC18F4580 as the target device.
3. Choose XC8 as the compiler.
4. Add the source code to the project.
5. Build the project and generate the HEX file.
6. Load the HEX file into the PIC18F4580.
7. Connect the circuit according to the schematic.
8. Power the circuit.
9. Press any button connected to RB0–RB4.
10. Observe the corresponding LED pattern displayed on PORTD.

---

## 🧪 Proteus Simulation

### Required Components

* PIC18F4580
* 8 LEDs
* 5 Push Buttons
* 220Ω Resistors
* 10kΩ Resistors
* 8MHz Crystal
* 22pF Capacitors
* Power and Ground Terminals

### Simulation Procedure

1. Create a new Proteus project.
2. Place all required components.
3. Wire the circuit according to the schematic.
4. Load the generated HEX file into the PIC.
5. Set the clock frequency to 8MHz.
6. Run the simulation.
7. Press the virtual buttons and observe the LED patterns.

---

## 🔧 Hardware Implementation

1. Program the PIC18F4580 using PICkit 3 or PICkit 4.
2. Assemble the circuit on a breadboard or PCB.
3. Power the circuit using a regulated 5V supply.
4. Test each button and verify the LED patterns.

---

## ⚠️ Notes

* Delay timing depends on the oscillator frequency.
* Proper pull-up resistors are required for reliable button operation.
* Switch bounce may cause repeated triggering.
* LED brightness depends on resistor values and supply voltage.

---

## 📚 Applications

* Digital Input Demonstration
* LED Pattern Generation
* Embedded Systems Laboratory Experiments
* PIC Microcontroller Learning
* Human Machine Interface (HMI) Basics

---

## 📸 Circuit Diagram

 ![image alt](https://github.com/manubraj/PIC-MICROCONTROLLER-LED-Project/blob/b4b33a03c6abc26d5e523e479fd243354d5ffd34/led%20blink.png)

## 📄 License

This project is intended for educational and learning purposes. Users are free to modify and improve the code for academic and personal projects.

---

## 🙏 Acknowledgements

Developed and tested using:

* PIC18F4580 Microcontroller
* MPLAB X IDE
* XC8 Compiler
* Proteus Design Suite
* Standard Push Buttons and LEDs
