#include <stdio.h>
#include <math.h>

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};


void task09_struct_distance() {
    struct Point p1, p2;
    double distance;

    printf("Enter coordinates of first point (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of second point (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    // Euclidean distance formula:
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    printf("Euclidean Distance = %.2f\n", distance);
}

// ======================= Main =======================
int main() {

    task09_struct_distance();
    
    return 0;
}
