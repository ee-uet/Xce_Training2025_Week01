#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    struct Point p1, p2;
    printf("Enter coordinates of 1st point x and y : ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter coordinates of 2nd point x and y : ");
    scanf("%d %d", &p2.x, &p2.y);
    double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("Distance between points (%d, %d) and (%d, %d) is: %.5f\n", p1.x, p1.y, p2.x, p2.y, distance);
}

int main()
{
    task09_struct_distance();
    return 0;
}