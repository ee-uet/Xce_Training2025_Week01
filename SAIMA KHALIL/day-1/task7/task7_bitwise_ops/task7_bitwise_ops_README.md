## Bitwise Operations

This program demonstrates **bitwise operations** on two integers entered by the user.  

---

### Code Explanation

#### Variables
- `int a, b` : stores the two numbers entered by the user.

#### Bitwise Operations
- `a & b` : AND  
- `a | b` : OR  
- `a ^ b` : XOR  
- `~a` : NOT (bitwise complement of `a`)  
- `a << 1` : Left shift `a` by 1 bit  
- `a >> 1` : Right shift `a` by 1 bit  

---

#### Example Run
Enter two numbers :
12 5
AND: 4
OR: 13
XOR: 9
NOT: -13
Left Shift: 24
Right Shift: 6


---

#### Run
```bash
gcc task7_bitwise_ops.c -o task7_bitwise_ops
./task7_bitwise_ops
```