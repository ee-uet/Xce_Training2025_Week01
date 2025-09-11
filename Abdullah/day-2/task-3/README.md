# Task 3: Preprocessor & File I/O

## Problem
1. **Preprocessor Macros**: Write macros for SQUARE(x), MAX(a,b), MAX(a,b,c), MAX(a,b,c,d), and TO_UPPER(c)
2. **File I/O**: Create a Student struct, store 5 students, find highest GPA, save to file, and read back

## Approach

### Preprocessor Macros
1. Use function-like macros with parentheses for safe evaluation
2. Build complex macros using simpler ones (MAX3 uses MAX2)
3. Implement character case conversion using ASCII arithmetic (lowercase - 32 = uppercase)

### File I/O
1. Define Student structure with name, roll, and GPA fields
2. Input 5 students and track highest GPA using pointer
3. Write student data to text file using fprintf
4. Read data back using fscanf and display

## How to Run

### Macros
```bash
gcc -o macros macros.c
./macros
```

### File I/O
```bash
gcc -o file_io file_io.c
./file_io
```

## Example Output

### Macros
```
Square of x = 5 is : 25
The Maximum of (2,3) is: 3
The Maximum of (2,4,6) is : 6
The Maximum of (2,4,6,9) is : 9
The To Upper of d is : 68
```

### File I/O
```
Enter the name of Student 1: Alice
Enter the GPA of Student 1: 3.8
Enter the roll of Student 1: 101
[... input for 5 students ...]
The Student with highest GPA is: Alice , 101, 3.800000.
Read from students.txt : Bob, 102, 3.500000
[... data for remaining students ...]
```

## Design Notes
- Macros use ternary operators for conditional logic
- File operations include basic error checking
- Student data stored in both array and file formats

## Key Concepts Demonstrated
- **Macro Definition**: Function-like macros with parameters
- **Macro Composition**: Building complex macros from simpler ones
- **File I/O**: Opening, writing, reading, and closing files
- **Structure Operations**: Accessing struct members via pointers
- **Pointer Comparison**: Finding maximum using pointer references

## Macro Implementations
- **SQUARE(x)**: `(x*x)` - Simple multiplication
- **MAX2(a,b)**: `(a>b?a:b)` - Ternary conditional
- **MAX3(a,b,c)**: Uses MAX2 recursively
- **MAX4(a,b,c,d)**: Uses MAX3 recursively
- **TO_UPPER(c)**: `(c-32)` - ASCII conversion

## Assumptions & Edge Cases
- Student names limited to 49 characters
- File operations assume successful open/close
- TO_UPPER assumes lowercase input

## Known Limitations
- **File I/O loop error**: Starts from index 1 instead of 0, skipping first student
- **Macro safety**: No protection against multiple evaluation side effects
- **TO_UPPER logic**: Only works for lowercase letters, unsafe for other characters
- **Error handling**: Basic file error checking, no recovery mechanisms

## Issues in Original Code
1. File write/read loops start from `i=1` instead of `i=0`
2. Only 4 students written/read instead of 5
3. TO_UPPER macro doesn't validate if character is lowercase
4. No bounds checking on student name input

## Files Created
- `students.txt` - Contains student records in text format

## Sources & AI Usage
- Original template code from lab manual
- Standard file I/O operations from slides shared in class
- Macro programming techniques from slides shared in class
- Googled for syntax and usage of `fscanf` and `fprintf`
- Looked up ASCII values for character conversion here: https://stackoverflow.com/questions/34703007/to-converting-upper-and-lower-case-why-we-add-32-and-32-pleas-explain