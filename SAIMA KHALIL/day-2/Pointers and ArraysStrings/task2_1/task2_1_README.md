## Custom String Functions in C

This program implements  **`strlen`**, **`strcpy`**, and **`strcmp`** using pointers.

---

### Code Explanation

#### Functions

1. **`my_strlen(const char *s)`**  
   Calculates the length of a string by iterating through the characters until the null terminator `\0` is reached.  
   - Uses a pointer `ptr` to traverse the string.  
   - Returns the difference `ptr - s` as the string length.

2. **`my_strcpy(char *dest, const char *src)`**  
   Copies the content of `src` string to `dest` string.  
   - Iterates through `src` and copies each character to `dest`.  
   - Null-terminates `dest` after copying.

3. **`my_strcmp(const char *s1, const char *s2)`**  
   Compares two strings character by character.  
   - Iterates until a difference is found or until the end of one string.  
   - Returns the difference of ASCII values of the first non-matching character (`s1 - s2`).

---

#### Example Run
Length = 5
Copied: saima
Comparison: 18

 Here : `strcmp("saima", "abbb")` returns `115-97 = 18` (ASCII difference of first differing characters `'s'` and `'a'`).

---

#### Run
```bash
gcc task2_1.c -o task2_1
./task2_1
```