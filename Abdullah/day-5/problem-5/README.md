# Problem 5: Insertion Sort Algorithm

## Problem
Implement an insertion sort algorithm for sorting an array using RISC-V assembly language.

## Approach
1. Load array and its size from memory
2. Use nested loop structure:
   - Outer loop: iterate from 2nd element to end (i = 1 to n-1)
   - Inner loop: find correct position for current element
3. For each element:
   - Save current element as key
   - Compare with previous elements
   - Shift larger elements to the right
   - Insert key at correct position
4. Continue until entire array is sorted

## Algorithm
```
insertion_sort(arr[], n):
1. for i = 1 to n-1:
     key = arr[i]
     j = i - 1
     
     while j >= 0 and arr[j] > key:
         arr[j+1] = arr[j]  // shift right
         j = j - 1
     
     arr[j+1] = key  // insert at correct position
```

## How to Run

### Build and Execute
```bash
make          # Assemble and link
make run      # Run with Spike simulator
make debug    # Debug step-by-step
make clean    # Remove generated files
```

## Example Test Case
- **Input Array**: [4, 5, 3, 6, 1, 2]
- **Expected Output**: [1, 2, 3, 4, 5, 6]
- **Step-by-step Sorting**:
  - Start: [4, 5, 3, 6, 1, 2]
  - i=1: [4, 5, 3, 6, 1, 2] (5 >= 4, no change)
  - i=2: [3, 4, 5, 6, 1, 2] (insert 3 at beginning)
  - i=3: [3, 4, 5, 6, 1, 2] (6 >= 5, no change)
  - i=4: [1, 3, 4, 5, 6, 2] (insert 1 at beginning)
  - i=5: [1, 2, 3, 4, 5, 6] (insert 2 at position 1)

## Assembly Implementation Details

### Key Instructions Used
- **la**: Load address of array/size
- **lw/sw**: Load/store words from/to memory
- **slli**: Shift left for array indexing (multiply by 4)
- **add/addi**: Address arithmetic
- **bge/ble**: Branch comparisons
- **j**: Unconditional jump

### Register Allocation
- **t0**: Array base address
- **t1**: Array size (n)
- **t2**: Outer loop counter (i)
- **t3**: Array base for calculations
- **t4**: Element offset calculation
- **t5**: Current element (key)
- **t6**: Inner loop counter (j)
- **s0**: Temporary array access
- **s1**: Array offset calculation
- **s2**: Element being compared

### Memory Layout
```
.data section:
array: .word 4,5,3,6,1,2     # Array to sort (6 elements)
size:  .word 6               # Array size
```

### Algorithm Structure
```assembly
_start:
    la t0, array        # Load array base address
    lw t1, size         # Load array size
    li t2, 1            # Initialize i = 1

outer_loop:
    bge t2, t1, done    # if i >= size, exit
    
    # Get current element arr[i]
    la t3, array
    slli t4, t2, 2      # t4 = i * 4
    add t3, t3, t4      # t3 = &arr[i]
    lw t5, 0(t3)        # t5 = arr[i] (key)
    
    addi t6, t2, -1     # j = i - 1

inner_loop:
    blt t6, zero, insert    # if j < 0, insert
    
    # Get arr[j]
    la s0, array
    slli s1, t6, 2      # s1 = j * 4
    add s0, s0, s1      # s0 = &arr[j]
    lw s2, 0(s0)        # s2 = arr[j]
    
    ble s2, t5, insert  # if arr[j] <= key, insert
    
    # Shift: arr[j+1] = arr[j]
    sw s2, 4(s0)        # arr[j+1] = arr[j]
    addi t6, t6, -1     # j--
    j inner_loop

insert:
    # Insert key at position j+1
    la s0, array
    addi t6, t6, 1      # j+1
    slli s1, t6, 2      # (j+1) * 4
    add s0, s0, s1      # &arr[j+1]
    sw t5, 0(s0)        # arr[j+1] = key
    
    addi t2, t2, 1      # i++
    j outer_loop
```

## Sorting Process Analysis

### Insertion Mechanics
1. **Element Selection**: Pick next unsorted element
2. **Position Finding**: Compare with sorted portion
3. **Element Shifting**: Move larger elements right
4. **Insertion**: Place element in correct position

### Array Indexing
- **Base Address**: Array starting location
- **Element Access**: base + (index × 4) for word alignment
- **Pointer Arithmetic**: Essential for memory operations


## Memory Access Pattern
```
Pass 1: [4][5][3][6][1][2]  →  [4][5][3][6][1][2]
Pass 2: [4][5][3][6][1][2]  →  [3][4][5][6][1][2]
Pass 3: [3][4][5][6][1][2]  →  [3][4][5][6][1][2]
Pass 4: [3][4][5][6][1][2]  →  [1][3][4][5][6][2]
Pass 5: [1][3][4][5][6][2]  →  [1][2][3][4][5][6]
```

## Debugging Strategy
```bash
spike -d p5
(spike) r                        # Check loop counters
```

## Sources & AI Usage
- Used Google to relate insertion sort concepts
- GeeksforGeeks [https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/]
- Used AI to help properly structure README and explain concepts clearly