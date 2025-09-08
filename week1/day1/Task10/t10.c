#include <stdio.h>
#include <stdlib.h>   // For atoi()

// ======================= Task 0.10 =======================
// Function that takes command line arguments and prints their sum
void task10_cmd_args(int argc, char *argv[]) {
    // Ensure at least 2 numbers are provided
    if (argc < 3) {
        printf("Usage: ./a.out <num1> <num2>\n");
        return;
    }

    // Convert command line strings to integers
    int num_1 = atoi(argv[1]);
    int num_2 = atoi(argv[2]);

    // Compute sum
    int sum = num_1 + num_2;

    // Print result
    printf("Sum is %d\n", sum);
}

// Main function to call task10
int main(int argc, char *argv[]) {
    task10_cmd_args(argc, argv);
    return 0;
}

