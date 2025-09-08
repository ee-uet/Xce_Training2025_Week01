#include <stdio.h>

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    int x, y;
    x = 5; 
    y = 9;

    // Demonstrate basic bitwise operations
    printf("x & y = %d\n", x & y);   // AND: only bits set in both x and y
    printf("x | y = %d\n", x | y);   // OR: bits set in either x or y
    printf("x ^ y = %d\n", x ^ y);   // XOR: bits set in x or y, but not both
    printf("~x = %d\n", ~x);         // NOT: flips all bits of x (two's complement)
    printf("x << 1 = %d\n", x << 1); // Left shift: multiply x by 2
    printf("x >> 1 = %d\n", x >> 1); // Right shift: divide x by 2 (floor)

    // Bonus: Check if number is power of 2
    printf("Enter any Integer: ");
    int n;
    scanf("%d", &n);

    // A number is power of 2 if n > 0 and n has only 1 set bit
    // (n & (n-1)) clears the lowest set bit, result is 0 if only 1 bit was set
    if (n > 0 && ((n & (n - 1)) == 0)) {
        printf("%d is a power of 2\n", n);
    } else {
        printf("%d is NOT a power of 2\n", n);
    }
}

// Main function to test Task 0.7
int main() {
    task07_bitwise_ops();
    return 0;
}

