# Task 5.1: Dynamic Array, Sum, and Average  

## Problem  
Create a program that:  
- Dynamically allocates an array of integers.  
- Allows the user to input the size of the array and its elements.  
- Calculates and prints the sum and average of the elements.  

## Approach  
- First, the program asks the user for the size of the array.  
- It then uses `malloc` to allocate memory dynamically at runtime.  
- Elements are stored using pointer arithmetic (`arr+i`).  
- A loop is used to calculate the sum of all elements.  
- The average is computed as `(float)sum / n` so that division is in floating-point.  
- Finally, the memory is released using `free()`.  

## How to Run  
1. **Compile the code:**  
   ```bash
   gcc task5_1.c -o out
2. **Run the executable:**
./out

## Test Cases
Case 1 – Small array
Input: n = 3, elements = [1, 2, 3]  
Output: Sum = 6, Average = 2.00  
Case 2 – Even sum
Input: n = 4, elements = [2, 4, 6, 8]  
Output: Sum = 20, Average = 5.00  
Case 3 – Floating-point average
Input: n = 2, elements = [3, 4]  
Output: Sum = 7, Average = 3.50  

## Example Output
Enter the number of elements of arr: 3  
Enter the elements: 1 2 3  
Sum is 6  
Average is 2.00  

## Known Limitations
1. Memory allocation failure is not checked (if malloc returns NULL).
2. Program only works for integers.



