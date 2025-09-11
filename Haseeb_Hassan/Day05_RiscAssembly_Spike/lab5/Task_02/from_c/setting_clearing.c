unsigned set_bit(unsigned num, unsigned pos) {
    return num | (1u << pos);
}

unsigned clear_bit(unsigned num, unsigned pos) {
    return num & ~(1u << pos);
}

int main() {
    unsigned n = 0x55AA55AA;
    unsigned pos = 3;

    n = set_bit(n, pos);     // Set bit
    n = clear_bit(n, pos);   // Clear bit

    while (1); // infinite loop like assembly
    return 0;
}