#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    int num1 = atoi(argv[1]); 
    int num2 = atoi(argv[2]); 


    int sum = num1 + num2;

    printf("Sum = %d\n", sum);
}
// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
    task10_cmd_args(argc, argv);

    return 0;
}
