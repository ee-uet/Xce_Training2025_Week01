# Problem
Create an array of integers and use pointer arithmetic to:
-	Print all elements of the array
-	Calculate the sum of all elements
-	Reverse the array in-place

#
**Approach**
- Declare and initialize an integer array.

- Use a pointer to traverse the array and print each element.

- Calculate the sum of all elements using pointer arithmetic.

- Reverse the array in place by swapping elements from start and end using pointers.

- Print the reversed array using a pointer to verify the changes.
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**     
arr = [1, 2, 3, 4, 5, 6, 7]  
Print all elements using pointer:  
Element 0: *ptr = 1 , sum = 1  
Element 1: *ptr = 2 , sum = 3  
Element 2: *ptr = 3 , sum = 6  
Element 3: *ptr = 4 , sum = 10  
Element 4: *ptr = 5 , sum = 15  
Element 5: *ptr = 6 , sum = 21  
Element 6: *ptr = 7 , sum = 28    
Reverse the array in place using pointers:    
Swap *start=1 with *end=7 , arr = [7,2,3,4,5,6,1]  
Swap *start=2 with *end=6 , arr = [7,6,3,4,5,2,1]  
Swap *start=3 with *end=5 , arr = [7,6,5,4,3,2,1]  
Final output:  
Original elements: 1 2 3 4 5 6 7  
Sum of elements: 28  
Reversed array: 7 6 5 4 3 2 1  
#
**Resources and References**  
While implementing the pointer arithmetic and array tasks, I referred to the lab slides to understand pointer usage, array traversal, and in-place reversal.



