#include <stdio.h>

// add function ka prototype
int add(int a, int b);

int main() {
    int x = 15;
    int y = 27;
    int result;

    result = add(x, y);  // call the add function

    printf("Sum = %d\n", result);

    return 0;
}
