#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    float dist;
    int temp1,temp2;
    struct Point p1;
    struct Point p2;
    printf("Enter P1(x,y) = ");
    scanf("%d,%d",&p1.x,&p1.y);
    printf("Enter P2(x,y) = ");
    scanf("%d,%d",&p2.x,&p2.y);
    temp1 = p2.y - p1.y;
    temp2 = p2.x - p1.x;
    dist = sqrt((temp1*temp1)+(temp2*temp2));
    printf("dist = %f\n",dist);
}

int main()
{
    task09_struct_distance();
    return 0;
}