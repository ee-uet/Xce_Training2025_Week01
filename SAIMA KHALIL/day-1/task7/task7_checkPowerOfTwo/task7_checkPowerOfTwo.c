#include <stdio.h>
#include <stdlib.h>

void checkPowerOfTwo() {
    int num;    
    printf("Enter a number to check if it's a power of 2: ");
    scanf("%d", &num);
    if (num > 0 && (num & (num - 1)) == 0) { // power of 2 has exactly one bit set in binary , subtracting 1 flips all the bits after that 1.so, num & (num-1) will always be 0 for powers of 2.
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }
} 

int main(){
    checkPowerOfTwo();
    return 0;
}