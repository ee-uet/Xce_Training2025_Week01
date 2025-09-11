#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int x,y;
    x = 8; y = 16;
    printf("x & y %d\n", x & y );           // AND OP
    printf("x | y = %d\n", x | y);          // OR OP
    printf("x ^ y = %d\n", x ^ y);          // XOR OP
    printf("~x = %d\n", ~x);                // NOT OP
    printf("x << 1 = %d\n", x << 1);        // LEFT SHIFT OP
    printf("x >> 1 = %d\n", x >> 1);        // RIGHT SHIFT OP

    // Bonus: Check if number is power of 2
    printf("Enter number: ");
    int n;
    scanf("%d", &n);
    if ( n > 0 && ((n & n-1) == 0))         // A number is power of 2 if it has only one bit set
    {
        printf("%d number is the power of 2\n",n);
    }
    else{
        printf("%d is not power of 2.\n", n);
    }
}

int main() {
    task07_bitwise_ops();
    return 0;
}