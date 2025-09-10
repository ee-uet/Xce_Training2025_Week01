#include <stdio.h>
#include <stdlib.h>

void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc > 3)
    {
        printf("Error! only 2 arguments can be passed\n");
    }
    int sum = atoi(argv[1]) + atoi(argv[2]);
    printf("sum = %d\n",sum);
}

int main(int argc, char *argv[])
{
    task10_cmd_args(argc,argv);
    return 0;
}