## Pointer 

This program demonstrates the use of **pointers** ,   accessing and modifying a variable through its pointer.

---

### Code Explanation

#### Variables
- `int a = 10` : a simple integer variable.  
- `int *ptr = &a` : a pointer that stores the address of `a`.

#### Logic
1. Print the **address** of `a` using `&a`.  
2. Print the **value** of `a` directly.  
3. Print the **value** of `a` using the pointer `*ptr`.  
4. Modify the value of `a` through the pointer (`*ptr = 100`).  
5. Print the **new value** of `a` after modification.

---

#### Example Run
Address of a is : 6422296
Value of a is : 10
Value of a using pointer is : 10
New value of a after modification via pointer is : 100


---

#### Run
```bash
gcc task1_1.c -o task1_1
./task1_1
