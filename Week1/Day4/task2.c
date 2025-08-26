int main() {
    volatile int num = 0x55;
    volatile int pos = 3;
    volatile int value = 1;

    int mask = 1 << pos;

    if (value)
        num |= mask;
    else
        num &= ~mask;

    return num;
}

