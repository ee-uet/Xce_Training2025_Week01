# RISC-V Assembly vs C Code Comparison Tasks

This repository contains implementations of three fundamental algorithms in both hand-written RISC-V assembly and C code, along with compiler-generated assembly for comparison and optimization analysis.

## Task Overview

| Task | Algorithm              | Files                    | Purpose                              |
|------|------------------------|--------------------------|--------------------------------------|
| 1    | Restoring Division     | `Task1_C.s`, `Task1_C.c` | Compare division implementations     |
| 2    | Bit Manipulation       | `Task2_C.s`, `Task2_C.c` | Compare bit set/clear operations     |
| 3    | Non-Restoring Division | `Task3_C.s`, `Task3_C.c` | Compare advanced division algorithms |

## Task 1: Restoring Division Algorithm

### Problem Description
Implement the restoring division algorithm that divides two 32-bit unsigned integers using the classical long division method with restoration steps.

### Files Structure
```
Task1/
├── Task1_hand.s             # Hand-written assembly
├── Task1_C.c                # C implementation
├── Task1_C.s                # Compiler-generated assembly
├── link.ld                  # Link file for RiscV compilation
└── Comparison_assembly.md   # Optimization comparison
```

### Algorithm Overview
- **Input**: Dividend and divisor
- **Process**: 32-bit iterative division with remainder restoration
- **Output**: Quotient and remainder
- **Example**: 13 ÷ 3 = 4 remainder 1

### Assembly Implementation Features
- Direct register manipulation
- Explicit loop control
- Manual bit shifting operations
- Immediate value loading

### C Implementation Features
- Structured algorithm with clear logic
- Variable-based state management
- Compiler optimization opportunities
- Portable across architectures

## Task 2: Bit Manipulation (Set/Clear)

### Problem Description
Implement functions to set or clear any specific bit in a 32-bit number using bitwise operations and masks.

### Files Structure
```
Task2/
├── Task2_hand.s             # Hand-written assembly
├── Task2_C.c                # C implementation
├── Task2_C.s                # Compiler-generated assembly
├── link.ld                  # Link file for RiscV compilation
└── Comparison_assembly.md   # Optimization comparison
```

### Algorithm Overview
- **Input**: Number, bit position, operation (set/clear)
- **Process**: Create mask and apply bitwise operations
- **Output**: Modified number
- **Example**: Set bit 5 in 0x12345678 → 0x12345678 | (1<<5)

### Key Operations
- **Set bit**: `number |= (1 << position)`
- **Clear bit**: `number &= ~(1 << position)`
- **Mask creation**: `1 << position`

## Task 3: Non-Restoring Division

### Problem Description
Implement the non-restoring division algorithm for 32-bit unsigned integers, which is more efficient than restoring division as it avoids restoration steps.

### Files Structure
```
Task3/
├── Task3_hand.s             # Hand-written assembly
├── Task3_C.c                # C implementation
├── Task3_C.s                # Compiler-generated assembly
├── link.ld                  # Link file for RiscV compilation
└── Comparison_assembly.md   # Optimization comparison
```

### Algorithm Overview
- **Input**: 32-bit dividend and divisor
- **Process**: Bit-by-bit division without restoration
- **Output**: Quotient and remainder
- **Example**: 123456789 ÷ 12345 = 10000 remainder 6789

### Key Features
- No restoration steps required
- Handles negative remainders during processing
- More efficient than restoring division
- Final correction step for positive remainder

## Build Instructions

### Prerequisites
```bash
# RISC-V toolchain
sudo apt-get install gcc-riscv64-unknown-elf

# Spike simulator
git clone https://github.com/riscv/riscv-isa-sim.git
cd riscv-isa-sim && ./configure && make && sudo make install
```

### Building Assembly Files
```bash
# Assemble and link hand-written assembly
riscv64-unknown-elf-as -o program.o program.s
riscv64-unknown-elf-ld -o program program.o

# Or use GCC
riscv64-unknown-elf-gcc -o program program.s
```

### Building C Files
```bash
# Compile C to executable
riscv64-unknown-elf-gcc -o program_c program.c

# Generate assembly from C (for comparison)
riscv64-unknown-elf-gcc -S -o program_gcc.s program.c

# With optimization flags
riscv64-unknown-elf-gcc -O2 -S -o program_gcc_opt.s program.c
```

