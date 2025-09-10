#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
   const char *start = s;
   const char *end = s + strlen(s) - 1;
   while(start<end) {
    if (tolower(*start) != tolower(*end)){
			return 0;
     }
	start++;
	end--;
     }
  return 1;
}



// ======================= Main =======================
int main() {
    
    printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

   

    
    return 0;
}
