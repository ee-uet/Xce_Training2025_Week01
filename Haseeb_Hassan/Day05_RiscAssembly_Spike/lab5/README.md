# Lab 5 - Division Algorithms in C and RISC-V Assembly

## Problem

This lab implements three fundamental division and bit manipulation algorithms, each provided in both C and RISC-V assembly versions for comparison and understanding:

1. **Restoring Division** (`div_restoring`) - Implements unsigned restoring division algorithm
2. **Bit Set/Clear Operations** (`setting_clearing`) - Demonstrates bit manipulation operations
3. **Non-Restoring Division** (`non_restoring`) - Implements signed non-restoring division algorithm

Each task is organized with dual implementations to demonstrate the translation from high-level C code to low-level assembly language, highlighting the fundamental operations and control structures used in division algorithms.

## Approach

### Task 1: Restoring Division Algorithm
**C Implementation:**
- Uses shift-and-subtract approach for unsigned division
- Implements 32-bit precision with MSB extraction
- Returns quotient and remainder via pointer

**Assembly Implementation:**
- Direct translation using RISC-V shift and arithmetic instructions
- Uses registers for quotient, remainder, and loop control
- Demonstrates unsigned comparison (`bgeu`) for trial subtraction

### Task 2: Bit Setting and Clearing
**C Implementation:**
- Implements `set_bit()` using OR operation with bit mask
- Implements `clear_bit()` using AND operation with inverted mask
- Uses bit shifting for position-specific operations

**Assembly Implementation:**
- Direct bit manipulation using `sll`, `or`, `and`, and `not` instructions
- Hardcoded bit position (3) and test value (0x55AA55AA)
- Demonstrates fundamental bitwise operations in assembly

### Task 3: Non-Restoring Division Algorithm
**C Implementation:**
- Implements signed division with conditional add/subtract operations
- Uses bit extraction and shifting for algorithm implementation
- Handles both positive and negative remainder cases

**Assembly Implementation:**
- Complex control flow with conditional branching
- Uses function calls (`jal ra`) for modular design
- Implements remainder correction for proper signed division

### Dual Implementation Strategy
Each task provides both C and assembly versions to demonstrate:
- Algorithm translation from high-level to low-level languages
- Register allocation and memory management strategies
- Control flow implementation differences
- Performance and complexity trade-offs

## How to Run

### Prerequisites
- RISC-V toolchain (`riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`, `riscv64-unknown-elf-gcc`)
- Spike RISC-V simulator
- Make utility
- Link script (`link.ld`) in each implementation directory

### Directory Structure
```
lab5/
├── task_1/
│   ├── from_assembly/
│   │   ├── div_restoring.s
│   │   ├── div_restoring.o
│   │   ├── div_restoring
│   │   ├── link.ld
│   │   └── Makefile
│   └── from_c/
│       ├── div_restoring.c
│       ├── div_restoring.s
│       ├── div_restoring
│       ├── link.ld
│       └── Makefile
├── task_2/
│   ├── from_assembly/
│   │   ├── setting_clearing.s
│   │   ├── setting_clearing.o
│   │   ├── setting_clearing
│   │   ├── link.ld
│   │   └── Makefile
│   └── from_c/
│       ├── setting_clearing.c
│       ├── setting_clearing.s
│       ├── setting_clearing
│       ├── link.ld
│       └── Makefile
└── task_3/
    ├── from_assembly/
    │   ├── non_restoring.s
    │   ├── non_restoring.o
    │   ├── non_restoring
    │   ├── link.ld
    │   └── Makefile
    └── from_c/
        ├── non_restoring.c
        ├── non_restoring.s
        ├── non_restoring
        ├── link.ld
        └── Makefile
```

### Building and Running

**For Assembly Implementation (from_assembly folders):**
```bash
cd task_1/from_assembly
make
make run

cd task_2/from_assembly
make
make run

cd task_3/from_assembly
make
make run
```

**For C Implementation (from_c folders):**
```bash
cd task_1/from_c
make
make run

cd task_2/from_c
make
make run

cd task_3/from_c
make
make run
```

### Build Process Details

**Assembly Version:**
```bash
riscv64-unknown-elf-as -o <name>.o <name>.s
riscv64-unknown-elf-ld -T link.ld -o <name> <name>.o
spike <name>
```

