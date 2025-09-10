# Problem 3: Factorial Calculation

## Problem
Implement a program to calculate the factorial of a number using RISC-V assembly language.

## Approach
1. Load the input number (n) into register
2. Initialize result accumulator to 1
3. Use iterative multiplication:
   - Multiply current result by current number
   - Decrement the number
   - Repeat until number reaches 0
4. Result stored in accumulator register

## Algorithm
```
Input: n (number to calculate factorial)
Output: n! (factorial result)

factorial(n):
1. result = 1
2. while n > 0:
     result = result * n
     n = n - 1
3. return result
```

## How to Run

### Build and Execute
```bash
make          # Assemble and link
make run      # Run with Spike simulator
make debug    # Debug step-by-step
make clean    # Remove generated files
```

## Example Test Case
- **Input**: 5
- **Expected Output**: 5! = 5 × 4 × 3 × 2 × 1 = 120
- **Calculation Steps**:
  - Start: result=1, n=5
  - Step 1: result=1×5=5, n=4
  - Step 2: result=5×4=20, n=3
  - Step 3: result=20×3=60, n=2
  - Step 4: result=60×2=120, n=1
  - Step 5: result=120×1=120, n=0
  - Final: 120

## Assembly Implementation Details

### Key Instructions Used
- **li**: Load immediate value
- **mul**: Multiply registers
- **addi**: Add immediate (for decrementing)
- **beqz**: Branch if equal to zero
- **jal/ret**: Function call/return (if using function)

### Register Allocation
- **t0**: Input number (n), decremented each iteration
- **t1**: Result accumulator
- **t2**: Temporary registers for calculations

### Algorithm Structure
```assembly
_start:
    li t0, 5        # Load input number (n=5)
    li t1, 1        # Initialize result = 1
    jal ra, factorial

factorial:
    beqz t0, done   # if n == 0, exit
    mul t1, t1, t0  # result = result * n
    addi t0, t0, -1 # n = n - 1
    j factorial     # repeat loop

done:
    # t1 contains factorial result
```

## Mathematical Properties
- **0! = 1** (by definition)
- **1! = 1**
- **n! = n × (n-1)!** (recursive definition)
- **Growth**: Factorial grows extremely rapidly

## Limitations and Considerations
1. **Integer Overflow**: 
   - 32-bit: Maximum ~12! (479,001,600)
   - 64-bit: Maximum ~20! 
   - No overflow checking in basic implementation

2. **Input Validation**:
   - No check for negative numbers
   - Assumes valid positive integer input

3. **Algorithm Choice**:
   - Iterative approach used (vs recursive)
   - More efficient in terms of stack usage

## Error Analysis
**Potential Issue in Original Code**: The original implementation appears to have a logic error:
- Uses `beqz t0, done` but then jumps to `factorial` label unconditionally
- This creates an infinite loop since the condition check happens after the label
- Should either use proper loop structure or recursive calls

**Corrected Logic Should Be**:
```assembly
factorial_loop:
    beqz t0, done
    mul t1, t1, t0
    addi t0, t0, -1
    j factorial_loop
```

## Debugging Tips
```bash
spike -d p3
(spike) until pc 0x80000004  # Stop at start
(spike) r                    # Check initial values
(spike) s                    # Step through multiplication
(spike) r                    # Monitor t1 (result) changes
```

## Expected Register States
For input n=5:
- **Initial**: t0=5, t1=1
- **After 1st iteration**: t0=4, t1=5
- **After 2nd iteration**: t0=3, t1=20
- **After 3rd iteration**: t0=2, t1=60
- **After 4th iteration**: t0=1, t1=120
- **After 5th iteration**: t0=0, t1=120 (done)


## Sources & AI Usage
- Standard iterative factorial algorithm
- RISC-V instruction set reference
- Used AI to understand and explain assembly concepts