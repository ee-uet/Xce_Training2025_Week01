#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator
    printf("\n");
    printf("Task2\n");
    int x,y;
    printf("Enter value of x:");
    scanf("%d",&x);
    printf("Enter value of y:");
    scanf("%d",&y);
    char operation;
    printf("x = %d\n",x);
    printf("y = %d\n",y);
    printf("x + y = %d\n",x + y);
    printf("x - y = %d\n",x - y);
    printf("x * y = %d\n",x * y);
    printf("x / y = %d\n", x/y);
    printf("x %% y = %d\n", x%y);
    printf("Enter operation:");
    scanf(" %c",&operation);
    switch(operation) {
    case '+':
     printf("x + y = %d\n",x + y);
    break;
    case '-':
     printf("x - y = %d\n",x - y);
    break;
    case '*':
     printf("x * y = %d\n",x * y);
    break;
    case '/':
     printf("x / y = %d\n", x/y);
    break;
    case '%':
     printf("x %% y = %d\n", x%y);
    break;
}
}


// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    
     task02_calculator();
    

    return 0;
}
