# Problem 1: Absolute Difference Between Two Numbers

## Problem
Implement a program to calculate the absolute difference between two numbers using RISC-V assembly language.

## Approach
1. Load two numbers into registers a0 and a1
2. Calculate the difference (a0 - a1)
3. Check if the result is negative
4. If negative, negate the result to get absolute value
5. Store final result in a0

## Algorithm
```
1. Load num1 into a0, num2 into a1
2. Calculate diff = a0 - a1
3. If diff < 0:
     result = -diff
   Else:
     result = diff
4. Return result in a0
```

## How to Run

### Prerequisites
- RISC-V GNU Toolchain installed
- Spike simulator installed and in PATH

### Build and Execute
```bash
make          # Assemble and link
make run      # Run with Spike
make debug    # Debug with Spike
make clean    # Clean generated files
```

## Example Execution
```bash
$ make run
# Calculates absolute difference between -5 and 10
# Expected result: 15 (stored in register a0)
```

## Assembly Code Structure
```assembly
_start:
    li a0, -5        # Load first number
    li a1, 10        # Load second number
    j abs_diff       # Jump to calculation

abs_diff:
    sub a2, a0, a1   # Calculate difference
    blt a2, x0, pos  # Branch if negative
    mv a0, a2        # Move result to a0
    j done

pos:
    sub a0, x0, a2   # Negate to get absolute value
```

## Key RISC-V Instructions Used
- **li**: Load immediate value
- **sub**: Subtract registers
- **blt**: Branch if less than
- **mv**: Move register (pseudo-instruction for `addi rd, rs, 0`)
- **j**: Jump (unconditional branch)

## Register Usage
- **a0**: First input number, final result
- **a1**: Second input number
- **a2**: Temporary storage for difference
- **t0, t1**: Used for Spike exit mechanism

## Design Notes
- Uses two input numbers: -5 and 10
- Implements conditional branching for sign checking
- Result stored in a0 register following RISC-V calling convention

## Known Issues in Original Code
There appears to be a logic error in the original implementation:
- In the `pos:` label, the code does `sub a0, x0, a0` instead of `sub a0, x0, a2`
- This computes `0 - a0` instead of `0 - a2` (the actual difference)
- With inputs -5 and 10, this gives result 5 instead of expected 15

## Expected vs Actual Behavior
- **Input**: a0 = -5, a1 = 10
- **Expected**: |(-5) - 10| = |-15| = 15
- **Actual**: Due to bug, result is 5

## Debugging with Spike
```bash
make debug
```

## Memory Layout
- **Code starts at**: 0x80000000
- **Exit mechanism**: Uses tohost/fromhost for Spike communication

## Sources & AI Usage
- Original assembly implementation provided
- Standard RISC-V instruction set usage
- Used AI for documentation and explanation generation
