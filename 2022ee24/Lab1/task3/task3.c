#include <stdio.h>
#include <stdlib.h>

void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;
    int num1 = 0;
    int num2 = 1;

    printf("Enter n = ");
    scanf("%d",&n);

    printf("%d,%d,",num1,num2);

    for (int i=0;i<n-2;i++)
    {   
        int temp = num1+num2;
        printf("%d,",temp);
        num1 = num2;
        num2 = temp;
    }
    printf("\n");
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int random_num = rand() % 101;  //random num b/w 0 to 100
    int guess = 101;
    int count = 0;
    while (guess != random_num)
    {
        printf("Enter guess(again): ");
        scanf("%d",&guess);
        count += 1;

        if ((guess-random_num) >= 25)
        {
            printf("guess is too high\n");
        }

        else if ((guess-random_num) <= -25)
        {
            printf("guess is too low\n");
        }
        
    }
    printf("You took %d tries\n",count);
}

int main()
{
    task03_fibonacci();
    task03_guessing_game();
    return 0;
}