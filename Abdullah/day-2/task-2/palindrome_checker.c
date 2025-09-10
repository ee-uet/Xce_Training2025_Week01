#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Custom strlen using pointers (copied from custom_string_functions.c for consistency)
int my_strlen(const char *s) {
    // TODO: Implement strlen
    const char *ptr = s;            // Pointer to traverse the string
    int length = 0;                 // Length counter
    while (*ptr) {                  // Loop until null terminator
        length++;                   // Increment length 
        ptr++;                      // Move to the next character
    }
    return length;                  // Return the final length
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // Pointers to the first and last characters of the string
    const char *start = s;
    const char *end = s + my_strlen(s) - 1; // Use my_strlen instead of strlen

    // Loop until the pointers meet or cross
    while (start < end) {
      // Dereference pointers to compare the actual characters (case-insensitive)
      if (tolower(*start) != tolower(*end)) {
        return 0; // Not a palindrome
      }
      
      // Move pointers inward
      start++;
      end--;
    }

    return 1; // It's a palindrome
}

int main() {
    printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");
    return 0;
}