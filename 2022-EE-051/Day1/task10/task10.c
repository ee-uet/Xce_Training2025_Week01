#include <stdio.h>
#include <stdlib.h>

void task10_cmd_args(int argc, char *argv[]) {
    // Need 3 arguments in command line
	if (argc < 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
    }
    // Take 2 integers as command line args and print sum
    // atoi converts string to integer
    int num1 = atoi(argv[1]);  
    int num2 = atoi(argv[2]);  
    int sum = num1 + num2;

    printf("Sum = %d\n", sum);
}

int main(int argc, char *argv[]) {
    task10_cmd_args(argc, argv);
    return 0;
}
