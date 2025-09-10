## Check Power of 2

This program checks whether a given integer is a **power of 2** using bitwise operations.

---

### Code Explanation

#### Variables
- `int num` : stores the number entered by the user.

#### Logic
1. A number is a power of 2 if it has **exactly one bit set** in binary.  
2. The check `(num & (num - 1)) == 0` works because:  
   - Subtracting 1 flips all bits after the single 1-bit of a power of 2.  
   - ANDing with the original number results in 0 if it is a power of 2.  
3.And also ensures if `num > 0` because powers of 2 are positive.

---

#### Examples Run
Enter a number to check if it's a power of 2: 16
16 is a power of 2.

Enter a number to check if it's a power of 2: 18
18 is not a power of 2.

---
#### Limitations

- Only works for positive integers.

- Does not handle zero or negative numbers as powers of 2.

---
#### Run
```bash
gcc task7_checkPowerOfTwo.c -o task7_checkPowerOfTwo
./task7_checkPowerOfTwo
```