# Final Task – Booth's Multiplication Algorithm

## Problem
Implement Booth's multiplication algorithm in C to handle signed integer multiplication using bitwise operations (shifts, addition, two’s complement).  
The program should:
- Correctly multiply positive and negative integers.
- Demonstrate the algorithm through multiple test cases.
- Work within 32-bit signed integer range.

---

## Approach
1. **Two’s Complement Function**  
   Implemented `twos_complement()` to convert a number into its negative equivalent.

2. **Bitwise Addition Function**  
   Wrote a helper `add(a, b)` to perform integer addition using only bitwise operations.

3. **Booth’s Multiplication**  
   - Initialize `A = 0`, `Q = multiplier`, `M = multiplicand`, `Q-1 = 0`.
   - For 32 iterations:
     - If `(Q0, Q-1) = (1,0)` → `A = A - M`.
     - If `(Q0, Q-1) = (0,1)` → `A = A + M`.
     - Perform arithmetic right shift on `(A, Q, Q-1)`.
   - Combine final `(A, Q)` into a 64-bit result.

4. **Testing**  
   Created multiple test cases covering:
   - Positive × Positive
   - Positive × Negative
   - Negative × Negative
   - Zero multiplication
   - Edge cases (`INT_MAX`, `INT_MIN`)

---

## How to Run
1. Save code in `Booth_multiplier.c`.
2. Compile:
   ```bash
   gcc Booth_multiplier .c -o Booth_multiplier 
   ./Booth_multiplier 

## Example Output
 5 *  3 = 15 (expected 15)
-5 *  3 = -15 (expected -15)
 5 * -3 = -15 (expected -15)
-5 * -3 = 15 (expected 15)
 0 *  7 = 0 (expected 0)
 -7 *  0 = 0 (expected 0)
 1 * 123 = 123 (expected 123)
INT_MAX * 1 = 2147483647 (expected 2147483647)
INT_MIN * 1 = -2147483648 (expected -2147483648)

## Known Limitations

Only works correctly for 32-bit signed integers.

Multiplication beyond 32-bit limits may not behave as expected (overflow).

Algorithm is for educational demonstration — less efficient than using hardware multiplication.

## Source

Youtube video 
link: https://youtu.be/cWfaw7b3jKY?si=TYuSvmSpTnDQlPo1