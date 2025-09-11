#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char string[100];
    printf("Task 5\n");
    printf("Enter String:\n");
    scanf("%[^\n]",string);
    for (int i = strlen(string)-1; i>=0; i--) {
        printf("%c",string[i]);
}
     printf("\n");
}


// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
     task05_reverse_string();
    
  

    return 0;
}
