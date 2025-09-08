#include <stdio.h>
#include <math.h>   // For sqrt() and pow()

// ======================= Task 0.9 =======================
// Define a structure to represent a 2D point
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // Take two points as input from user
    struct Point p1, p2;
    printf("Enter coordinates of p1(x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of p2(x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    // Calculate Euclidean distance using sqrt((x2-x1)^2 + (y2-y1)^2)
    double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    // Print result with 3 decimal precision
    printf("Euclidean Distance is %.3f\n", distance); 
}

// Main function to test Task 0.9
int main() {
    task09_struct_distance();
    return 0;
}

