# C Program: Factorial

## Overview
1. **Factorial:**  
   - Uses recursion to calculate the factorial of a given number (example: `5! = 120`).  

---

## How the Code Works
### Factorial
- **`factorial(int n)`**  
  - Implements recursion:  
    - Base Case: If `n == 0` or `n == 1`, return `1`.  
    - Recursive Case: Return `n * factorial(n - 1)`.  

**How it works for 5:**  
- factorial(5) → `5 * factorial(4)`  
- factorial(4) → `4 * factorial(3)`  
- factorial(3) → `3 * factorial(2)`  
- factorial(2) → `2 * factorial(1)`  
- factorial(1) → returns `1` (base case)  

Now the recursion “unwinds”:  
- factorial(2) = `2 * 1 = 2`  
- factorial(3) = `3 * 2 = 6`  
- factorial(4) = `4 * 6 = 24`  
- factorial(5) = `5 * 24 = 120`  

---

### `main()` Function 
- Then calls `factorial(5)` → prints `Factorial of 5 = 120`.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task4B.c -o task4B
./task4B
