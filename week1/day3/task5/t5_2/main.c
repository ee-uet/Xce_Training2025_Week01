#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main() {
    printf("Sum: %d\n", add(3, 4));
    printf("Diff: %d\n", sub(9, 2));
    printf("Mul: %d\n", mul(5, 3));
    return 0;
}
