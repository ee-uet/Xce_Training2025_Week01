#include <stdio.h>

// add function ka prototype
int add(int a, int b);

int main() {
    int x = 27;
    int y = 15;
    int result;
    int result1;

    result = add(x, y);  // call the add function
    result1 = subtract(x, y);  // call the subtract function

    printf("Sum = %d\n", result);
    printf("Subtraction = %d\n", result1);

    return 0;
}
