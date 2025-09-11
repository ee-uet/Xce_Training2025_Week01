#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ======================= Task 0.9 =======================
// Define a struct for a 2D point
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    struct Point p1, p2;
    printf("Enter coordinates of p1(x,y): ");
    scanf("%d %d",&p1.x, &p1.y);
    printf("Enter coordinates of p2(x,y): ");
    scanf("%d %d",&p2.x, &p2.y);

    // Calculate Euclidean distance
    double distance = sqrt ( pow(p2.x - p1.x,2) + pow(p2.y - p1.y, 2));
    printf("Euclidean Distance : %.3f\n", distance);
}

int main() {
    task09_struct_distance();
    return 0;
}