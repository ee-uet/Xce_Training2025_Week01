# Task – Custom String Functions Using Pointers

## Problem
Reimplement basic string functions in C using only pointers:
1. `my_strlen` – calculate string length.
2. `my_strcpy` – copy one string into another.
3. `my_strcmp` – compare two strings.

---

## Approach
- **`my_strlen`**:  
  Start from the first character and increment a counter until `'\0'` is reached.  

- **`my_strcpy`**:  
  Copy each character from `src` to `dest` until `'\0'`, then terminate with `'\0'`.  

- **`my_strcmp`**:  
  Compare both strings character by character.  
  - If characters differ → return ASCII difference.  
  - If both end together → return 0 (equal).  

---

## How to Run
1. Save code in a file, `task2_1.c`.  
2. Compile:  
   ```bash
   gcc task2_1.c -o task2_1
    ./task2_1

## Example Output
Len = 5
Copied: World
Strings are equal 


## Known Limitations

No buffer overflow checks in my_strcpy (assumes dest is large enough).

Case-sensitive comparison in my_strcmp.

No handling for NULL pointers.