### Running on Spike
```bash
# Run assembly version
spike pk program

# Run C version
spike pk program_c

# Run with debugger
spike -d pk program
```

## Comparison Methodology

### Performance Metrics
1. **Instruction Count**: Total instructions executed
2. **Code Size**: Binary size in bytes
3. **Register Usage**: Number of registers utilized
4. **Memory Access**: Load/store operations count
5. **Branch Instructions**: Conditional jumps count

### Optimization Analysis

#### Hand-Written Assembly Advantages
- **Direct control**: Exact instruction sequence
- **Register optimization**: Efficient register allocation
- **No overhead**: No function call overhead
- **Minimal instructions**: Only necessary operations

#### Compiler-Generated Assembly Advantages
- **Advanced optimization**: Loop unrolling, instruction reordering
- **Register allocation**: Sophisticated register assignment algorithms
- **Dead code elimination**: Removes unused code
- **Constant propagation**: Compile-time constant evaluation

#### C Code Advantages
- **Readability**: Clear algorithmic logic
- **Maintainability**: Easy to modify and debug
- **Portability**: Works across different architectures
- **Safety**: Less prone to register clobbering errors

## Expected Results

### Task 1: Restoring Division (13 ÷ 3)
- **Hand-written Assembly**: ~40-50 instructions, direct bit manipulation
- **Compiler-generated**: ~30-40 instructions with optimizations
- **Result**: Quotient = 4, Remainder = 1

### Task 2: Bit Manipulation (Set bit 5 in 0x12345678)
- **Hand-written Assembly**: ~6-8 instructions, direct bit operations
- **Compiler-generated**: ~4-6 instructions with constant folding
- **Result**: 0x12345678 → 0x12345658 (if clearing) or 0x12345678 (if setting)

### Task 3: Non-Restoring Division (123456789 ÷ 12345)
- **Hand-written Assembly**: ~35-45 instructions, optimized loop
- **Compiler-generated**: ~25-35 instructions with loop optimizations
- **Result**: Quotient = 10000, Remainder = 6789

## Optimization Comparison Results

### General Findings

#### Code Size
- **C with -O0**: Largest, includes debug info and unoptimized code
- **C with -O2**: Moderate, good balance of size and performance
- **Hand-written**: Smallest, only essential instructions

#### Performance
- **Hand-written**: Predictable performance, no surprises
- **C with -O2**: Often fastest due to advanced optimizations
- **C with -O0**: Slowest, includes unnecessary operations

#### Maintainability
- **C code**: Highest, clear algorithm structure
- **Compiler-generated**: Moderate, readable but optimized
- **Hand-written**: Lowest, requires assembly knowledge

## Analysis Tools

### Instruction Counting
```bash
# Use spike with instruction counting
spike --isa=rv64gc pk program

# Or use performance counters
spike -d pk program
(spike) reg 0    # Check register states
(spike) step     # Single step execution
```

### Code Size Analysis
```bash
# Check binary size
riscv64-unknown-elf-size program

# Disassemble to see instructions
riscv64-unknown-elf-objdump -d program
```

### Performance Profiling
```bash
# Generate assembly with timing info
riscv64-unknown-elf-gcc -S -fverbose-asm program.c

# Compare instruction sequences
diff hand_written.s compiler_generated.s
```

## Learning Outcomes

### Assembly Programming Skills
- Direct hardware control understanding
- Register allocation strategies
- Instruction-level optimization techniques
- RISC-V architecture specifics

### Compiler Technology Understanding
- Optimization technique recognition
- Code generation strategies
- Performance vs. size trade-offs
- Cross-platform portability considerations

### Algorithm Implementation
- Low-level algorithm understanding
- Bit manipulation techniques
- Division algorithm variants
- Performance optimization strategies

## Conclusions

This comparative study demonstrates the trade-offs between hand-written assembly and compiler-generated code:

- **Hand-written assembly** provides maximum control but requires expertise
- **Compiler optimizations** often produce superior performance with less effort
- **C code** offers the best balance of readability and performance
- **Context matters**: Choice depends on requirements (performance, maintainability, development time)

The results provide insights into modern compiler capabilities and the continued relevance of assembly language programming in performance-critical applications.

## References

- RISC-V Instruction Set Manual
- Computer Architecture: A Quantitative Approach (Hennessy & Patterson)
- Compiler Design Principles and Techniques
- RISC-V Assembly Programming Guide
