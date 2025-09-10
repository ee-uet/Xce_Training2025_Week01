# Task 0.5 – String Reversal & Second Largest Element

## Problem
- **Part 1:** Reverse a string without using library functions.  
- **Part 2:** Find the second largest element in a given integer array.  

---

## Approach
1. **Reverse String**
   - Read the string from user input.
   - Find its length manually by iterating until `'\0'`.
   - Use two pointers (`first` and `end`) to swap characters until the string is reversed.
   - Print the reversed string.

2. **Second Largest Element**
   - Initialize two variables: `large` (largest) and `second` (second largest).
   - Traverse the array:
     - If a number is greater than `large`, update `second = large` and `large = number`.
     - Else if the number is greater than `second` and not equal to `large`, update `second`.
   - Print the second largest number.

---

## How to Run
1. Save the code 
2. Compile the program:
   ```bash
   gcc reverse_string.c -o reverse_string
   ./reverse_string

   gcc second_largest.c -o second_largest
   ./second_largest

## Example Output

Enter the string:  hello
The Reverse string is: olleh

Second largest number is: 11

## Known Limitations

Reverse string function currently only supports single-word input (scanf("%s") stops at spaces).

Array for second largest is hardcoded (size = 10, values fixed).

No error handling for empty input or invalid cases.