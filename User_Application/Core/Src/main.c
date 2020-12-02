#include "main.h"
#include "stdio.h"

//delay
void delay1(void);


/*
 * Initialize the GPIO pins
 */
void gpioinit(void) {

    RCC_AHB1_CLKEN(RCC_AHB1Peri_GPIOA);
    GPIO_Config(GPIOA, 5, Output_Mode, Pull_Down, No_AF);
}

/*
 * Main functions begins
 */
int main(void) {

    gpioinit();

    while (1) {

        GPIO_Toggle(GPIOA, 5);
        delay1();
        delay1();
    }

    return 0;
}

void delay1(void) {
    unsigned static volatile long i = 0;
    unsigned static volatile long j = 0;
    for (i = 0; i < 2000; i++) {
        for (j = 0; j < 400;) {
            j++;
        }
    }
}

