## Simple Calculator
This program performs basic arithmetic operations on two integers:
- Addition
- Subtraction
- Multiplication
- Division
- Modulus

---

### Code Explanation
#### Inputs
- Two integers entered by the user.
- Operation choice (`1-Add`, `2-Sub`, `3-Mul`, `4-Div`, `5-Mod`).

#### Switch-Case Operations
- **Case 1:** `a + b`
- **Case 2:** `a - b`
- **Case 3:** `a * b`
- **Case 4:** `a / b`  
  - Typecasting `(float)a / b` used to avoid integer division.  
  - Checks if `b != 0` to prevent division by zero.
- **Case 5:** `a % b` (modulus operation).
- **Default:** Error message if input is invalid.

#### Format Specifiers
- `%d` : prints integers (`int`)
- `%.3f` : prints floating-point values up to 3 decimal places

---

#### Example Run
**Addition**
Enter two numbers:
10 3
Enter the operation to be performed:
1-Add 2-Sub 3-Mul 4-Div 5-Mod
1
Add: a+b = 13

---

#### Run:
```bash
gcc task2.c -o task2
./task02
```
