#include <stdio.h>

void task01_datatypes() {
   // TODO: Declare int, float, double, char
  // Print their sizes and demonstrate type casting
    int w = 13;
    float x = 3.1439;
    double y = 2.3589;
    char z = 'Z';

    printf("Integer value is %d, size = %zu bytes\n", w, sizeof(w));
    printf("Float value is %f, size = %zu bytes\n", x, sizeof(x));
    printf("Double value is %f, size = %zu bytes\n", y, sizeof(y));
    printf("Char value is %c, size = %zu bytes\n", z, sizeof(z));

    printf("Integer to float: %f\n", (float)w);
    printf("Double to integer: %d\n", (int)y);
}

int main() {

    task01_datatypes();
    return 0;
}

