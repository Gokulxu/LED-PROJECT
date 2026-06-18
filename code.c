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
