# Task 0.6 – File I/O Operations

## Problem
- Write **5 integers** entered by the user to a file.  
- Read back the integers from the file and display them.  

---

## Approach
1. Prompt the user to enter 5 integers and store them in an array.  
2. Open a file `number.txt` in **write mode** and write the integers line by line using `fprintf()`.  
3. Close the file.  
4. Reset the array values to `0` to ensure fresh reading.  
5. Open the file `number.txt` in **read mode** and read integers back into the array using `fscanf()`.  
6. Print the read integers on the console.  

---

## How to Run
1. Save the code in a file, `task_6.c`.  
2. Compile the program:  
   ```bash
   gcc task_6.c -o task_6
   ./task_6


## Example Output
Enter 5 integers:
1 2 3 4 5
Numbers written to numbers.txt
Numbers read from file:
1 2 3 4 5

## Known Limitations

File name is fixed (number.txt), cannot be changed by the user.

Program assumes exactly 5 integers will be entered (no validation for fewer/more inputs).

No error handling for corrupted file contents or invalid data formats.

--------------------------___________________-------------

## For Optional task 

# Task 0.6 (Optional) – Prime Numbers with File I/O

## Problem
- Generate all prime numbers between **1 and 100**.  
- Write these prime numbers into a file named **`primes.txt`**.  

---

## Approach
1. Implement a helper function `isPrime(int n)` that checks whether a number is prime.  
   - Return `1` if prime, `0` otherwise.  
2. Open a file `primes.txt` in **write mode**.  
3. Write the line `"Prime numbers between 1 and 100 are:"`.  
4. Loop from `1` to `100` and check each number with `isPrime()`.  
5. If prime, write it into the file separated by spaces.  
6. Close the file.  
7. Print confirmation that the file has been created.  

---

## How to Run
1. Save the code in a file, `task06_file_io_prime`.  
2. Compile the program:  
   ```bash
   gcc task06_file_io_prime.c -o task06_file_io_prime
   ./task06_file_io_prime


## Example Output
Prime numbers written to primes.txt

## Known Limitations

File name is fixed (primes.txt), user cannot specify a different name.

Works only for primes in the range 1–100 (hardcoded).

No error handling for file permission issues beyond open failure.


## AI Usage
Part of the code was written with the help of ChatGPT (AI assistant).  
I asked about file operations in C (open, read, write, close), and used its examples to build my program.  

### What I verified
- I tested edge cases, such as:
  - File not existing when opened in "r" mode (error handling).
  - Writing and reading empty strings.
  - Appending data multiple times.
- I checked that the program follows assignment constraints (uses stdio.h functions).
- I confirmed that the code compiles and runs correctly on Linux.
