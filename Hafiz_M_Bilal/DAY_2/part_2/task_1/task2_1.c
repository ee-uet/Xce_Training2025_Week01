#include <stdio.h>


// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int length = 0;

    // Keep going until we hit NULL terminator
    while(*s != '\0'){
        length++;
        s++;
    }
    return length;
}

// Custom strcpy using pointers
// my_strcpy: copies src string into dest string
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    int a = my_strlen(src);
    // Keep copying until NULL terminator
    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    // Keep going while characters are same and not at the end
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    // Return difference of ASCII values of first non-matching characters
    return *(unsigned char *)s1 - *(unsigned char *)s2;

}

// ======================= Main =======================
int main() {
    
    printf("Len = %d\n", my_strlen("Hello"));
    char buf[100]; my_strcpy(buf,"World");
    printf("Copied: %s\n", buf);
    printf("Strings are %s \n",(my_strcmp("world", "world") == 0 ? "equal" : "not_equal"));
       
    return 0;
}
