#include <stdio.h>
#include <stdlib.h>

void task10_cmd_args(int argc, char *argv[]) { //argc is count,argv is  argument array
    if (argc != 3) {
        printf("Something went wrong here! \n");
        return;
    }
    int num1 = atoi(argv[1]);  
    int num2 = atoi(argv[2]);   
    printf("Sum is: %d\n", num1 + num2);
}

int main(int argc, char *argv[])
{
    task10_cmd_args(argc,argv);
    return 0;
}