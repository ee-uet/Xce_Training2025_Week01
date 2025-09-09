#include <stdio.h>
#include <stdint.h>

unsigned int set_bit(unsigned int n, unsigned int k) {
    return n | (1 << k);
}

unsigned int clear_bit(unsigned int n, unsigned int k) {
    return n & ~(1 << k);
}

int main() {
    unsigned int num = 5; 

    printf("Number: %d\n", num);
    printf("Set bit 5: %d\n", set_bit(num, 1));
    printf("Clear bit 5: %d\n", clear_bit(num, 1));

    return 0;
}