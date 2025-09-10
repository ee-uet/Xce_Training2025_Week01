# C Program: Command-Line Arguments (Sum of Two Integers)

## Overview
This program demonstrates:
- How to use **command-line arguments** in C  
- Conversion of string arguments (`argv`) to integers using `atoi()`  
- Performing arithmetic operation (sum) on arguments  

---

## Code Structure
- **`task10_cmd_args(int argc, char *argv[])`**
  - Checks if two integers are provided as command-line arguments  
  - Converts them from strings to integers using `atoi()`  
  - Prints their sum  
- **`main(int argc, char *argv[])`**
  - Passes the arguments to `task10_cmd_args()`  

---

## How to Compile and Run

### Using GCC
```sh
gcc task10.c -o task10
./task10 12 8

### Example Run

Input (via command line)
./task10 15 25

Output
Sum = 40