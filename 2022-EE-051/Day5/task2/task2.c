// #include <stdio.h>

int main() {
    volatile int num = 0x55;

    // Bit position we want to modify
    volatile int pos = 3;

    // Value to set (1 = set the bit, 0 = clear the bit)
    volatile int value = 1;

    // Create a mask with 1 at the desired bit position
    int mask = 1 << pos;

    // If value = 1, set the bit using OR
    // If value = 0, clear the bit using AND with inverted mask
    if (value)
        num |= mask;      // Set bit at 'pos'
    else
        num &= ~mask;     // Clear bit at 'pos'

   // printf("Updated num = 0x%X\n", num);

    return 0;
}
