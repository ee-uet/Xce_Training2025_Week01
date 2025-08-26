volatile int tohost;

void _start() {
    int rem = 0;
    int num = 13;
    int den = 3;
    int quot = num;
    int cnt = 32;
    int bit;
    for(int i = 0;i<cnt;i++) {
        bit = 1 << (cnt - 1);
        bit = quot & bit;
        bit = bit >> (cnt - 1);
        rem = rem << 1;
        rem = rem | bit;
        quot = quot & (~(1 << (cnt - 1)));
        quot = quot << 1;
        if (rem >= 0) {
            rem = rem - den;
            if (rem >= 0) {
                quot = quot | 1;
            }
        } else {
            rem = rem + den;
            if (rem >= 0) {
                quot = quot | 1;
            }
        }
        
    }

    tohost = 1;
    while (1);
}