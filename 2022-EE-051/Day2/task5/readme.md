# C Program: Dynamic Memory Allocation & Leak Detection

## Overview
This program demonstrates **dynamic memory allocation in C** using:
1. **`malloc`** – Allocate memory dynamically.  
2. **`realloc`** – Resize memory blocks.  
3. **Custom Leak Detector** – Detect unfreed memory allocations.  

---

##  Code Structure

###  `task5_1_dynamic_array()`
- Allocates memory for an integer array using `malloc`.  
- Reads elements, computes **sum** and **average**.  
- Frees allocated memory.  

###  `task5_2_realloc_array()`
- Allocates an initial array.  
- Resizes it using `realloc`.  
- Accepts new input for resized array.  
- Prints final array and frees memory.  
  
###  `task5_3_leak_detector()`
- Implements **custom malloc/free wrappers**:  
  - `my_malloc(size)` → allocates memory and tracks pointer.  
  - `my_free(ptr)` → frees memory and removes pointer from tracking.  
  - `report_leaks()` → reports any unfreed memory.  
- Demonstrates **intentional leak detection**.  

---

## How the Code Works

1. **Dynamic Array Allocation (`malloc`)**
   - Memory allocated on heap → resizable at runtime.  
   - Freed after use → prevents memory leaks.  

2. **Reallocation (`realloc`)**
   - Expands or shrinks previously allocated memory.  
   - Useful for resizable arrays (like vectors in C++).  

3. **Memory Leak Detector**
   - Tracks all allocations.  
   - Prints unfreed pointers at program end.  
   - Helps debug **forgotten frees**.  

### What I Verified

Created two arrays, when I fred the both no memory leak was detected but when i did not free the one, memory leak was detected.

## Key Points
- Always **free allocated memory** after use.   
- Leak detection is useful in larger projects.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task5.c -o task5
./task5
```

---

## Example Run

```sh
Enter size: 3
1 2 3
Sum is 6 and average is 2.000000
Enter size: 3
Enter 3 elements:
10 20 30
Enter new size: 5
Enter 5 elements for extended array:
10 20 30 40 50
Final array: 10 20 30 40 50
Memory leaks detected: 1
Leak at pointer: 0x563f7b8002a0
```

