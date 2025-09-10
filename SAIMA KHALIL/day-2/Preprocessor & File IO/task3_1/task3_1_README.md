## Macros

This program demonstrates the use of **macros**.

---

### Code Explanation

#### Macros

1. **`SQUARE(x)`** : Calculates the square of `x`.
2. **`MAX2(a,b)`** : Returns the maximum of two values `a` and `b`.
3. **`MAX3(a,b,c)`** : Returns the maximum of three values using `MAX2`.
4. **`MAX4(a,b,c,d)`** : Returns the maximum of four values using `MAX3`.
5. **`TO_UPPER(c)`** : Converts a lowercase character `c` to uppercase using `toupper()`.

---

#### Example Run
Square of 5: 25
Max of 5 and 10: 10
Max of 5, 10 and 15: 15
Max of 5, 10, 15 and 20: 20
Uppercase of 'a': 'A'

---
#### Run
```bash
gcc task3_1.c -o task3_1 
./task3_1
```