**C Version:**
```bash
riscv64-unknown-elf-gcc -march=rv64g -mabi=lp64d -static -mcmodel=medany -fvisibility=hidden -nostdlib -nostartfiles -T link.ld <name>.c -o <name>
spike <name>
```

## Examples

### Task 1: Restoring Division
**C Version Input/Output:**
```c
// Input: n=50, d=7
// Expected: quotient=7, remainder=1
// 50 ÷ 7 = 7 remainder 1
```

**Assembly Version:**
```assembly
# Input: t0=100, t1=7
# Expected: t2=14 (quotient), t3=2 (remainder)  
# 100 ÷ 7 = 14 remainder 2
```

### Task 2: Bit Operations
**C Version:**
```c
// Input: n=0x55AA55AA, pos=3
// After set_bit: n=0x55AA55AA | (1<<3) = 0x55AA55AA | 0x8 = 0x55AA55AA
// After clear_bit: n=0x55AA55AA & ~(1<<3) = 0x55AA55AA & 0xFFFFFFF7
```

**Assembly Version:**
```assembly
# Input: t0=0x55AA55AA, position=3
# Set bit 3: OR with 0x8
# Clear bit 3: AND with ~0x8
```

### Task 3: Non-Restoring Division
**C Version:**
```c
// Input: num=13, den=3
// Expected: quotient≈4, remainder=1
// Uses signed division algorithm
```

**Assembly Version:**
```assembly
# Input: a0=25, a1=4  
# Expected: quotient=6, remainder=1
# 25 ÷ 4 = 6 remainder 1
```

## Known Limitations

### General Limitations
1. **No Visual Output**: Results stored in registers/memory without display
2. **Hardcoded Inputs**: All test values are hardcoded in source
3. **Limited Error Handling**: No division by zero or overflow protection
4. **Simulator Dependency**: Designed specifically for Spike simulator

### Algorithm-Specific Limitations

**Task 1 (Restoring Division):**
- Only handles unsigned division
- Fixed 32-bit precision
- No optimization for special cases (powers of 2)

**Task 2 (Bit Operations):**
- Hardcoded bit position and test values
- No bounds checking for bit positions
- Limited to 32-bit operations

**Task 3 (Non-Restoring Division):**
- Complex remainder correction logic
- May not handle all edge cases correctly
- Different input values between C and assembly versions

### Implementation Differences
1. **C vs Assembly Inputs**: Different test values used in C and assembly versions
2. **Memory Management**: C version uses stack/heap, assembly uses registers
3. **Function Calls**: C uses standard calling conventions, assembly uses custom approach
4. **Error Recovery**: Inconsistent error handling between implementations

## Technical Details

### Division Algorithm Concepts

**Restoring Division:**
- Shift dividend left, bring MSB into remainder
- Compare remainder with divisor
- If remainder ≥ divisor: subtract divisor, set quotient bit
- If remainder < divisor: keep remainder, clear quotient bit
- Repeat for all bits

**Non-Restoring Division:**  
- More efficient than restoring division
- Uses add/subtract operations based on remainder sign
- Requires remainder correction at the end
- Better performance for signed division

### RISC-V Instructions Demonstrated

**Arithmetic Operations:**
- `add`, `sub` - Basic arithmetic
- `slli`, `srli` - Logical shift operations
- `or`, `and`, `not` - Bitwise operations

**Control Flow:**
- `bgeu` - Unsigned branch greater/equal
- `bge`, `blt` - Signed comparisons  
- `jal ra` - Function calls with return address
- `ret` - Function return

**Memory and System:**
- `la`, `sd` - Address loading and store doubleword
- Spike exit sequences using `tohost`

### Register Usage Patterns
- `t0`-`t5` - Temporary registers for computations
- `a0`, `a1` - Function arguments (Task 3)
- `ra` - Return address for function calls
- Careful register preservation across operations

### Compilation Differences
- **Assembly**: Direct register allocation and instruction selection
- **C**: Compiler optimization and standard calling conventions
- **Memory Layout**: Different approaches to data organization
- **Performance**: Assembly provides direct control, C offers portability

## Sources & AI Usage

- Computer arithmetic algorithms from standard references
- RISC-V Instruction Set Manual for instruction specifications
- Spike simulator documentation for proper system integration
- Division algorithm theory from computer architecture textbooks
- Bit manipulation techniques from systems programming references
- AI tools were used for algorithm optimization and register usage patterns