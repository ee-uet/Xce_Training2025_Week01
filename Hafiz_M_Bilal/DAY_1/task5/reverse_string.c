#include <stdio.h>

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char p[100];

    printf("Enter the string:  ");
    scanf("%s",p);

    // Find the length of string manually
    int length = 0;
    while(p[length] != '\0'){
        length++;
    }

    printf("The Reverse string is: ");

    // Use two pointers: one at start, one at end
    char *first = &p[0];
    char *end = &p[length-1];

    // Swap characters until the pointers meet in the middle
    while(first < end){
        char temp = *first;
        *first = *end;
        *end = temp;

        // Move forward
        first++;

        // Move backward
        end--;
    }

    printf("%s",p);
    printf("\n");
}


// ======================= Main =======================
int main() {

    task05_reverse_string();

    return 0;
}
