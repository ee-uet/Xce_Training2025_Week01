## Array Operations Using Pointers

This program demonstrates **pointer-based operations** on arrays and **summing elements** and **reversing the array in place**.

---

### Code Explanation

#### Functions

1. **`swap(int *a, int *b)`**  
   Swaps the values of two integers using their pointers as explained in task

2. **`reverse_array_in_place(int *arr, int size)`**  
   Reverses the elements of the array **in place** using pointers.  
   - `left_ptr` starts at the first element of the array.  
   - `right_ptr` starts at the last element of the array.  
   - Swap the elements pointed by `left_ptr` and `right_ptr` and move the pointers toward each other until they meet.

#### Steps 
1. Define an array `arr[] = {1, 2, 3, 4, 5}`.  
2. Use a pointer `ptr` to traverse the array.  
3. Calculating and then print the sum of the array elements.  
4. Then call `reverse_array_in_place(ptr, 5)` to reverse the array.  
5. Then prints the reversed array.

---

#### Example Run
Array elements are: 1 2 3 4 5
Sum of elements: 15
Reversed array in place is : 5 4 3 2 1



---

#### Run
```bash
gcc task1_3_array_pointers.c -o task1_3_array_pointers
./task1_3_array_pointers
```