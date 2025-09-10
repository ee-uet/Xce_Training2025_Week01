# Task 0.5 — Arrays and Strings

## Problem
1. Reverse a string without using library functions.  
2. Find the second largest element in an integer array.

## Approach
- **String Reverse**:  
  - Manually count string length by iterating until `'\0'`.  
  - Print characters from end to start.  

- **Second Largest in Array**:  
  - Traverse the array while tracking `max` and `second_max`.  
  - Update values when a larger element is found.  

## How to Run
    ```bash
    gcc t5.c -o t5
    ./t5
    
## Example Run
    Reversed string:
    dlrow olleh

    Finding second largest element:
    Second highest is: 40

## Known Limitations
- task05_reverse_string() uses a fixed-size array (char name[50]), not dynamic input.
- task05_second_largest() assumes array length can be derived by (sizeof(arr)/4) — works only if int is 4 bytes.

## Sources and AI
- Concepts of string reversal and array traversal verified online.
