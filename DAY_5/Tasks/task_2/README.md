# Bit Manipulation: Set and Clear a Bit (RISC-V Assembly + C)

This project demonstrates **bit manipulation** to **set and clear a specific bit** in an integer, implemented in both:
- **RISC-V Assembly** (`task_2_as.s`)
- **C implementation** (`task_2.c`)

It also provides a `Makefile` to build and run both versions using the RISC-V toolchain and Spike simulator.

---
## Approach 
Algorithm

Set a bit:

set = num | (1 << position)


Sets the bit at the specified position to 1.

Clear a bit:

clear = set & ~(1 << position)


Clears the bit at the same position (sets to 0).

The program stores the result in memory (result) in assembly.

Equivalent operations are performed in C using bitwise operators.

## Files

- `task_2_as.s` → Assembly implementation for setting and clearing a bit.
- `task_2.c` → C implementation performing the same task.
- `start.s` → Startup file for C programs when building bare-metal.
- `link.ld` → Linker script for building RISC-V executables.
- `Makefile` → Automates build, run, debug, and cleanup.

---

## Requirements

- **RISC-V Toolchain** (`riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`, `riscv64-unknown-elf-gcc`)
- **Spike Simulator** (`spike`)

---

## Build Instructions

### 1. Build Assembly version
```bash.

##-------------------------------
## Run Programs

Run Assembly only:

make run1


Run C file Assembly:

make run2

debug Assembly only:

make debug1


debug C file Assembly:

make debug2

##--------------------------------------
## Example

Initial number: 0x00000002

Bit position: 5

Assembly Result:

After set: 0x00000022

After clear: 0x00000002

C Result: Same values using bitwise operations.

##------------------------------------
## Limitations

Fixed bit-width: Works for 32-bit integers. For larger integers, shifts must be adjusted.

No input validation: If the position exceeds 31 (for 32-bit), behavior is undefined.

Bare-metal only: Assembly version is written for Spike simulation, not for Linux/host systems.

No multiple-bit operations: Only supports setting and clearing a single bit. Masks for multiple bits are not included.