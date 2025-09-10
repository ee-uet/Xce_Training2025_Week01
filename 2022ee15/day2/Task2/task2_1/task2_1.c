#include <stdio.h>

// Custom strlen using pointers
int my_strlen(const char *s) {
    int size = 0;
    while (*s != '\0') {
        size++;
        s++;
    }
    return size;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // add null terminator
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int main() {
    char str1[] = "hello";
    char str2[20];
    char str3[] = "hello";
    char str4[] = "world";

    // Test strlen
    printf("Length of '%s': %d\n", str1, my_strlen(str1));

    // Test strcpy
    my_strcpy(str2, str1);
    printf("Copied string: %s\n", str2);

    // Test strcmp
    printf("Compare '%s' and '%s': %d\n", str1, str3, my_strcmp(str1, str3));
    printf("Compare '%s' and '%s': %d\n", str1, str4, my_strcmp(str1, str4));

    return 0;
}

