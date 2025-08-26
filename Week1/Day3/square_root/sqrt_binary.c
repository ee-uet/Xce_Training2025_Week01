#include <stdio.h>

double sqrt_binary_search(double x, double precision) {
    if (x < 0) {
        return -1; // Error: negative input
    }
    double low = 0, high = (x < 1) ? 1 : x;
    double mid;
    while ((high - low) > precision) {
        mid = (low + high) / 2;
        if (mid * mid < x) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return (low + high) / 2;
}
int main() {
    double x = 9.0;
    double precision = 1e-10;
    printf("sqrt(%.2f) ≈ %.10f\n", x, sqrt_binary_search(x, precision));
     return 0;
}


