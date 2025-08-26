
int main() {
    unsigned int dividend = 77, divisor = 7;
    unsigned int quotient = 0, rem = 0;  

    for(int i = 31; i >= 0; i--){
        rem = rem << 1;
        if ((dividend >> i) & 1) {
            rem = rem | 1;
        }
        if(rem >= divisor){
            rem = rem - divisor;
            quotient = quotient | (1U << i);
        }
    }

    volatile unsigned int *q = (unsigned int*)0x80000000;
    volatile unsigned int *r = (unsigned int*)0x80000004;
    *q = quotient;
    *r = rem;

    return 0;
}

