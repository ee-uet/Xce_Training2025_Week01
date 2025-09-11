# Problem
Create a program that: 
- Dynamically allocates an array of integers 
-	Allows the user to input the size of the array and its elements. 
-	Calculates and prints the sum and average of the elements.
- Implement a function that uses realloc() to extend an existing dynamically allocated array.
- Create a simple memory leak detector: 
   -	Write functions to allocate and free memory 
    -	Keep track of allocated memory addresses 
   -	Print a warning if the program ends with unfreed memory 
#
**Approach**

- First,  allowed the user to create a dynamic array by allocating memory using malloc and input its elements.

- Then,  calculated the sum and average by iterating over the array and printed the results.

- To demonstrate resizing,  used realloc to extend an existing array and added extra elements to it.

- For memory management,  wrote custom functions my_malloc and my_free to keep track of allocated memory addresses.  
  
**Memory Leak Detector Approach**

Created a global array allocated_ptrs to store the addresses of all memory blocks allocated using my custom my_malloc function. Every time my_malloc allocates memory, it also saves the pointer in this array and increments a counter allocated_count.

When memory is freed using my_free, the function searches for the pointer in allocated_ptrs. If found, it removes it from the array, decreases allocated_count, and frees the memory. At the end of the program, the check_leaks function checks allocated_count.

If it is zero, all memory was properly freed and there are no leaks. If it is greater than zero, the program prints the addresses of the memory blocks that were not freed, signaling memory leaks.
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**      
Allocate two integers:  
a = 10  
b =  20  
Free a  
Check memory leaks:  
Only b is unfreed  
Output:
a  (freed)
b (memory leak detected)
#
**Resources and References**    
Used AI tools and online resources, including Google, to better understand dynamic memory allocation and memory leak detection concepts, as the topic was complex for me  and required additional clarification beyond lecture materials.
