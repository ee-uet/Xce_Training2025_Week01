# C Program: Pointer Operations and Array Manipulation

## Overview
This program demonstrates different pointer-based operations in C:
- Accessing and modifying variables using pointers  
- Swapping two numbers using pointers  
- Traversing, summing, and reversing an array using pointers  

---

## Code Structure

- **`task1_1()`**
  - Declares an integer variable `a` and a pointer `ptr` pointing to it  
  - Prints the value of `a` directly and through the pointer  
  - Changes the value of `a` using the pointer and prints the updated value  

- **`swap(int *a, int *b)`**
  - Takes two integer pointers as arguments  
  - Swaps the values of the integers they point to using a temporary variable  
  - Prints the swapped values  

- **`task1_3()`**
  - Declares an array `arr` and a pointer `p` pointing to it  
  - Traverses the array using the pointer and prints each element  
  - Computes the sum of elements using the pointer  
  - Reverses the array **in place** using two pointers (`start` and `end`)  
  - Prints the reversed array  

- **`main()`**
  - Calls all the above functions in sequence:  
    1. `task1_1()`  
    2. `swap()` with `a = 5` and `b = 10`  
    3. `task1_3()`  

---

## How the Code Works

1. **Pointer Basics (`task1_1`)**  
   - A variable `a` is declared and assigned `10`.  
   - A pointer `ptr` stores the address of `a`.  
   - `*ptr` is used to access the value of `a` through its address.  
   - Changing `*ptr = 20` updates `a` directly because the pointer references its memory location.  

2. **Swapping Values (`swap`)**  
   - Function takes two integer pointers `a` and `b`.  
   - A temporary variable holds one value, then the values are exchanged.  
   - Since pointers directly modify memory, the swapped values reflect in the caller function.  

3. **Array Traversal and Reversal (`task1_3`)**  
   - A pointer iterates through the array, printing values and adding them to compute the sum.  
   - Two pointers (`start` at the beginning, `end` at the end) are used to reverse the array by swapping values until they meet in the middle.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task1.c -o task1
./task1

```
## Example Run
### Output
```sh
Direct value is 10
Value by using pointer is 10
New value is 20
a = 10
b = 5
1
2
3
4
5
Sum is 15
Reversed array is
5
4
3
2
1
