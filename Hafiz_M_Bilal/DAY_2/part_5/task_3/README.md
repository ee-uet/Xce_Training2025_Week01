# Task 5.3 – Memory Leak Detector (Manual Tracking)

## Problem
Implement a simplified memory leak detector in C:
- Track memory allocations with a custom `my_malloc`.
- Free memory with `my_free` and update tracking.
- At the end, check if any allocated memory was not freed and report leaks.

---

## Approach
- Defined a global array `allocated_ptrs[MAX_PTRS]` to store allocated pointers.
- Each call to `my_malloc` stores the returned pointer in the tracking array.
- `my_free` checks if the pointer exists in the tracking list:
  - If found → frees memory and sets pointer slot to `NULL`.
  - If not found → prints a warning (`invalid free`).
- `report_leaks` iterates through all tracked allocations and reports unfreed ones.

---

## How to Run
1. Save code as `task5_3.c`.
2. Compile:
   ```bash
   gcc task5_3.c -o task5_3
   ./task5_3

## Example Run
Output:
Memory allocated to 1th pointer 
Memory allocated to 2th pointer 
Allocated pointer's memory successfully free at 0x55b4c31432a0
Memory leak detected at pointer 0x55b4c3143280 

## Known Limitations

Can track at most MAX_PTRS allocations (100 in this case).

Does not shrink allocated_count after free (so freed slots remain in list).

Only detects leaks at the end when report_leaks is called.
