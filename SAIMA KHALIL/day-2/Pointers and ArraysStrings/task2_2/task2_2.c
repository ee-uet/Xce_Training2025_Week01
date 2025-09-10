#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // for 'tolower'


int is_palindrome(const char *s) {
    const char *start = s;
    const char *end = s + strlen(s) - 1;
    while (start < end) {
        if (tolower(*start) != tolower(*end)){//coz case-insensitive ha
            return 0; // Not a palindrome
        }
        start++;
        end--;
    } 
    return 1; // Is a palindrome
}

int main(){
    const char *s = "saias";
    int ispal;
    ispal=is_palindrome(s);
    printf("is Palindrome? %d \n1=Yes \n0=No",ispal);
    return 0;
}