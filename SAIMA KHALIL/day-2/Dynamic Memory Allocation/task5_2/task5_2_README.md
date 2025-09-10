# Dynamic Array Reallocation 

This program demonstrates **dynamic memory allocation** and **resizing an array**   using `malloc` and `realloc`.  

---

## Code Explanation

1. **Initial Memory Allocation**
   - The user inputs the initial number of elements `n`.
   - Memory is allocated dynamically with `malloc`.
   - The program reads `n` integers from the user.

2. **Display Current Array**
   - Then  prints all elements currently in the array.

3. **Array Reallocation**
   - The user inputs a new size (`new_size`) greater than the current size.
   - `realloc` is used to extend the array while keeping existing elements intact.
   - Then newly added elements are initialized (  just with their index values).

4. **Display Extended Array**
   - The program prints the array after reallocation to show new elements.

5. **Memory Cleanup**
   - `free()` is used to release allocated memory.
   - The pointer is set to `NULL` inorder to avoid dangling references.

---

#### Example Run

Enter initial number of elements in array: 5
Enter 5 integers:
1 2 3 4 5
Current array: 1 2 3 4 5
Enter new size for array: 8
Array extended to size 8.
New array: 1 2 3 4 5 5 6 7


---

#### Run

```bash
gcc task5_2.c -o task5_2
./task5_2
```