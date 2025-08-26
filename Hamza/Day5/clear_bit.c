#include <stdio.h>
unsigned int set_bit(unsigned int num, int pos) {
    return num | (1 << pos);
}
unsigned int clear_bit(unsigned int num, int pos) {
    return num & ~(1 << pos);
}
int main() {
    unsigned int num = 10; 
    int pos = 1;
    unsigned int result_set = set_bit(num, pos);
    printf("Set bit at pos %d: %u\n", pos, result_set); // 12 (1100)
    unsigned int result_clear = clear_bit(num, pos);
    printf("Clear bit at pos %d: %u\n", pos, result_clear); //  8 (1000)

    return 0;
}
