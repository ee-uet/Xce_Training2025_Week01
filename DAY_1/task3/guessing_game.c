#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.3 =======================
void task03_guessing_game() {
    // TODO: Implement guessing game with random number

    int random,guess,attempt = 0;
    random = rand() % 101;
    
    do{
        printf("Enter your guess number ");
        scanf("%d", &guess);
        attempt++;

        if(guess < random){
            printf("The guess is too low\n");
        }
        else if(guess > random){
            printf("The guess is too high\n");
        }
        else{
            printf("You guess the correct number in %dth attempts\n",attempt);
        }
    } while(random != guess);
}

// ======================= Main =======================
int main() {
       
    task03_guessing_game();

    return 0;
}