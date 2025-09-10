#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct Point {
    int x;
    int y;
};
void task09_struct_distance() {
  // TODO: Take two points and calculate Euclidean distance
  struct Point x1,x2; 
  float distance;
    printf("Enter x1,y1 ");
    scanf("%d %d", &x1.x, &x1.y);

    printf("Enter x2,y2 ");
    scanf("%d %d", &x2.x, &x2.y);

    distance = sqrt((x2.x - x1.x) * (x2.x - x1.x) +
                    (x2.y - x1.y) * (x2.y - x1.y));

    printf("Euclidean distance  = %f\n", distance);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
     task09_struct_distance();
   
    return 0;
}
