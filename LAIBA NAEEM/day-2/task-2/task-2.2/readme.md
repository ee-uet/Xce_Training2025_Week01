# Problem
Write a program that checks if a given string is a palindrome (case insensitive).
#
**Approach**

- Use two pointers, start and end, to traverse the string from both ends.

- Convert characters to lowercase using tolower() to make the check case-insensitive.

- Compare characters at start and end:

    - If they are equal, move start forward and end backward.

    - If not, return 0 (not a palindrome).

     - If all character pairs match, return 1 (palindrome).
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Resources and References**  
1. While implementing these functions, I referred to the lab slides to understand pointer usage.
2. Used AI to learn how to convert capital letters to lowercase with tolower() for case-insensitive comparison.
