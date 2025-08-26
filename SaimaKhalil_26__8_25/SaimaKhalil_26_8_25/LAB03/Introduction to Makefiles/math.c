#include "math.h"

// Multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Integer division (no remainder handling)
int divide(int a, int b) {
    if (b == 0) return 0; // simple check to avoid divide-by-zero
    return a / b;
}
