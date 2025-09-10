#include <stdio.h>
#include <stdlib.h>

void task03_guessing_game() 
{
    int guess,random_number;
    random_number=(rand()%100)+1;
    do
    {
        printf("Guess number : \n");
        scanf("%d",&guess);
        if(guess==random_number)
        {
            printf("Well,You got it right!\n");
        }
        else if(guess<random_number)
        {
             printf("Well,You are low!\n");
        }
        else if (guess>random_number)
        {
             printf("Well,You are high!\n");
        }   
    }
    while(guess!=random_number);     
}
int main()
{
    task03_guessing_game();
    return 0;
}