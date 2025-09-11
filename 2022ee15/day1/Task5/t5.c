#include <stdio.h>

// ======================= Task 0.5 =======================

// Reverse a string without using library functions
void task05_reverse_string() {
    char name[50] = "hello world";
    int length = 0;

    // Count string length manually
    while (name[length] != '\0') {
        length++;
    }

    // Print characters in reverse order
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }
    printf("\n");
}

// Find the second largest element in an array
void task05_second_largest() {
    int arr[] = {1, 5, 29, 7, 43, 40};
    int length = (sizeof(arr)) / 4; // assumes int = 4 bytes (⚠ not portable)

    int max = arr[0];
    int second_max = arr[0];

    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            // current element is new max, so push old max into second_max
            second_max = max;
            max = arr[i];
        } else if ((arr[i] > second_max) && (arr[i] != max)) {
            // update second_max if current element is less than max but greater than second_max
            second_max = arr[i];
        }
    }
    printf("Second highest is: %d\n", second_max);
}

// Main function to test Task 0.5
int main() {
    printf("Reversed string:\n");
    task05_reverse_string();

    printf("Finding second largest element:\n");
    task05_second_largest();

    return 0;
}

