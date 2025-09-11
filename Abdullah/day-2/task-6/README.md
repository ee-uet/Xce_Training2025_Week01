# Task 6: Final Task - Booth's Multiplication Algorithm

## Problem
Implement Booth's multiplication algorithm in C with:
- Separate functions for shifting and adding for visualization
- Two signed integers as input, return their product
- Bit manipulation operators for efficient multiplication
- Comprehensive test cases including edge cases and overflow scenarios

## Approach
1. **Helper Functions**:
   - `add()`: Bitwise addition without using + operator
   - `twos_complement()`: Convert number to two's complement
   - `arithmatic_right_shifter()`: Perform arithmetic right shift on A,Q registers

2. **Main Algorithm**:
   - Initialize registers A (accumulator), Q (multiplier), Q₁ (extra bit)
   - Iterate through 32 bits
   - Check Q₀ and Q₁ bits to determine operation
   - Add M or -M to A based on bit pattern
   - Perform arithmetic right shift

3. **Test Suite**:
   - Positive × Positive numbers
   - Negative × Positive combinations
   - Edge cases: zero, one, INT_MAX, INT_MIN
   - Overflow scenarios

## How to Run

### Compilation
```bash
gcc -o booth_multiplication booth_multiplication.c
```

### Execution
```bash
./booth_multiplication
```

## Example Output
```
Test 7 * 3 = 21 (Expected 21)
Test -7 * 3 = -21 (Expected -21)
Test 7 * -3 = -21 (Expected -21)
Test -7 * -3 = 21 (Expected 21)
Test 1234 * 0 = 0 (Expected 0)
Test 999 * 1 = 999 (Expected 999)
Test 2147483647 * 1 = 2147483647 (Expected 2147483647)
Test -2147483648 * 1 = -2147483648 (Expected -2147483648)
Test 50000 * 50000 = -1794967296 (Expected -1794967296, may overflow)
```

## Design Notes
- Uses 32-bit register implementation
- Arithmetic right shift preserves sign bit
- Bitwise addition avoids using arithmetic operators
- Comprehensive test coverage for various scenarios

## Key Concepts Demonstrated
- **Booth's Algorithm**: Efficient multiplication using bit patterns
- **Bitwise Operations**: AND, OR, XOR, shift operations
- **Two's Complement**: Negative number representation
- **Arithmetic Shifts**: Sign-preserving right shifts
- **Register Simulation**: A, Q, Q₁ register behavior

## Booth's Algorithm Steps
1. Initialize `A=0`, Q=multiplier, `Q₁=0`, M=multiplicand
2. For each bit (32 iterations):
   - Examine Q₀ (LSB of Q) and Q₁
   - If `Q₀Q₁ = 01: A = A + M`
   - If `Q₀Q₁ = 10: A = A - M`
   - If `Q₀Q₁ = 00 or 11: No operation`
   - Arithmetic right shift A,Q,Q₁
3. Result is in combined A,Q registers

## Algorithm Complexity
- **Time Complexity**: O(n) where n is number of bits (32)
- **Space Complexity**: O(1) - uses fixed registers
- **Bit Operations**: More efficient than repeated addition

## Assumptions & Edge Cases
- Uses 32-bit integer arithmetic
- Handles signed integer overflow according to C standard
- Two's complement representation for negative numbers
- Arithmetic right shift preserves sign bit

## Known Limitations
- **Return value issue**: Function returns truncated result instead of full 64-bit product
- **Overflow handling**: Large products may overflow 32-bit integers
- **Performance**: Not optimized for modern processors with hardware multiplication
- **Portability**: Assumes 32-bit int and specific bit manipulation behavior


## Test Cases Covered
- **Basic operations**: Small positive/negative combinations
- **Identity tests**: Multiplication by 0 and 1
- **Boundary values**: `INT_MAX` and `INT_MIN`
- **Overflow scenarios**: Large numbers that exceed 32-bit range
- **Sign combinations**: All four sign combinations

## Sources & AI Usage
- Got help from [https://www.geeksforgeeks.org/computer-organization-architecture/computer-organization-booths-algorithm/] for understanding Booth's algorithm
- Watched [https://www.youtube.com/watch?v=9h8kz7bX5rM] for visual explanation
- Standard Booth's multiplication algorithm
- Bitwise arithmetic implementation techniques
- Comprehensive test case design patterns
- AI assistance for Arithmetic part (type of `combined`) implementation