#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    
     int array[] = {1, 2};
int n = sizeof(array) / sizeof(array[0]);

// Sort array in descending order 
for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
        if (array[j] < array[j+1]) {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
}

printf("Second largest element is: %d\n", array[1]);

    
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
    
     task05_second_largest();
  

    return 0;
}
