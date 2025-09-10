#include <stdio.h>
#include <stdlib.h>


void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char strng[100];

    // Input string
    printf("Enter the string:  ");
    scanf("%s",strng);

    // Calculate length
    int length = 0;
    while(strng[length] != '\0'){
        length++;
    }
    // Print reversed string
    printf("Reversed string is: ");

    char *first = &strng[0];
    char *end = &strng[length-1];
    while(first < end){
        char temp = *first;
        *first = *end;
        *end = temp;

        first++;
        end--;
    }
    

    printf("%s",strng);
    
    printf("\n");
}

int main() {
    task05_reverse_string();
    return 0;
}