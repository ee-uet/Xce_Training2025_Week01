#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate the square root using binary search
double sqrt_binary(double x, double precision = 1e-6) {
    double low = 0.0;
    double high = 1.0; // Fixed high value, similar to Verilog
    double mid;

    // If x is larger than 1, adjust the high value
    if (x > 1.0) {
        high = x;
    }

    // Perform the binary search
    while ((high - low) >= precision) {
        mid = (low + high) / 2.0;
        if (mid * mid > x) {
            high = mid; // Move the high boundary
        } else {
            low = mid; // Move the low boundary
        }
    }

    return mid; // Final estimate of the square root
}

int main() {
    double x;

    cout << "Enter a number to find its square root: ";
    cin >> x;

    // Calculate square root using binary search
    double result = sqrt_binary(x);

    // Output the result with precision
    cout << fixed << setprecision(6);
    cout << "Square root of " << x << " is: " << result << endl;






    return 0;
    }

