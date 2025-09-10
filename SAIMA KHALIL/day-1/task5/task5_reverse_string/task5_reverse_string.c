#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void task05_reverse_string() {
    char str[100], reversed[100];
    int len = 0;   
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);//fgets stores input with \n when we press Enter,from standard input(stdin) stream
    str[strcspn(str, "\n")] = 0; //returns the index of '\n' in str, and then we replace it with '\0' to remove the newline
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0'; // null-terminating the reversed string
    printf("Reversed string: %s\n", reversed);
    printf("Length of the string: %d\n", len);
}

int main()
{
    task05_reverse_string();
    return 0;
}
