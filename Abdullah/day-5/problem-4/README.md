# Problem 4: Array Reversal In-Place

## Problem
Implement a program to reverse an array in-place using RISC-V assembly language with pointer manipulation.

## Approach
1. Load array base address and size
2. Set up two pointers: start (beginning) and end (last element)
3. Use two-pointer technique:
   - Swap elements at start and end positions
   - Move start pointer forward
   - Move end pointer backward
   - Continue until pointers meet or cross
4. Array is reversed in original memory location

## Algorithm
```
Input: Array of integers, size n
Output: Same array reversed in-place

reverse_array(arr, size):
1. start_ptr = arr[0] address
2. end_ptr = arr[size-1] address
3. while start_ptr < end_ptr:
     swap(*start_ptr, *end_ptr)
     start_ptr += 4 (next element)
     end_ptr -= 4 (previous element)
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
- **Input Array**: [1, 2, 3, 4, 5]
- **Expected Output**: [5, 4, 3, 2, 1]
- **Step-by-step Process**:
  - Initial: [1, 2, 3, 4, 5], start=0, end=4
  - Swap 1↔5: [5, 2, 3, 4, 1], start=1, end=3
  - Swap 2↔4: [5, 4, 3, 2, 1], start=2, end=2
  - Pointers meet: stop

## Assembly Implementation Details

### Key Instructions Used
- **la**: Load address
- **lw**: Load word from memory
- **sw**: Store word to memory
- **slli**: Shift left logical immediate (for array indexing)
- **add/addi**: Address arithmetic
- **blt**: Branch if less than

### Register Allocation
- **t0**: Start pointer (moves forward)
- **t1**: End pointer (moves backward)
- **t2**: Array size
- **t3**: Offset calculation
- **t4, t5**: Temporary values for swapping


### Algorithm Structure
```assembly
_start:
    la t0, array          # t0 = start pointer
    lw t2, size           # t2 = array size
    
    # Calculate end pointer
    la t1, array          # base address
    slli t3, t2, 2        # t3 = size * 4 (bytes)
    add t1, t1, t3        # end pointer (past last)
    addi t1, t1, -4       # adjust to last element

loop:
    blt t1, t0, done      # if end < start, done
    
    # Swap elements
    lw t4, 0(t0)          # load from start
    lw t5, 0(t1)          # load from end
    sw t5, 0(t0)          # store to start
    sw t4, 0(t1)          # store to end
    
    # Move pointers
    addi t0, t0, 4        # start += 4
    addi t1, t1, -4       # end -= 4
    j loop
```

## Pointer Arithmetic Details
- **Array Element Size**: 4 bytes per word
- **Start Pointer**: Begins at array[0]
- **End Pointer**: Begins at array[size-1]
- **Pointer Movement**: ±4 bytes per iteration
- **Termination**: When start_ptr >= end_ptr

## Memory Access Pattern
```
Initial State:
[1][2][3][4][5]
 ^           ^
start       end

After 1st swap:
[5][2][3][4][1]
    ^       ^
   start   end

After 2nd swap:
[5][4][3][2][1]
       ^
   start/end (done)
```

## Edge Cases Handled
1. **Empty Array**: Size = 0, no iterations
2. **Single Element**: Size = 1, no swaps needed
3. **Even Length**: All elements swapped
4. **Odd Length**: Middle element stays in place


## Debugging Tips
```bash
spike -d p4
(spike) until pc 0x80000014  # Stop at loop start
(spike) mem 0x80000000 +20   # View initial array
(spike) s                    # Step through swap
(spike) mem 0x80000000 +20   # View array changes
(spike) r                    # Check pointer positions
```

## Memory Viewing
To see array contents during debugging:
```bash
(spike) mem array_address +20    # Shows 5 words (20 bytes)
```

## Expected Memory States
- **Before**: 0x00000001 0x00000002 0x00000003 0x00000004 0x00000005
- **After**:  0x00000005 0x00000004 0x00000003 0x00000002 0x00000001


## Sources & AI Usage
- Used AI assistance for proper structuring of README and refining explanations.