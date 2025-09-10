# C Program: Find Second Largest Element

## Overview 
1. **Find the Second Largest Element in an Array**  
   - Uses a fixed array `{1, 2, 3, 4, 5}`.  
   - Finds and prints the second largest value.  

---

## Code Structure
- `task05_second_largest()`  
  - Declares an integer array `a[] = {1, 2, 3, 4, 5}`.  
  - Initializes `largest` and `second` to the first element.  
  - Iterates through the array:  
    - If a new element is larger than `largest`, update both `largest` and `second`.  
    - If it’s between `second` and `largest`, update only `second`.  
  - Prints the second largest value.  

- `main()`  
  - Runs find second largest element.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task5B.c -o task5B
./task5B
```
### Example Run
```sh
Input:
{1, 2, 3, 4, 5}
Output:
Second largest element is 4
