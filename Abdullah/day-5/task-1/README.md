# Task 1: Restoring Division Algorithm Comparison

## Problem
Write an assembly program for restoring division algorithm in RISC-V assembly language. Use the toolchain to build assembly file from C code and compare the two implementations for optimization analysis.

## Approach
1. **Hand-written Assembly**: Implement restoring division using basic RISC-V instructions
2. **C Implementation**: Write equivalent C code for the same algorithm
3. **Compiler-generated Assembly**: Generate assembly from C using RISC-V toolchain
4. **Comparison Analysis**: Compare hand-written vs compiler-generated for optimization

## Restoring Division Algorithm
```
Restoring Division Process:
1. Initialize: A=0, Q=dividend, M=divisor, n=32
2. For i = 1 to n:
   a. Shift left: A,Q = A,Q << 1
   b. Subtract: A = A - M
   c. If A < 0 (negative):
        A = A + M (restore)
        Q[0] = 0
      Else:
        Q[0] = 1
3. Result: Q = quotient, A = remainder
```

## How to Run

### Build Both Versions
```bash
make all          # Build both hand-written and compiler-generated
```

### Run Specific Versions
```bash
make run1         # Run hand-written assembly
make run2         # Run compiler-generated assembly
```

### Debug Analysis
```bash
make debug1       # Debug hand-written version
make debug2       # Debug compiler-generated version
```

### Clean
```bash
make clean        # Remove all generated files
```

## Test Case Analysis
- **Dividend**: 37
- **Divisor**: 5
- **Expected**: Quotient = 7, Remainder = 2
- **Verification**: 7 × 5 + 2 = 37 

## Implementation Comparison

### Hand-written Assembly Approach
```assembly
# Simple repeated subtraction method
# More readable but less efficient
loop:
    blt t4, t2, done     # if remainder < divisor -> exit
    sub t4, t4, t2       # remainder -= divisor  
    addi t3, t3, 1       # quotient += 1
    j loop
```

**Characteristics:**
- **Algorithm**: Repeated subtraction (simpler than true restoring division)
- **Efficiency**: O(quotient) time complexity
- **Readability**: Very clear and easy to understand
- **Instructions**: ~4 instructions per iteration
- **Optimization**: None - straightforward implementation

### C Implementation Approach
```c
// True restoring division algorithm
// More complex but theoretically efficient
for (int i = 1; i <= n; i++) {
    A = (A<<1 | Q >> 31);  // Shift A,Q left
    Q = Q<<1;
    A = A-M;               // Subtract divisor
    if ((int)A > 0) {      // Check if positive
        A += M;            // Restore if negative
        Q = Q & ~1;        // Set Q[0] = 0
    } else {
        Q = Q | 1;         // Set Q[0] = 1
    }
}
```


## Optimization Analysis

### Hand-written Assembly Advantages
1. **Simplicity**: Easy to understand and debug
2. **Direct Control**: Explicit register usage
3. **Minimal Instructions**: Straightforward operation sequence
4. **Predictable**: No hidden compiler optimizations

### Hand-written Assembly Disadvantages
1. **Algorithm Choice**: Uses less efficient repeated subtraction
2. **Performance**: O(n) where n = quotient value
3. **Large Numbers**: Slow for large quotients

### Compiler-generated Assembly Advantages
1. **Algorithm**: Implements true restoring division
2. **Optimization**: Compiler may optimize bit operations
3. **Consistency**: Standard implementation
4. **Fixed Time**: Always 32 iterations regardless of input

### Compiler-generated Assembly Disadvantages
1. **Complexity**: More complex instruction sequences
2. **Overhead**: Additional setup
3. **Register Pressure**: May use more registers
4. **Less Readable**: Harder to follow generated code

## Performance Comparison

### Instruction Count Analysis
- **Hand-written**: ~4 instructions × quotient value
- **Compiler-generated**: ~10-15 instructions × 32 iterations
- **Crossover Point**: Hand-written faster for small quotients

### Memory Usage
- **Hand-written**: Minimal register usage (3-4 registers)
- **Compiler-generated**: More registers, possible stack usage

### Accuracy Comparison
- **Hand-written**: Good for integer division
- **Compiler-generated**: Handles edge cases better

## Debugging Strategy

### Hand-written Version Analysis
```bash
(spike) r                    # Check t3 (quotient), t4 (remainder)
(spike) s                    # Step through subtraction loop
(spike) until pc 0x80000014  # Break at loop condition
```

### Compiler-generated Version Analysis
```bash
(spike) r                    # Check function parameters and locals
(spike) s                    # Step through bit manipulation
(spike) mem stack_area +100  # Check stack if used
```

## Sources & AI Usage
- Used Google to research restoring division algorithm
- GeeksforGeeks [https://www.geeksforgeeks.org/computer-organization-architecture/restoring-division-algorithm-unsigned-integer/]
- AI assistance for proper structuring README and explanations