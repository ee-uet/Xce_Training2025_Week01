

int main() {
    int divisor = 4;
    int dividend = 43;
    int remainder = 0;
    int quotient = 0;
    int size = 32;
    int i, temp;
    int mask;

    for(i = size - 1; i >= 0; i--) {
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        if(remainder >= 0) {
            temp = remainder - divisor;
        } else {
            temp = remainder + divisor;
        }

        if(temp >= 0) {
            remainder = temp;
            mask = 1 << i;
            quotient = quotient | mask;
        } else {
            remainder = temp;
        }
    }
     if(remainder < 0){
         remainder+=divisor;
     }
    printf("%d,%d",remainder,quotient);
    return 0;
}
