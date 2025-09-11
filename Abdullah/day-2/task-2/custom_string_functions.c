#include <stdio.h>
#include <stdlib.h>

// Custom strlen using pointers
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

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    while (*src) {
        *dest = *src;           // Copy character from src to dest
        dest++;                 // Move to the next position in dest
        src++;                  // Move to the next position in src
    }
    *dest = '\0';               // Explicitly add null terminator
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    while (*s1 && *s2 && *s1 == *s2) {   // Loop until characters differ or end of either string
        s1++;
        s2++;
    }
    if (*s1 == *s2) {
        return 0;       // Both strings ended, they are equal
    }
    return *s1 < *s2 ? -1 : 1;      // Return -1 which means s1 character comes before s2
}

int main() {
    printf("Len = %d\n", my_strlen("Helllo"));              // Test my_strlen
    char buf[100];                                          // Buffer to hold copied string
    my_strcpy(buf,"World");                                 // Copy "World" into buf
    printf("Copied: %s\n", buf);                            // Print copied string   
    printf("Compare: %d\n", my_strcmp("Hello", "World"));   // Test my_strcmp
    return 0;
}