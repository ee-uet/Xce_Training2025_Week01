#include <stdio.h>
#include <ctype.h>

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    const char *start = s;
    const char *end = s;

    // Move end to the last valid character
    while (*end != '\0') {
        end++;
    }
    end--; // step back from '\0'

    // Compare characters from both ends
    while (start < end) {
        if (tolower(*start) != tolower(*end)) {
            return 0; // not a palindrome
        }
        start++;
        end--;
    }
    return 1; // palindrome
}

int main() {
    char str1[] = "Level";
    char str2[] = "Hello";
    char str3[] = "MadAm";

    printf("'%s' is %s\n", str1, is_palindrome(str1) ? "Palindrome" : "Not Palindrome");
    printf("'%s' is %s\n", str2, is_palindrome(str2) ? "Palindrome" : "Not Palindrome");
    printf("'%s' is %s\n", str3, is_palindrome(str3) ? "Palindrome" : "Not Palindrome");

    return 0;
}

