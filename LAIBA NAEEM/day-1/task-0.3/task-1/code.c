#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
   int number;
   int x = 0;
   int y = 1;
   int z;
   printf("\n");
   printf("Task 3 : Fibonacci Sequence\n");
   printf("Enter number:");
   scanf("%d",&number);
   for ( int i = 0; i<number; i++){
    printf("%d\n",x);
    z = x + y;
    x = y; 
    y = z; 
}
}



// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
     task03_fibonacci();
    
    

    return 0;
}
