# Task 3: Non-Restoring Division Algorithm Comparison

## Problem
Write an assembly program for non-restoring 32-bit unsigned division in RISC-V assembly language. Write equivalent C code and compare the two implementations for optimization analysis.

## Approach
1. **Hand-written Assembly**: Implement non-restoring division using RISC-V shift and arithmetic instructions
2. **C Implementation**: Write equivalent C code for the same algorithm
3. **Compiler-generated Assembly**: Generate assembly from C using RISC-V toolchain
4. **Comparison Analysis**: Compare hand-written vs compiler-generated for optimization

## Non-Restoring Division Algorithm
```
Non-Restoring Division Process:
1. Initialize: A=0, Q=dividend, M=divisor, n=32
2. For i = 0 to n-1:
   a. If A >= 0:
        Shift left: A,Q = A,Q << 1
        Subtract: A = A - M
      Else:
        Shift left: A,Q = A,Q << 1  
        Add: A = A + M
   b. Set quotient bit:
        If A >= 0: Q[0] = 1
        Else: Q[0] = 0
3. Final correction: If A < 0, A = A + M
4. Result: Q = quotient, A = remainder
```

## Algorithm Differences

### Restoring vs Non-Restoring
| Aspect | Restoring | Non-Restoring |
|--------|-----------|---------------|
| **Correction** | After each subtraction | Only at the end |
| **Operations** | Subtract, then restore if negative | Subtract or add based on sign |
| **Efficiency** | More operations per iteration | Fewer operations per iteration |
| **Complexity** | Simpler logic | More complex control flow |

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
- **Dividend**: 100
- **Divisor**: 7
- **Expected**: Quotient = 14, Remainder = 2
- **Verification**: 14 × 7 + 2 = 100 ✓

## Implementation Comparison

### Hand-written Assembly Approach
```assembly
# Non-restoring division with shift operations
loop:
    # Shift left: (remainder, dividend)
    slli t3, t3, 1         # remainder << 1
    srli t6, t1, 31        # get MSB of dividend
    or   t3, t3, t6        # combine with remainder
    slli t1, t1, 1         # dividend << 1

    # Decision based on remainder sign
    bltz t3, add_divisor   # if remainder < 0, add
    
sub_divisor:
    sub t3, t3, t2         # remainder -= divisor
    ori t5, t5, 1          # set quotient bit
    j continue
    
add_divisor:
    add t3, t3, t2         # remainder += divisor
    # quotient bit remains 0
```


### C Implementation Approach
```c
// Non-restoring division with bit manipulation
for (int i = 0; i < n; i++) {
    if ((int)A < 0) {
        A = (A << 1) | (Q >> 31);
        A = A + M;
    } else {
        A = (A << 1) | (Q >> 31);
        A = A - M;
    }
    
    Q = Q << 1;
    
    if ((int)A >= 0) {
        Q = Q | 1;
    } else {
        Q = Q & ~1;
    }
}

// Final correction
if ((int)A < 0) {
    *remainder = A + M;
} else {
    *remainder = A;
}
```

## Optimization Analysis

### Hand-written Assembly Advantages
1. **Register Control**: Direct register management for A, Q, M
2. **Instruction Selection**: Optimal choice of shift/arithmetic instructions
3. **Branch Optimization**: Minimal conditional branches
4. **Bit Operations**: Efficient bit extraction and insertion

### Hand-written Assembly Disadvantages
1. **Complexity**: More complex than simple repeated subtraction
2. **Debugging**: Harder to trace bit-level operations
3. **Fixed Values**: Hardcoded dividend and divisor
4. **Error Prone**: Easy to make mistakes in bit manipulation

### Compiler-generated Assembly Advantages
1. **Correctness**: Well-tested algorithm implementation
2. **Optimization**: Compiler can optimize bit operations
3. **Maintainability**: C code easier to modify and debug
4. **Variable Inputs**: Supports function parameters

### Compiler-generated Assembly Disadvantages
1. **Function Overhead**: Stack frame setup/teardown
2. **Register Spilling**: May use memory for register pressure
3. **Complex Generated Code**: Multiple instruction sequences
4. **Type Conversions**: Additional instructions for signed/unsigned

## Performance Comparison

### Instruction Count Analysis
- **Hand-written**: ~8-10 instructions per iteration × 32
- **Compiler-generated**: Variable based on optimization level

### Memory Usage
- **Hand-written**: Register-only operations
- **Compiler-generated**: May use stack for local variables

### Branch Prediction
- **Hand-written**: Predictable branch patterns
- **Compiler-generated**: May have more complex control flow

## Algorithm Complexity

### Time Complexity
- **Both Versions**: O(32) - fixed iterations for 32-bit division
- **Per Iteration**: Constant time operations
- **Total**: Significantly better than O(quotient) of simple division

### Space Complexity  
- **Both Versions**: O(1) - constant space usage
- **Registers**: 4-5 registers for core algorithm
- **Stack**: Compiler version may use additional stack space

## Debugging Strategy

### Hand-written Version Analysis
```bash
(spike) r                    # Check t1 (dividend), t2 (divisor), t3 (remainder)
(spike) s                    # Step through shift operations
(spike) until pc loop_addr   # Break at loop iterations
(spike) r                    # Monitor quotient (t5) bit updates
```

### Key Register Monitoring
- **t1**: Current dividend value (shifts each iteration)
- **t2**: Divisor (constant)
- **t3**: Remainder accumulator (sign determines operation)
- **t5**: Quotient accumulator (builds result bit by bit)

### Compiler-generated Version Analysis
```bash
(spike) r                    # Check function parameters and locals
(spike) s                    # Step through C-generated bit operations
(spike) mem stack +32        # Monitor stack variables if used
```

## Bit-level Operation Details

### Shift Operations
```assembly
# Combined left shift of (A,Q)
slli t3, t3, 1         # A = A << 1
srli t6, t1, 31        # Extract MSB of Q
or   t3, t3, t6        # A[0] = Q[31]
slli t1, t1, 1         # Q = Q << 1
```

### Quotient Bit Setting
```assembly
# Set quotient bit based on remainder sign
bltz t3, skip_set      # if A < 0, skip setting bit
ori  t5, t5, 1         # Q[0] = 1
skip_set:
slli t5, t5, 1         # Prepare for next bit
```

## Sources & AI Usage
- Google Scholar articles on non-restoring division
- GeekforGeeks [https://www.geeksforgeeks.org/computer-organization-architecture/non-restoring-division-unsigned-integer/]
- AI assistance for proper structuring REEADME and refining explanations