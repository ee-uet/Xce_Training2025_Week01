#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Calculate the length of string
int my_strlen(const char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}
// copies one string from source to destination
void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}
// compares two strings
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
// Checks if a number is palindrome or not
int is_palindrome(const char *s) {
    const char *start = s;
    const char *end = s + strlen(s) - 1;
    while (start < end) {
        if (tolower(*start) != tolower(*end)) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int main(){
    printf("Len = %d\n", my_strlen("Hello"));
    char buf[100];
    my_strcpy(buf, "World");
    printf("Copied: %s\n", buf);
    printf("%d\n", my_strcmp("What", "What"));
    printf("Palindrome? %s\n", is_palindrome("Whatever") ? "Yes" : "No");
    return 0;
}