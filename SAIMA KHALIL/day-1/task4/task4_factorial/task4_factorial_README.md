## Factorial (Using Recursion)  
This program calculates the factorial of a number entered by the user using recursion.  

---

### Code Explanation  
#### Variables  
- `int n` : number entered by the user.  
- `fact` : stores the factorial result.  

#### Logic  
1. User enters a number `n`.  
2. Function `factorial(n)` is called recursively:  
   - **Base case**: if `n == 0` or `n == 1`, return `1`.  
   - **Recursive case**: return `n * factorial(n-1)`.  
3. The result is printed on the screen.  

---

#### Example Run  

Enter the number you want to find factorial of ! :
5
Factorial is : 120

---

#### Run:  
```bash
gcc task4_factorial.c -o task4_factorial
./task4_factorial
```