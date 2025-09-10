## Swapping Two Numbers Using Pointers

This program demonstrates **swapping two integers** using pointers .

---

### Code Explanation

#### Function
- `void swap(int *a, int *b)` :  
  Swaps the values of two integers using their pointers.
  1. Store the value of `*a` in a temporary variable `temp`.  
  2. Assign `*b` to `*a`.  
  3. Assign `temp` to `*b`.

#### Steps
1. Read two integers `a` and `b` from the user.  
2. Call `swap(&a, &b)` to swap their values.  
3. Print the values of `a` and `b` after swapping.

---

#### Example Run
Enter two numbers :
5 10
Value of a and b after swapping :
10 5


---

#### Run
```bash
gcc task1_2.c -o task1_2
./task1_2
```