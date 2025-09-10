# Task 2: Bit Set/Clear Operations Comparison

## Problem
Write an assembly program for setting or clearing any bit in a 32-bit number in RISC-V assembly language. Write equivalent C code and compare the two implementations for optimization analysis.

## Approach
1. **Hand-written Assembly**: Implement bit manipulation using RISC-V bitwise instructions
2. **C Implementation**: Write equivalent C code using bitwise operators
3. **Compiler-generated Assembly**: Generate assembly from C using RISC-V toolchain
4. **Comparison Analysis**: Compare hand-written vs compiler-generated for optimization

## Bit Manipulation Operations

### Set Bit Operation
```
To set bit at position n:
result = number | (1 << n)

Example: Set bit 5 in 0x00000002
- Original: 0x00000002 (binary: ...00000010)
- Mask:     0x00000020 (binary: ...00100000) = 1 << 5
- Result:   0x00000022 (binary: ...00100010) = original | mask
```

### Clear Bit Operation
```
To clear bit at position n:
result = number & ~(1 << n)

Example: Clear bit 5 in 0x00000022
- Original: 0x00000022 (binary: ...00100010)
- Mask:     0xFFFFFFDF (binary: ...11011111) = ~(1 << 5)
- Result:   0x00000002 (binary: ...00000010) = original & mask
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
- **Input Number**: 0x00000002 (decimal: 2)
- **Bit Position**: 5
- **Set Operation**: 0x00000002 → 0x00000022 (decimal: 2 → 34)
- **Clear Operation**: 0x00000022 → 0x00000002 (decimal: 34 → 2)

## Implementation Comparison

### Hand-written Assembly Approach
```assembly
# Direct bit manipulation using RISC-V instructions
# Set bit operation
li t3, 1           # Load constant 1
sll t3, t3, a1     # Shift left by position (create mask)
or t3, t3, a0      # OR with original number

# Clear bit operation  
li t4, 1           # Load constant 1
sll t4, t4, a1     # Shift left by position (create mask)
not t4, t4         # Invert mask
and t4, t4, t3     # AND with set result
```

### C Implementation Approach
```c
unsigned int num = 0x00000002;
int position = 5;
unsigned int set, clear = 0;

set = num | (1U << 5);        // Set bit operation
clear = set & ~(1U << 5);     // Clear bit operation
```

**Characteristics:**
- **Syntax**: Standard C bitwise operators
- **Portability**: Works across different architectures
- **Optimization**: Compiler can optimize constant expressions
- **Readability**: Clear intent with operators

### Hand-written Assembly Advantages
1. **Direct Control**: Explicit register allocation
2. **Minimal Overhead**: No function call overhead
3. **Instruction Selection**: Optimal instruction choice
4. **Register Reuse**: Efficient temporary register usage

### Hand-written Assembly Disadvantages
1. **Hardcoded Values**: Position and number are fixed
2. **No Abstraction**: Cannot easily change inputs
3. **Maintenance**: Harder to modify for different operations
4. **Limited Flexibility**: Fixed bit position

### Compiler-generated Assembly Advantages
1. **Optimization**: Compiler may perform constant folding
2. **Function Structure**: Proper function prologue/epilogue
3. **Variable Handling**: Supports dynamic inputs
4. **Portability**: Can be compiled for different targets

### Compiler-generated Assembly Disadvantages
1. **Overhead**: Additional instructions for C runtime
2. **Stack Usage**: May use stack for local variables
3. **Complexity**: More complex instruction sequences
4. **Register Pressure**: May spill registers unnecessarily

## Instruction Sequence Comparison

### Hand-written Assembly Sequence
```assembly
# ~6 core instructions for both operations
li t3, 1           # 1 instruction
sll t3, t3, a1     # 1 instruction
or t3, t3, a0      # 1 instruction
li t4, 1           # 1 instruction (could reuse t3)
sll t4, t4, a1     # 1 instruction
not t4, t4         # 1 instruction (RISC-V pseudo-instruction)
and t4, t4, t3     # 1 instruction
```

### Compiler-generated Sequence
```assembly
# Likely includes function setup + optimized operations
# May use immediate values if constants are detected
# Could optimize away redundant operations
# Might inline operations if small enough
```

## Bit Manipulation Techniques

### RISC-V Specific Instructions
- **sll/srl**: Shift left/right logical
- **and/or/xor**: Bitwise logical operations
- **not**: Bitwise NOT (pseudo-instruction for xor with -1)
- **andi/ori**: Immediate bitwise operations

### Optimization Opportunities
1. **Constant Folding**: Compile-time evaluation of (1 << 5)
2. **Register Reuse**: Reusing mask register
3. **Instruction Combining**: Using immediate forms when possible
4. **Dead Code Elimination**: Removing unused intermediate values

## Performance Metrics

### Instruction Count
- **Hand-written**: ~7 instructions total
- **Compiler-generated**: Varies with optimization level
- **Efficiency**: Hand-written likely fewer instructions

### Register Usage
- **Hand-written**: 3-4 registers (a0, a1, t3, t4)
- **Compiler-generated**: Depends on optimization and calling convention

### Memory Access
- **Hand-written**: Only for initial data load
- **Compiler-generated**: May include stack operations

## Debugging Analysis

### Hand-written Version Debugging
```bash
(spike) r                    # Check a0 (input), a1 (position)
(spike) s                    # Step through bit operations
(spike) r                    # Verify t3 (set result), t4 (clear result)
```

### Register State Tracking
- **a0**: Original number (0x00000002)
- **a1**: Bit position (5)
- **t3**: Set result (0x00000022)
- **t4**: Clear result (0x00000002)


## Algorithm Efficiency Summary

| Aspect | Hand-written | Compiler-generated |
|--------|-------------|-------------------|
| **Instruction Count** | Minimal | Variable |
| **Register Usage** | Optimal | Compiler-dependent |
| **Code Size** | Smaller | Larger |
| **Flexibility** | Fixed inputs | Variable inputs |
| **Optimization** | Manual | Automatic |
| **Readability** | Assembly-level | C-level |

## Educational Insights
This comparison demonstrates:
1. **Bit Manipulation Fundamentals**: Core operations in both assembly and C
2. **Compiler Behavior**: How high-level operations translate to assembly
3. **Optimization Trade-offs**: Manual vs automatic optimization
4. **Instruction Efficiency**: Direct assembly vs generated code

## Advanced Bit Manipulation
- **Multiple Bits**: Setting/clearing bit ranges
- **Bit Testing**: Checking if specific bits are set
- **Bit Counting**: Population count operations
- **Bit Rotation**: Circular shifts for encryption

## Sources & AI Usage
- AI tools assisted in structuring README and refining explanations.