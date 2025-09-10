## Fibonacci Sequence Generator
This program generates the Fibonacci sequence up to `n` terms entered by the user.  


---

### Code Explanation
#### Variables
- `int n` : number of terms entered by the user.  
- `t1 = 0, t2 = 1` : the first two terms of Fibonacci.  
- `nextterm` : stores the sum of the previous two terms.  

#### Logic
1. User enters how many terms they want.  
2. Loop runs from `0` to `n-1`.  
3. Each iteration prints the current `t1` and it's basically the fibonacci number,this way sequence gets printed.  
4. Updates values as:
   - `nextterm = t1 + t2` i-e the previous fibonacci and current fibonacci number sum yields next fibonacci.
   - `t1 = t2` 
   - `t2 = nextterm`  

---

#### Example Run

Enter the number of terms for fibonacci sequence:
5
The terms are:
0
1
1
2
3

---

#### Run:
```bash
gcc task3_fibonacci.c -o task3_fibonacci
./task3
```
