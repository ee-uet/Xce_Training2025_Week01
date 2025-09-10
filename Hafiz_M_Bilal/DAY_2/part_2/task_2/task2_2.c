#include <stdio.h>
#include <ctype.h>

int my_strlen(const char *s) {
    int length = 0;
    while(*s != '\0'){
        length++;
        s++;
    }
    return length;
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    int a = my_strlen(s);
    const char *end = s + (a-1); 
    while(s < end){
        if(tolower(*s) != tolower(*end)){
            return 0;
        }
        s++;
        end--;
    }
    return 1;
}

// ======================= Main =======================
int main() {
    
    printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    return 0;
}
