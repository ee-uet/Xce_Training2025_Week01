#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void task03_guessing_game() {
    // Implement guessing game with random number
    int target = rand() % 101;
    int guess;
   
    while(1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
    // number should only be from 1 to 100
        if(guess < 1 || guess > 100) {
            printf("Out of range!\n");
            continue;
        }
    // Tells the user if the number entered is lower or higher than the randomly generated number
        if(guess < target)
            printf("Too Low!\n");
        else if(guess > target)
            printf("Too High!\n");
        else {
            printf("Correct! The number was %d.\n", target);
            break;
        }
    }
}

int main() {
    // is used in order to generate unique sequence of numbers each time 
    srand(time(0));
    task03_guessing_game();
    return 0;
}

