# C Program: Reverse String

## Overview
1. **Reverse a String**  
   - Takes a string input from the user.  
   - Reverses it manually without using string library functions.  

## Code Structure
- `task05_reverse_string()`  
  - Reads a string from the user.  
  - Manually calculates its length (`len`) by looping until `'\0'`.  
  - Prints the string in reverse order using a loop from `len - 1` down to `0`.   

- `main()`  
  - Run: reverse string.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task5A.c -o task5A
./task5A
```

### Example Run
```sh
Enter a string: what
Reversed string: tahw
```
