#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int n, guess, attempts = 0;
    n = rand() % 100 + 1; // Random number between 1 and 100
    printf("Guess the number (1-100): ");
    do {
        scanf("%d", &guess);
        attempts++;
        if (guess < n) {
            printf("Low! Try again: ");
        } 
        else if (guess > n) { 
            printf("High! Try again: ");
        } 
        else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", n, attempts);
        }
    }
    while (guess != n);
}

int main() {
    srand(time(NULL)); // Seed random numbers
    task03_guessing_game();
    return 0;
}