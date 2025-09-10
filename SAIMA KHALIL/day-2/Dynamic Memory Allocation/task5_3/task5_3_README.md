# Memory Leak Detector  

This program demonstrates a **memory leak detection mechanism** using  `my_malloc` and `my_free` functions.  
 

---

## Code Explanation

#### Global Variables
- `allocated_ptrs[MAX_PTRS]` : Stores pointers returned by `my_malloc`.
- `allocated_count` : Number of currently active allocations.


####  Functions
void* my_malloc(size_t size)
- Allocates memory using `malloc`.
- Tracks the allocated pointer in `allocated_ptrs`.
- Detects excessive allocations to prevent hidden leaks.

void my_free(void *ptr)
- Frees memory if it exists in `allocated_ptrs`.
- Removes the pointer from the tracking array.

void report_leaks()
- Prints all pointers that were allocated but not freed.
- Prints **“No memory leaks detected”** if all memory is freed.

---

#### Example Run

Memory leak detected! 1 pointers not freed:
Pointer 1: 00C01B30      
No memory leaks detected.

---

#### Sources Used
Used AI to understand how memory leak detection actually works and how it can be incorporated into code.

---
#### Run
```bash
gcc task5_3.c -o task5_3 
./task5_3 
```