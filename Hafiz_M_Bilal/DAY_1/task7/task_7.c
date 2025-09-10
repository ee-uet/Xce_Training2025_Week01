#include <stdio.h>
#include <stdbool.h>

bool is_power_of_two(int n) {
    // (n > 0) ensures the number is positive
    // (n & (n - 1)) == 0 → true only if n has exactly one bit set
    return (n > 0) && ((n & (n - 1)) == 0);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int x = 5; 
    int y = 9; 

    printf("x = %d, y = %d\n", x, y);
    printf("x & y = %d\n", x & y);   
    printf("x | y = %d\n", x | y);   
    printf("x ^ y = %d\n", x ^ y);   
    printf("~x = %d\n", ~x);         
    printf("~y = %d\n", ~y);         
    printf("x << 1 = %d\n", x << 1); 
    printf("y << 1 = %d\n", y << 1);
    printf("x >> 1 = %d\n", x >> 1); 
    printf("y >> 1 = %d\n", y >> 1);

    // Power of 2 check
    int num;
    printf("\nEnter a number to check if it is power of 2: ");
    scanf("%d", &num);

    if (is_power_of_two(num))
        printf("%d is a power of 2\n", num);
    else
        printf("%d is NOT a power of 2\n", num);
}

// ======================= Main =======================
int main() {

    task07_bitwise_ops();
    
    return 0;
}