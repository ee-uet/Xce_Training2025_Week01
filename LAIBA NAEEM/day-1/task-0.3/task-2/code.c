#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.3 =======================


void task03_guessing_game() {
   // TODO: Implement guessing game with random number
   printf("\n");
   printf("Task 3: Guessing Game\n");
   int guess;
   int number = (rand()%100)+1;
   printf("Random Number= %d\n",number);
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too High\n");
        } else if (guess < number) {
            printf("Too Low\n");
        } else {
            printf("Correct\n");
        }
    } while (guess != number);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {

     task03_guessing_game();
    

    return 0;
}
