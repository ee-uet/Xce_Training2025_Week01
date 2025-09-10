// file: t3.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task03_fibonacci() {
    // print Fibonacci sequence up to n terms
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        printf("result: %d\n", a);
        next = a + b;
        a = b;
        b = next;
    }
}

void task03_guessing_game() {
    // implement guessing game with random number
    int random = (rand() % 100 + 1);
    int guess;

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);

        if (guess == random) {
            printf("Correct Guess\n");
        } else if (guess > random) {
            printf("Too High\n");
        } else {
            printf("Too Low\n");
        }
    } while (guess != random);
}

int main(void) {
    // seed random for guessing game
    srand(time(0));

    printf("Running Fibonacci Task:\n");
    task03_fibonacci();

    printf("\nRunning Guessing Game:\n");
    task03_guessing_game();

    return 0;
}

