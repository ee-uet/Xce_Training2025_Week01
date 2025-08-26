int main() {
    unsigned int num = 0b10101010;
    int bit_to_set = 3;
    int bit_to_clear = 5;

    // Set bit 3
    num = num | (1 << bit_to_set);

    // Clear bit 5
    num = num & ~(1 << bit_to_clear);

    
    volatile int *tohost = (int *)0x80001000;
    *tohost = 1;
    return 0;
}
