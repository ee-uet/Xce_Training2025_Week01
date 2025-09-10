# Task 5: Arrays and Strings

## Problem
1. **Reverse a string**: Write a function to reverse a string without using library functions
2. **Find the 2nd Largest Element in an Array**: Write a function that scans an integer array and prints the second largest element

## Approach

### String Reversal
1. Read string input from user
2. Calculate string length manually (without strlen)
3. Use two pointers (first and last) approach
4. Swap characters from both ends moving towards center

### Second Largest Element
1. Initialize array with predefined values
2. Track largest and second largest elements in single pass
3. Handle case where new element becomes largest
4. Handle case where element is second largest but not equal to largest

## How to Run

### String Reversal
```bash
gcc -o reverse_string reverse_string.c
./reverse_string
```

### Second Largest Element
```bash
gcc -o second_largest second_largest.c
./second_largest
```

## Example Output

### String Reversal
```
Enter the string: hello
Reversed string is: olleh
```

### Second Largest Element
```
Second large number: 939
```
(For array: {99,55,83,993,939,223,12,0})

## Design Notes
- String reversal uses pointer arithmetic for in-place reversal
- Second largest algorithm handles duplicates correctly
- Both implementations avoid library functions as required

## Assumptions & Edge Cases
- String input assumes no spaces (uses scanf %s)
- Array is hardcoded with 8 elements
- Second largest assumes at least 2 distinct elements exist

## Known Limitations
- String reversal limited to single words (no spaces)
- Array size is fixed and hardcoded
- No input validation for empty arrays

## Sources & AI Usage
- Original template code from lab manual
- Classic two-pointer technique for string reversal
- Single-pass algorithm for second largest element