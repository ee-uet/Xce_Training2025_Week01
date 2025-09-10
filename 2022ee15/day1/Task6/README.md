# Task 0.6 — File I/O Basics

## Problem
- Read **5 integers** from the user and store them in a file (`numbers.txt`).
- Read back the integers from the file and print them to the console.
- (Optional) Extend: Save results of prime-checker (Task 0.4) into a file.

## Approach
1. Use `fopen("numbers.txt", "w")` to open a file in write mode.  
2. Write integers with `fprintf`.  
3. Close the file after writing.  
4. Reopen with `fopen("numbers.txt", "r")` in read mode.  
5. Use `fscanf` inside a loop until EOF to read back the numbers.  
6. Print them to the console.  

## How to Run
    ```bash
    gcc t6.c -o t6
    ./t6
    
## Example Output:
    Enter 5 integers: 1 2 3 4 5
    Numbers written to 'numbers.txt'
    Numbers read from 'numbers.txt':
    1 2 3 4 5

## Known Limitations
- File name is fixed as numbers.txt.
- No input validation (expects integers).

## Sources & AI Usage
- AI helped add file-handling syntax (fopen, fprintf, fscanf) and EOF handling.

