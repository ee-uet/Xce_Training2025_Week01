#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
 
int my_strlen(const char *s) {
    const char *ptr = s;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - s; // Return length by pointer difference
}
  
void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src; // Copy character (also can do by taking dest as arr dest[i]==src(ptr+i) etc or src[i])
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate destination string
}
 
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2; // Return difference
}

int main(){
    char arr[100];
    printf("\nLength = %d\n", my_strlen("saima"));
    my_strcpy(arr,"saima");
    printf("Copied: %s\n", arr);
    printf("Comparison: %d\n", my_strcmp("saima", "abbb"));//is 18 because ascii(s)-ascii(a)=115-97=18
    return 0;
}