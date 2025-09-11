
---

# Task 5: Dynamic Memory Management in C

## Problem
The task is to demonstrate dynamic memory management in C using:
1. Dynamic arrays with `malloc` (sum and average calculation).
2. Resizing arrays with `realloc`.
3. Detecting memory leaks with custom allocation tracking.

## Approach
- **Task 5.1:**  
  - Allocate an integer array using `malloc`.  
  - Read elements from the user, compute the sum and average.  
  - Free the memory afterward.  

- **Task 5.2:**  
  - Allocate an initial array and fill it with user input.  
  - Use `realloc` to extend the array size.  
  - Add new elements to the extended array.  
  - Print the final array, compute sum and average.  

- **Task 5.3:**  
  - Implement custom wrappers (`my_malloc`, `my_free`) that track allocations in a global list.  
  - At program exit, run `report_leaks()` to show any unfreed memory.  
  - Demonstrate leak detection by freeing some but not all allocations.  

## How to Run
Compile and execute:
```bash
gcc task5.c -o task5
./task5
````

## Examples

### Example 1 (Dynamic Array)

```
Enter size of the array: 3
Enter element0: 10
Enter element1: 20
Enter element2: 30
Sum = 60
Average = 20.000000
```

### Example 2 (Realloc Array)

```
Enter initial size of the array: 2
Element 0: 5
Element 1: 7
Initial array: 5 7
Enter extended size: 4
Element 2: 9
Element 3: 11
Extended array: 5 7 9 11
Sum = 32
Average = 8.00
```

### Example 3 (Leak Detector)

```
Memory leaks detected!
Leak at address: 0x55e4f8c1c2a0
Leak at address: 0x55e4f8c1c2f0
```

## Known Limitations

* Leak detector is simplified:

  * Tracks at most 100 pointers.
  * Leak addresses may differ each run.
* Average in Task 5.1 prints with full floating precision (`%f`), which may not always be cleanly formatted.
* Program expects valid integer input from the user (no input validation).


* **Constraints:**

  * Memory allocation may fail if input sizes are very large.


## Sources & AI Usage

* Code was written with assistance from **ChatGPT (OpenAI)**.
* General knowledge of `malloc`, `realloc`, `free`, and pointer tracking was used; no direct external code was copied.
---