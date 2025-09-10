# Task 6: File I/O Basics

## Problem
Write a program that:
- Reads 5 integers from the user and stores them in a file (numbers.txt)
- Reads back the integers from the file and prints them on the console

## Approach
1. Get 5 integers from user input
2. Open file "number.txt" in write mode
3. Write integers to file using fprintf
4. Close file after writing
5. Clear array and reopen file in read mode
6. Read integers back using fscanf
7. Display the read integers

## How to Run

### Compilation
```bash
gcc -o file_io file_io.c
```

### Execution
```bash
./file_io
```

## Example Output
```
Enter 5 integers:
10
20
30
40
50
Numbers written to numbers.txt
Numbers read from file:
10 20 30 40 50 
```

## Files Created
- `number.txt` - Contains the 5 integers, one per line

## Design Notes
- Uses FILE pointer for file operations
- Writes integers one per line for readability
- Clears array before reading to verify file I/O works
- Includes basic error checking for file opening

## Assumptions & Edge Cases
- Assumes valid integer input from user
- File created in current working directory
- File is overwritten each time program runs

## Known Limitations
- Basic error handling (only checks if file opens)
- No validation for read operations
- Hardcoded filename and array size

## Sources & AI Usage
- Original template code from lab manual
- Standard C file I/O functions used
- No AI assistance for file operations logic