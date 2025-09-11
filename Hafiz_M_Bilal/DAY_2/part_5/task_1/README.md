# Task 5.1 – Dynamic Array (malloc), Sum & Average

## Problem
Write a program in C that:
1. Dynamically allocates memory for an integer array using `malloc`.
2. Takes `n` elements as input from the user.
3. Calculates and prints the **sum** and **average** of the elements.
4. Frees the allocated memory.

---

## Approach
- Input size `n` from the user.
- Allocate memory using:
  ```c
  int *arr = (int*) malloc(n * sizeof(int));
Take array input from the user and simultaneously compute the sum.

Calculate average as:
float avg = (float)sum / n;
Print sum and average.

Free allocated memory using free(arr).

## How to Run

Save the file as task5_1.c.

Compile:

gcc task5_1.c -o task5_1


Run:

./task5_1

## Example Execution
Input:
Enter number of elements of an array: 5
Enter 1th number: 10
Enter 2th number: 20
Enter 3th number: 30
Enter 4th number: 40
Enter 5th number: 50

Output:
Sum: 150
Average: 30.00

## Known Limitations

User must enter a valid positive integer for n.

No error handling for non-integer inputs.