# RISC-V Assembly Programming Solutions

This repository contains RISC-V assembly implementations of fundamental algorithms and mathematical operations, designed to run on the Spike RISC-V simulator.

## Programs Overview

| Problem | File                    | Description                     | Input          | Output           |
|---------|-------------------------|---------------------------------|----------------|------------------|
| 1       | `absolute_difference.s` | Calculate absolute difference   | Two integers   | |num1 - num2|    |
| 2       | `count_bits.s`          | Count set bits in 32-bit word   | 32-bit number  | Number of 1 bits |
| 3       | `factorial.s`           | Calculate factorial iteratively | Integer n      | n!               |
| 4       | `array_reverse.s`       | Reverse array in-place          | Integer array  | Reversed array   |
| 5       | `insertion_sort.s`      | Sort array using insertion sort | Unsorted array | Sorted array     |

## Problem Descriptions

### 1. Absolute Difference
**Purpose**: Calculate the absolute difference between two numbers
**Algorithm**: 
- Compute `num1 - num2`
- If result is negative, negate it using two's complement
- Example: `|25 - 40| = |-15| = 15`

### 2. Count Set Bits
**Purpose**: Count the number of 1 bits in a 32-bit integer
**Algorithm**:
- Process each bit from LSB to MSB
- Extract bit using AND with 1, accumulate count
- Shift number right by 1 bit, repeat for 32 iterations
- Example: `0x12345678` has multiple 1 bits to count

### 3. Factorial Calculation
**Purpose**: Calculate factorial of a number using iterative approach
**Algorithm**:
- Initialize accumulator to 1, counter to n
- Multiply accumulator by counter, decrement counter
- Continue until counter reaches 0
- Example: `5! = 5 × 4 × 3 × 2 × 1 = 120`

### 4. Array Reversal
**Purpose**: Reverse an integer array in-place using two-pointer technique
**Algorithm**:
- Set left pointer to start (0), right pointer to end (n-1)
- Swap elements at left and right positions
- Move pointers toward center until they meet
- Example: `[1,2,3,4,5]` becomes `[5,4,3,2,1]`

### 5. Insertion Sort
**Purpose**: Sort an array in ascending order
**Algorithm**:
- Start from second element (index 1)
- Compare with sorted portion (left side)
- Shift larger elements right, insert current element at correct position
- Continue until all elements are processed
- Example: `[7,3,5,2,9,1]` becomes `[1,2,3,5,7,9]`

## Code Structure

### Common Elements
All programs include:
- **Data section**: Input values and result storage
- **Text section**: Assembly code implementation
- **Spike exit mechanism**: Proper termination for simulator
- **Comments**: Explaining key algorithmic steps

### Memory Layout
```
.data
- Input values (numbers, arrays)
- Result storage locations

.text
- Main program logic
- Function implementations
- Loop structures

.section .tohost
- Spike simulator communication
```

## Register Usage Conventions

| Register Type | Usage                            | Examples                      |
|---------------|----------------------------------|-------------------------------|
| `a0-a1`       | Function arguments/return values | Input parameters              |
| `t0-t6`       | Temporary registers              | Loop counters, calculations   |
| `s0-s1`       | Saved registers                  | Array base, persistent values |
| `ra`          | Return address                   | Function calls                |

## Running the Programs

### Prerequisites
- RISC-V toolchain (riscv64-unknown-elf-gcc)
- Spike RISC-V simulator
- Proxy kernel (pk)

### Build and Run
```bash
# Assemble
riscv64-unknown-elf-as -o program.o program.s

# Link
riscv64-unknown-elf-ld -o program program.o

# Run in Spike
spike pk program
```

### Alternative with GCC
```bash
# Compile and link
riscv64-unknown-elf-gcc -o program program.s

# Run
spike pk program
```

## Expected Results

### Test Cases and Outputs

**Absolute Difference** (25, 40):
- Input: num1=25, num2=40
- Output: result=15

**Count Bits** (0x12345678):
- Input: 0x12345678 (binary: 00010010001101000101011001111000)
- Output: Count of 1 bits in the number

**Factorial** (5):
- Input: n=5
- Output: result=120

**Array Reverse** ([1,2,3,4,5]):
- Input: [1,2,3,4,5]
- Output: [5,4,3,2,1]

**Insertion Sort** ([7,3,5,2,9,1]):
- Input: [7,3,5,2,9,1]
- Output: [1,2,3,5,7,9]

## Key Features

### Algorithm Implementation
- **Efficient algorithms**: Optimal time/space complexity
- **In-place operations**: Minimal memory usage where possible
- **Iterative approaches**: Avoiding stack overflow issues
- **Edge case handling**: Division by zero, empty arrays, etc.

### RISC-V Specific
- **Standard calling conventions**: Proper register usage
- **Memory addressing**: Word-aligned data access
- **Spike compatibility**: Exit mechanisms and simulator support
- **Modular design**: Reusable functions and clear interfaces

### Code Quality
- **Clear commenting**: Explaining algorithmic steps
- **Consistent style**: Uniform indentation and naming
- **Error handling**: Basic checks for invalid inputs
- **Testable design**: Predefined test cases with expected results

## Debugging Tips

### Using Spike Debugger
```bash
# Run with interactive debugger
spike -d pk program

# Useful commands in debugger
(spike) reg 0              # Show registers
(spike) mem 0x10000000     # Show memory
(spike) pc                 # Show program counter
(spike) step               # Single step execution
```

### Common Issues
- **Memory alignment**: Ensure word-aligned data access
- **Register clobbering**: Save/restore registers in functions
- **Branch conditions**: Check comparison logic carefully
- **Loop bounds**: Verify counter initialization and termination

## Extensions

### Possible Enhancements
- Add recursive factorial implementation
- Implement other sorting algorithms (bubble, selection)
- Add error checking for invalid inputs
- Optimize bit counting using population count instructions
- Add floating-point arithmetic examples

This collection provides a solid foundation for understanding RISC-V assembly programming and implementing common algorithms in low-level code.
