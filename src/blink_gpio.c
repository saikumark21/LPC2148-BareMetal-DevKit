#include"lpc214x.h"

void delay() {
    for (volatile int i = 0; i < 500000; i++);
}

int main() {
    IO0DIR |= (1 << 10);  // Set P0.10 as output

    while (1) {
        IO0SET = (1 << 10);  // LED ON
        delay();
        IO0CLR = (1 << 10);  // LED OFF
        delay();
    }
}
