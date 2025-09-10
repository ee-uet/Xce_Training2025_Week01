# Palindrome Checker in C  

This program checks if a given string is a **palindrome** . It performs the comparison **case-insensitively** using `tolower`.  

---

## Code Explanation  

#### Function: 
`is_palindrome(const char *s)`  
- Uses two pointers:  
  - `start` : beginning of the string  
  - `end` : end of the string  
- Compares characters while moving `start` forward and `end` backward.  
- If all characters match, returns **1** (Yes).  
- If any mismatch occurs, returns **0** (No).  

---

## Example Run  

```text
Input: madam
Output:
is Palindrome? 1
1=Yes
0=No
 
Input: saias
Output:
is Palindrome? 0
1=Yes
0=No
```

#### Run  
```bash
gcc task_2_1.c -o task_2_1
./task_2_1
```