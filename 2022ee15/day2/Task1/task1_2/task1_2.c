#include <stdio.h>

// function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;   // store value of *a temporarily
    *a = *b;         // assign value of *b to *a
    *b = temp;       // put temp (old *a) into *b
}

int main() {
    int x = 5, y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    // calling swap with addresses of x and y
    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

