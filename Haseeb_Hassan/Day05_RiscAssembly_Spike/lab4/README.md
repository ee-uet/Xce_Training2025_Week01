# Lab 4 - RISC-V Assembly Programming

## Problem

This lab focuses on implementing fundamental algorithms and operations using RISC-V assembly language. The lab consists of 5 distinct problems, each demonstrating different programming concepts:

1. **Absolute Difference** (`abs_diff`) - Calculate the absolute difference between two numbers
2. **Bit Counting** (`count_bits`) - Count the number of set bits (1s) in a binary number
3. **Factorial Calculation** (`factorial`) - Compute factorial using iterative approach
4. **Array Reversal** (`reverse_array`) - Reverse elements in an array
5. **Sorting Algorithm** (`sorting`) - Implement insertion sort algorithm

Each problem is organized in separate directories with complete build systems and demonstrates core assembly programming concepts including arithmetic operations, loops, conditionals, memory access, and algorithm implementation.

## Approach

### Problem-Specific Implementations

**Problem 1: Absolute Difference**
- Uses conditional branching (`bge`) to determine which number is larger
- Implements subtraction to calculate absolute difference
- Demonstrates basic arithmetic and control flow

**Problem 2: Bit Counting**
- Implements bit manipulation using `andi` and `srli` instructions
- Uses loop counter to process all 32 bits
- Demonstrates bitwise operations and accumulation

**Problem 3: Factorial**
- Uses iterative approach with multiplication (`mul`) instruction
- Implements countdown loop with conditional termination
- Demonstrates loop control and arithmetic operations

**Problem 4: Array Reversal**
- Manipulates array elements using memory load/store operations
- Uses pointer arithmetic for array indexing
- Demonstrates memory access patterns and data movement

**Problem 5: Sorting (Insertion Sort)**
- Implements complete insertion sort algorithm
- Uses nested loops with complex control flow
- Demonstrates advanced memory operations and algorithm implementation
- Includes both inline and function-based implementations

### Technical Approach
- **Spike Simulator Compatibility**: All programs use proper Spike exit sequences
- **Memory Organization**: Proper use of `.text`, `.data`, and `.tohost` sections  
- **Register Usage**: Efficient use of temporary registers (`t0`-`t9`)
- **Control Flow**: Implementation of loops, conditionals, and function calls

## How to Run

### Prerequisites
- RISC-V toolchain (`riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`)
- Spike RISC-V simulator
- Make utility
- Link script (`link.ld`) in each problem directory

### Building and Running Individual Problems

Navigate to each problem directory and use the provided Makefile:

```bash
# Problem 1: Absolute Difference
cd problem_1
make
make run

# Problem 2: Bit Counting  
cd problem_2
make
make run

# Problem 3: Factorial
cd problem_3
make
make run

# Problem 4: Array Reversal
cd problem_4
make
make run

# Problem 5: Sorting
cd problem_5
make
make run
```

### Build Process for Each Problem
```bash
# Assemble source file
riscv64-unknown-elf-as -o <name>.o <name>.s

# Link with custom linker script
riscv64-unknown-elf-ld -T link.ld -o <name> <name>.o

# Run with Spike simulator
spike <name>
```

### Directory Structure
```
lab4/
├── problem_1/
│   ├── abs_diff.s
│   ├── abs_diff.o
│   ├── abs_diff
│   ├── link.ld
│   └── Makefile
├── problem_2/
│   ├── count_bits.s
│   ├── count_bits.o
│   ├── count_bits
│   ├── link.ld
│   └── Makefile
├── problem_3/
│   ├── factorial.s
│   ├── factorial.o
│   ├── factorial
│   ├── link.ld
│   └── Makefile
├── problem_4/
│   ├── reverse_array.s
│   ├── reverse_array.o
│   ├── reverse_array
│   ├── link.ld
│   └── Makefile
└── problem_5/
    ├── sorting.s
    ├── sorting.o
    ├── sorting
    ├── link.ld
    └── Makefile
```

## Examples

### Problem 1: Absolute Difference
```assembly
# Input: a=15, b=6
# Expected: |15-6| = 9
# Result stored in register t2
```

### Problem 2: Bit Counting
```assembly
# Input: 0b101101 (binary: 101101)
# Expected: 4 set bits (1s)
# Result stored in register t1
```

### Problem 3: Factorial
```assembly
# Input: n=5
# Expected: 5! = 120
# Result stored in register t1
```

### Problem 4: Array Reversal
```assembly
# Input array: [1, 2, 3, 4, 5]
# Expected: [5, 4, 3, 2, 1]
# Array modified in place
```

### Problem 5: Sorting
```assembly
# Input array: [5, 3, 4, 1, 2]
# Expected: [1, 2, 3, 4, 5]
# Uses insertion sort algorithm
```

### Sample Build Output
```bash
$ make
riscv64-unknown-elf-as -o abs_diff.o abs_diff.s
riscv64-unknown-elf-ld -T link.ld -o abs_diff abs_diff.o

$ make run
spike abs_diff
# Program executes and terminates properly
```

## Known Limitations

### General Limitations
1. **No Output Display**: Programs don't print results - values remain in registers/memory
2. **Hardcoded Values**: All input values are hardcoded in the assembly source
3. **Limited Error Handling**: No bounds checking or error validation
4. **Simulator Dependency**: Programs specifically designed for Spike simulator

### Problem-Specific Limitations

**Problem 1 (Absolute Difference):**
- Only works with the specific hardcoded values (15, 6)
- No overflow protection for large numbers

**Problem 2 (Bit Counting):**
- Fixed to process exactly 32 bits
- Hardcoded input value (0b101101)

**Problem 3 (Factorial):**
- Limited to small values due to no overflow handling
- Iterative only (no recursive implementation)

**Problem 4 (Array Reversal):**
- Fixed array size and elements
- No dynamic memory allocation

**Problem 5 (Sorting):**
- Fixed array size (5 elements)
- Only implements insertion sort
- No comparison function flexibility

### Technical Limitations
1. **Register Conflicts**: No register allocation optimization
2. **Memory Layout**: Fixed memory sections without dynamic allocation  
3. **Debugging**: Limited debugging symbols in release builds
4. **Portability**: Spike-specific exit sequences limit portability

## Technical Details

### RISC-V Instructions Used

**Arithmetic Operations:**
- `add`, `sub`, `mul` - Basic arithmetic
- `addi` - Immediate arithmetic
- `li` - Load immediate values

**Logical Operations:**
- `andi` - Bitwise AND with immediate
- `srli` - Shift right logical immediate

**Memory Operations:**
- `lw`, `sw` - Load/store words
- `la` - Load address

**Control Flow:**
- `bge`, `ble`, `blt`, `bnez`, `beqz` - Conditional branches
- `j`, `jal` - Unconditional jumps
- `ret` - Function return

**System Operations:**
- `ebreak` - Debugger breakpoint (commented versions)
- Spike exit sequence using `tohost`

### Assembly Sections
- `.text` - Executable code section
- `.data` - Initialized data section  
- `.tohost` - Spike simulator communication section

### Register Usage Patterns
- `t0`-`t9` - Temporary registers for computations
- `ra` - Return address for function calls
- `s0`-`s2` - Saved registers in complex algorithms

## Sources & AI Usage

- RISC-V Instruction Set Manual for instruction reference
- Spike simulator documentation for proper exit sequences
- Computer architecture principles for algorithm implementation
- Assembly language programming best practices
- GNU assembler and linker documentation for build process
- AI tools were used for register usage and instructions reference