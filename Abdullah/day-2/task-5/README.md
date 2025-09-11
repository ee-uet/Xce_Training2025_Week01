# Task 5: Dynamic Memory Allocation

## Problem
1. **Dynamic Array**: Create a program that dynamically allocates an array, inputs elements, and calculates sum and average
2. **Realloc Array**: Implement a function that uses realloc() to extend an existing dynamically allocated array
3. **Memory Leak Detector**: Create a simple memory leak detector that tracks allocated memory and reports unfreed blocks

## Approach

### Dynamic Array
1. Get array size from user input
2. Allocate memory using malloc()
3. Input elements and calculate sum
4. Compute average and display results
5. Free allocated memory

### Realloc Array
1. Initially allocate memory for 5 integers
2. Fill with sample data
3. Use realloc() to extend to 10 integers
4. Fill remaining elements and display
5. Free memory when done

### Memory Leak Detector
1. Track allocated pointers in global array
2. Custom malloc wrapper adds pointers to tracking
3. Custom free wrapper removes pointers from tracking
4. Report function shows any unfreed memory

## How to Run

### Dynamic Array
```bash
gcc -o dynamic_array dynamic_array.c
./dynamic_array
```

### Realloc Array
```bash
gcc -o realloc_array realloc_array.c
./realloc_array
```

### Memory Leak Detector
```bash
gcc -o memory_leak_detector memory_leak_detector.c
./memory_leak_detector
```

## Example Output

### Dynamic Array
```
Enter the number size of arrray: 3
Enter number 1 :10
Enter number 2 :20
Enter number 3 :30
Sum of the Elements: 60
Average of the Elements: 20
```

### Realloc Array
```
Initially allocated for 5 elements.
Reallocating to hold 10 elements.
Final array contents: 1 2 3 4 5 6 7 8 9 10 
```

### Memory Leak Detector
```
Memory leak detection...
Allocated 3 blocks.
Freeing 2 blocks.
--- Memory Leak Report ---
Warning! 1 block(s) of memory were not freed:
  - Leaked block at address: 0x55a1b2c3d4e0
--------------------------
Freeing remaining blocks.
```

## Design Notes
- Dynamic allocation uses malloc() with error checking
- Realloc() properly handles potential memory movement
- Leak detector uses global tracking arrays
- All programs include proper memory cleanup

## Key Concepts Demonstrated
- **Dynamic Allocation**: malloc() for runtime memory allocation
- **Memory Reallocation**: realloc() for extending allocated blocks
- **Error Handling**: Checking for allocation failures
- **Memory Tracking**: Custom wrappers for allocation functions
- **Leak Detection**: Reporting unfreed memory blocks

## Memory Management Best Practices
- Always check malloc()/realloc() return values
- Store realloc() result in temporary pointer first
- Free original block if realloc() fails
- Track all allocations for leak detection
- Free all allocated memory before program exit

## Assumptions & Edge Cases
- Dynamic array assumes positive size input
- Realloc handles potential memory movement
- Leak detector limited to MAX_PTRS (100) tracked pointers
- Handles NULL pointer checks appropriately

## Known Limitations
- **Integer division in average**: Uses integer division, losing decimal precision
- **No input validation**: Dynamic array doesn't validate size input
- **Limited tracking**: Leak detector can't track beyond MAX_PTRS allocations
- **No protection against double-free**: Custom free doesn't prevent double-free errors

## Algorithm Details

### Realloc Process
1. Initial allocation with malloc()
2. Fill initial data
3. Call realloc() with larger size
4. Check for realloc() success
5. Handle potential memory movement
6. Initialize new memory region

### Leak Detection Process
1. Wrapper functions intercept malloc/free calls
2. Track allocated pointers in global array
3. Remove pointers when freed
4. Report remaining pointers at program end

## Sources & AI Usage
- Original template code from lab manual
- Standard dynamic memory allocation techniques
- Went through C11 standard Caltech for malloc/realloc/free
- Memory leak detection patterns
- AI assistance for memory management logic