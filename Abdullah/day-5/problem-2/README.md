# Problem 2: Count Set Bits in 32-bit Word

## Problem
Implement a function to count the number of set bits (1s) in a 32-bit word using RISC-V assembly language.

## Approach
1. Load a 32-bit test value into register
2. Initialize counter to zero
3. Use bit manipulation to check each bit:
   - Extract least significant bit (LSB) using AND with 1
   - Add LSB value to counter
   - Right shift the number by 1 position
   - Repeat until all bits processed
4. Return count in a0 register

## Algorithm
```
Input: 32-bit number in a0
Output: Count of set bits in a0

1. Initialize counter = 0
2. While number != 0:
   a. Extract LSB using (number & 1)
   b. Add LSB to counter
   c. Right shift number by 1
3. Return counter
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
- **Input**: 0xA01B0C01 (binary: 10100000000110110000110000000001)
- **Expected Output**: 9 set bits
- **Binary Analysis**: 
  - Positions with 1s: 0, 6, 7, 11, 12, 16, 17, 24, 29
  - Total count: 9

## Assembly Implementation Details

### Key Instructions Used
- **andi**: Bitwise AND with immediate (extract LSB)
- **srli**: Logical right shift immediate
- **beqz**: Branch if equal to zero
- **add**: Add registers
- **jal/ret**: Function call/return

### Register Allocation
- **a0**: Input number, final result
- **t0**: Working copy of input number
- **t1**: Bit counter
- **t2**: Temporary for extracted bit
- **ra**: Return address

### Function Structure
```assembly
count:              # Function entry point
    mv t0, a0       # Copy input to working register
    li t1, 0        # Initialize counter

loop:               # Main counting loop
    beqz t0, done   # Exit when no more bits
    andi t2, t0, 1  # Extract LSB
    add t1, t1, t2  # Add to counter
    srli t0, t0, 1  # Shift right
    j loop          # Continue loop

done:               # Function exit
    mv a0, t1       # Move result to a0
    ret             # Return to caller
```

## Bit Manipulation Technique
This implementation uses the standard bit counting approach:
1. **Isolation**: `andi t2, t0, 1` isolates the rightmost bit
2. **Accumulation**: `add t1, t1, t2` adds the bit value (0 or 1) to counter
3. **Progression**: `srli t0, t0, 1` moves to next bit position

## Performance Analysis
- **Time Complexity**: O(n) where n is number of bits (32)
- **Space Complexity**: O(1) - uses constant number of registers
- **Optimization**: Could use more advanced techniques like Brian Kernighan's algorithm

## Alternative Approaches
1. **Brian Kernighan's Method**: `n & (n-1)` eliminates rightmost set bit
2. **Lookup Table**: Pre-computed counts for byte values
3. **Parallel Counting**: SWAR (SIMD Within A Register) techniques

## Debugging Tips
```bash
spike -d p2
(spike) r                    # Monitor t1 counter changes
```

## Expected Register State
After execution with input 0xA01B0C01:
- **a0**: 9 (final count)
- **t0**: 0 (number completely processed)
- **t1**: 9 (same as a0)

## Sources & AI Usage
- Standard bit manipulation algorithm
- RISC-V instruction set documentation
- Used AI to understand and explain assembly concepts
