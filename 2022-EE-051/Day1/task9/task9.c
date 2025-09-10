#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
    
};
void task09_struct_distance() {
    // Take two points and calculate Euclidean distance
     struct Point p1, p2;
    // Taking the coordinates from the user
    printf("Enter coordinates of first point (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of second point (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    double distance = sqrt((p2.x - p1.x) * (p2.x - p1.x) +
                           (p2.y - p1.y) * (p2.y - p1.y));

    printf("Euclidean Distance = %.2f\n", distance);
}

int main(){
    task09_struct_distance();
    return 0;
}
