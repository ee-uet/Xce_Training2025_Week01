# Task 3.1 — Preprocessor Macros

## Problem
Write preprocessor macros for:
- `SQUARE(x)` → returns square of a number
- `MAX(a, b)` → maximum of two numbers
- `MAX(a, b, c)` → maximum of three numbers
- `MAX(a, b, c, d)` → maximum of four numbers
- `TO_UPPER(c)` → convert a lowercase character to uppercase

Demonstrate the macros with test cases.

## Approach
- Use preprocessor `#define` to define reusable macros.
- Enclose parameters and expressions in parentheses to avoid operator precedence issues.
- Build `MAX3` and `MAX4` using the `MAX2` macro.
- For `TO_UPPER`, check if the character is between `'a'` and `'z'`.  
  If yes, subtract `'a'` and add `'A'` to get its uppercase version.

## How to Run
1. **Compile the program:**
   ```bash
   gcc task3_1.c -o out
2. **Run the executable:**
    ./out

## Test Cases
1. Square of a number
Input: SQUARE(5)
Expected: 25
2. Max of two numbers
Input: MAX2(10, 20)
Expected: 20
3. Max of three numbers
Input: MAX3(5, 15, 10)
Expected: 15
4. Max of four numbers
Input: MAX4(10, 20, 30, 25)
Expected: 30
5. Character conversion
Input: TO_UPPER('a')
Expected: 'A'
Input: TO_UPPER('Z')
Expected: 'Z' (unchanged)

## Example Output
SQUARE(5) = 25
MAX2(10, 20) = 20
MAX3(5, 15, 10) = 15
MAX4(10, 20, 30, 25) = 30
TO_UPPER('a') = A
TO_UPPER('Z') = Z

## Known Limitations
1. Macros do not perform type checking (works only if the arguments are valid).
2. TO_UPPER only handles ASCII letters, not locale-specific characters.

## Sources and AI Usage 
1. I used AI to understand the logic for TO_UPPER macro.



