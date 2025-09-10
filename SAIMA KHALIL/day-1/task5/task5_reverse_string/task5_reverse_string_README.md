## Reverse a String

This program takes a string as input, reverses it, and then prints its length.

---

### Code Explanation

#### Variables
- `char str[100]` : stores the input string.  
- `char reversed[100]` : stores the reversed string.  
- `int len = 0` : keeps track of the string length.  

#### Steps
1. **Input string**  
   - `fgets(str, sizeof(str), stdin);`  
   - Reads the string including the newline `\n` when Enter is pressed.  

2. **Remove newline**  
   - `str[strcspn(str, "\n")] = 0;`  
   - `strcspn` finds the index of `\n` and replaces it with `\0`.  

3. **Find length**  
   - Loop runs until `'\0'` is found to count characters.  

4. **Reverse string**  
   - For loop copies characters from the end of `str` to `reversed`.  
   - Finally adds `'\0'` to terminate the reversed string.  

5. **Output**  
   - Prints both reversed string and its length.  

---

#### Example Run
Enter a string: saima
Reversed string: amias
Length of the string: 5

---

#### Run:
```bash
gcc task5_reverse_string.c -o task5_reverse_string
./task5_reverse_string
```