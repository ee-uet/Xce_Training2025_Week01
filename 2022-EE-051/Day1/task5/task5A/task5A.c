#include <stdio.h>

void task05_reverse_string() {
    // Reverse a string without library functions
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while(str[len] != '\0') len++;

    printf("Reversed String: ");
    for(int i = len - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

int main() {

    task05_reverse_string();
    return 0;
}

