# RISC-V Assembly Programming Lab


This lab provides hands-on experience with RISC-V assembly programming using Spike simulator and GNU toolchain for low-level programming concepts.

## Prerequisites

- RISC-V GNU Toolchain (riscv64-unknown-elf-gcc, riscv64-unknown-elf-as)
- Spike RISC-V ISA Simulator
- Text editor (vim/nano)


### Task 1: Installation
- Installed RISC-V toolchain: `sudo apt-get install gcc-riscv64-unknown-elf`
- Downloaded and built Spike simulator from GitHub
- Added Spike to PATH: `export PATH=$PATH:/opt/riscv/bin`

### Task 2: Basic Example
- Created linker script (link.ld) with entry point at 0x80000000
- Implemented basic counter loop in assembly
- Successfully assembled, linked, and ran on Spike


## Problems Implemented

1. **Absolute Difference:** Calculate absolute difference between two numbers
2. **Count Set Bits:** Count number of set bits in 32-bit word
3. **Factorial:** Calculate factorial of a number recursively
4. **Reverse Array:** In-place array reversal algorithm
5. **Insertion Sort:** Sorting algorithm implementation

## Advanced Tasks

### Task A: Restoring Division Algorithm
- Assembly implementation of restoring division
- C code comparison for optimization analysis
- Performance testing on Spike

### Task B: Bit Manipulation
- Set/clear any bit in 32-bit number
- Assembly vs C code comparison
- Optimization analysis

### Task C: Non-Restoring Division
- 32-bit unsigned division implementation
- Assembly vs C code performance comparison
- Spike execution analysis

## Key Commands

### Build and Run
```bash
# Assemble and link
riscv64-unknown-elf-as -o program.o program.S
riscv64-unknown-elf-ld -T link.ld -o program program.o

# Run on Spike
spike program

# Debug mode
spike -d --log-commits program
```

### Makefile Usage
```bash
make PROG=filename    # Build specific program
make run PROG=filename    # Run program
make debug PROG=filename  # Debug program
make clean            # Clean build files
```

### Debugging Commands
```
(spike) until pc 0x80000000  # Run until address
(spike) r                    # Show registers
(spike) s                    # Step instruction
(spike) mem 0x80000000 +32   # Show memory
```

## Learning Outcomes

- RISC-V assembly language syntax and instruction set
- Spike simulator usage and debugging techniques
- GNU toolchain for cross-compilation
- Low-level algorithm implementations
- Assembly optimization techniques
- Comparison of hand-written vs compiler-generated assembly


