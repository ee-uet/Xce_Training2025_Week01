int main() {
    int dividend = 13;   // number to be divided
    int divisor = 3;     // divisor

    int n = 4;
    int quotient = 0;
    int remainder = 0;

    for (int i = n - 1; i >= 0; i--) {
        remainder = (remainder << 1) | ((dividend >> i) & 1);
        remainder = remainder - divisor;

        if (remainder < 0) {
            remainder = remainder + divisor;
            quotient = (quotient << 1) | 0;
        } else {
            quotient = (quotient << 1) | 1;
        }
    }

    while(1);  // infinite loop to prevent program exit
}

