# Problem
Implement your own versions of:
strlen()
strcpy()
strcmp()
Use pointer arithmetic only (no <string.h>).
#
**Approach**
- Implement custom string functions using pointers instead of array indexing.

- my_strlen: Traverse the string using a pointer until the null character \0 to count the length.

- my_strcpy: Copy each character from the source string to the destination using pointer arithmetic, and terminate with \0.

- my_strcmp: Compare the lengths of two strings by traversing each with a pointer, then return 0 if equal, 1 if the first is longer, or -1 if shorter.

Demonstrate these functions in main() by printing string length, copying a string, and comparing two strings.
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**   
1. my_strlen("Hello")  
   - Traverse characters: H → e → l → l → o → \0  
   - Length = 5

2. my_strcpy(buf, "World")
   - Copy each character: W → o → r → l → d → \0

    - Copied string in buf = "World"

3. my_strcmp("Hello", "worlddd")
     - Count characters: "Hello" = 5, "worlddd" = 7

    - Compare lengths: 5 - 7 < 0

    - Output = -1 (first string is shorter)
#
**Resources and References**  
While implementing these functions, I referred to the lab slides to understand pointer usage.

