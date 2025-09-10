#include <stdio.h>

// Task 3.1: Preprocessor Macros

// Macro to calculate square of a number
#define SQUARE(x) ((x) * (x))

// Macro to find max of two numbers
#define MAX2(a, b) (((a) > (b)) ? (a) : (b))

// Macro to find max of three numbers (using MAX2)
#define MAX3(a, b, c) (MAX2(MAX2((a), (b)), (c)))

// Macro to find max of four numbers (using MAX2)
#define MAX4(a, b, c, d) (MAX2(MAX2((a), (b)), MAX2((c), (d))))

// Macro to convert lowercase char to uppercase
#define TO_UPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - 'a' + 'A') : (c))

void task3_1_macros() {
    // Demonstrating all macros with sample test cases
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("MAX2(10, 20) = %d\n", MAX2(10, 20));
    printf("MAX3(5, 15, 10) = %d\n", MAX3(5, 15, 10));
    printf("MAX4(10, 20, 30, 25) = %d\n", MAX4(10, 20, 30, 25));
    printf("TO_UPPER('a') = %c\n", TO_UPPER('a'));
    printf("TO_UPPER('Z') = %c\n", TO_UPPER('Z')); // already uppercase
}

int main() {
    task3_1_macros();
    return 0;
}

