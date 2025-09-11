#include <stdio.h>

void task05_second_largest() {
    // Find the second largest element in an array
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);  //size of array
    int largest = a[0], second = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if(a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    printf("Second largest element is: %d\n", second);
}

int main() {
    
    task05_second_largest();
    return 0;
}

