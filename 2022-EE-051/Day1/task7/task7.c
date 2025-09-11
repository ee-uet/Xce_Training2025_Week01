#include <stdio.h>

void task07_bitwise_ops() {
    // Demonstrate AND, OR, XOR, NOT, shifts
    int x = 5;
    int y = 9;

    printf("x = %d, y = %d\n", x, y);
    printf("x & y = %d\n", x & y);
    printf("x | y = %d\n", x | y);
    printf("x ^ y = %d\n", x ^ y);
    printf("~x = %d\n", ~x);
    printf("x << 1 = %d\n", x << 1);
    printf("y >> 2 = %d\n", y >> 2);

    // Bonus: Check if number is power of 2
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("%d is NOT a power of 2\n", num);
        return;
    }

    while (num % 2 == 0) {
        num /= 2;
    }

    if (num == 1) {
        printf("YES, it is a power of 2\n");
    } else {
        printf("NO, not a power of 2\n");
    }

}

int main(){
    task07_bitwise_ops();
    return 0;
}
