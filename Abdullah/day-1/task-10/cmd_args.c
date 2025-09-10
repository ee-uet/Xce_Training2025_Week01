#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    int sum;
    int num1 = atoi(argv[1]);       // Convert first argument to integer
    int num2 = atoi(argv[2]);       // Convert second argument to integer
    sum = num1 + num2;
    printf("Sum is %d\n", sum);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    task10_cmd_args(argc, argv);    // argc = number of arguments and argv = argument vector
    return 0;
}