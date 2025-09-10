#include <stdio.h>
#include <stdlib.h>

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    // Initialize array with predefined values
    int arr[10] = {99,55,83,993,939,223,12,0};
    int large = arr[0];                         // Largest element
    int second = 0;                             // Second largest element
    int len = 10;                               // Length of the array
    for(int i = 0;i < len;i++){

        if(large < arr[i]){                     // New largest found
            second = large;                     // Update second largest
            large = arr[i];                     // Update largest
        }
        else if (arr[i] > second && arr[i] != large) {
            second = arr[i];
        }        
    }
    printf("Second large number: %d\n",second);
}

int main() {
    task05_second_largest();
    return 0;
}