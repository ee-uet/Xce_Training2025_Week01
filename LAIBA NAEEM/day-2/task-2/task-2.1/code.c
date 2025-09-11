#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int counter = 0;
    while (*s != '\0') {
      counter = counter+1;
      s++;
}
    return counter;
}

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;  // copy character
        src++;         // move source pointer
        dest++;       
    }
    *dest = '\0';     
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int counter1 = 0;
    int counter2 = 0;
    while (*s1 != '\0') {
         counter1 = counter1 + 1;
         s1++;
}
    while (*s2 != '\0') {
         counter2 = counter2 + 1;
         s2++;
}
   if (counter1 - counter2 == 0)
     {
      return 0;
}
  else if ( counter1 > counter2 ) {

    return 1;
}
   else if ( counter1 < counter2 ) {

    return -1;
}
}

// ======================= Main =======================
int main() {
   

    // --- Part 2 ---
    printf("Len = %d\n", my_strlen("Hello"));
    char buf[100]; 
    my_strcpy(buf,"World");
    printf("Copied: %s\n", buf);
    char arr1[100] = "Hello";
    char arr2[45] = "worlddd";
    printf("output = %d\n", my_strcmp(arr1,arr2));
   

   
    return 0;
}
