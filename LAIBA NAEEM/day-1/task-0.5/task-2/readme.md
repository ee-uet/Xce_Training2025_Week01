# Problem
Write a function that scans an integer array and prints the second largest element.
#
**Approach**
- First, an array of numbers is defined.

- The program calculates the number of elements in the array.

- To find the second largest element, the array is sorted in descending order using a simple bubble sort.

- Bubble sort compares each element with the next one and swaps them if the previous element is smaller.

- After sorting, the largest element is at index 0, and the second largest is at index 1.

- The program prints the element at index 1 as the second largest.
##
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
##
**Example:**
 Array {7, 2, 9, 4}

Original array: 7, 2, 9, 4

Sort the array in descending order using bubble sort

-  Compare 7 and 2, no change, array becomes 7, 2, 9, 4

- Compare 2 and 9, swap, array becomes 7, 9, 2, 4

- Compare 2 and 4, swap, array becomes 7, 9, 4, 2

- Next loop, compare 7 and 9, swap, array becomes 9, 7, 4, 2

- Compare 7 and 4, no change, array remains 9, 7, 4, 2

- Compare 4 and 2, no change, array remains 9, 7, 4, 2

- Array after sorting is 9, 7, 4, 2

Largest element is at index 0, value is 9

Second largest element is at index 1, value is 7

Final output: 7.
#
**AI Usage / What I Verified**

- I understood how the program works using AI assistance.

- Verified the algorithm step by step with examples to see how the array is sorted and how the second largest element is found.