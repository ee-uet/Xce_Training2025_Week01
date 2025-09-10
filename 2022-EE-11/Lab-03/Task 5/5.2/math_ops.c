#include "math_ops.h"

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    return 0.0;
}