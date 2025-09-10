# Task 2.1 — Custom String Functions

## Problem
Implement your own versions of:
- `strlen()`
- `strcpy()`
- `strcmp()`

**Rules:**  
- Use only pointer arithmetic.  
- Do not include `<string.h>`.  

## Approach
- **my_strlen:** Traverse string with a pointer until `'\0'` and count characters.  
- **my_strcpy:** Copy characters one by one into destination; finally add null terminator.  
- **my_strcmp:** Compare characters until a mismatch or `'\0'` is found, return the difference.  

## How to Run
1. **Compile the program:**
   ```bash
   gcc task2_1.c -o out
2. **Run the executable:**
./out

## Test Cases
1. String length
Input: "hello"
Expected: 5
2. String copy
Source: "hello"
Destination after copy: "hello"
3. String compare
Input: "hello", "hello" → Expected: 0
Input: "hello", "world" → Expected: negative value
Input: "world", "hello" → Expected: positive value

## Example Output
Length of 'hello': 5
Copied string: hello
Compare 'hello' and 'hello': 0
Compare 'hello' and 'world': -15

## Known Limitations
1. Works only with null-terminated strings.
2. Does not handle buffer overflow in my_strcpy (assumes dest is large enough).
3. Comparison in my_strcmp is ASCII-based, so uppercase/lowercase are treated differently.

## Sources 
I understand the concept of const pointer and const variable.

