# C Program: Custom String Functions & Palindrome Check

## Overview
This program demonstrates **custom implementations** of common string functions in C without directly using the standard library’s functions like `strlen`, `strcpy`, and `strcmp`.  
It also includes a function to check if a string is a **palindrome** (case-insensitive).  

---

## Code Structure

- **`my_strlen(const char *s)`**  
  Counts and returns the length of a string.  

- **`my_strcpy(char *dest, const char *src)`**  
  Copies a string from `src` to `dest`.  

- **`my_strcmp(const char *s1, const char *s2)`**  
  Compares two strings lexicographically.  
  - Returns `0` if both are equal  
  - Returns positive if `s1 > s2`  
  - Returns negative if `s1 < s2`  

- **`is_palindrome(const char *s)`**  
  Checks whether a given string is a palindrome.  
  Ignores case using `tolower()`.  

- **`main()`**  
  Tests the above functions with example strings.  

---

##  How the Code Works

### 1. String Length (`my_strlen`)

* Starts from the first character.
* Increments a counter until it finds the null terminator `'\0'`.

Example:

```c
char str[] = "Hello";
int len = my_strlen(str);  // len = 5
```

---

### 2. String Copy (`my_strcpy`)

* Iterates through each character of the source string.
* Copies characters into the destination buffer.
* Adds `'\0'` at the end to terminate the string.

Example:

```c
char src[] = "World";
char dest[10];
my_strcpy(dest, src);
// dest now contains "World"
```

---

### 3. String Compare (`my_strcmp`)

* Compares characters of two strings one by one.
* If all match → returns `0`.
* If a mismatch occurs → returns the ASCII difference of the first mismatch.

Example:

```c
int diff = my_strcmp("abc", "abd"); // returns 'c' - 'd' = -1
```

---

### 4. Palindrome Check (`is_palindrome`)

* Uses two pointers: one at the start, one at the end.
* Compares characters ignoring case using `tolower()`.
* Moves inward until pointers meet.
* If all matched → string is a palindrome.

Example:

```c
is_palindrome("Madam");    // Yes
is_palindrome("Whatever"); // No
```

---

## Extra Example Runs

```c
printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes" : "No");
```

### Output

```sh
Palindrome? Yes
```

---

## ASCII + Binary Difference Table (`my_strcmp("What", "Whatever")`)

At first, `"What"` matches `"What"` in `"Whatever"`.  
After that, `"What"` ends (`'\0'`) but `"Whatever"` continues with `'e'`.

| Position | s1 (`"What"`) | s2 (`"Whatever"`) | ASCII (s1) | ASCII (s2) | Binary (s1) | Binary (s2) | Difference (s1 - s2) |
| -------- | ------------- | ----------------- | ---------- | ---------- | ----------- | ----------- | -------------------- |
| 1        | W             | W                 | 87         | 87         | 01010111    | 01010111    | 0                    |
| 2        | h             | h                 | 104        | 104        | 01101000    | 01101000    | 0                    |
| 3        | a             | a                 | 97         | 97         | 01100001    | 01100001    | 0                    |
| 4        | t             | t                 | 116        | 116        | 01110100    | 01110100    | 0                    |
| 5        | `\0` (end)    | e                 | 0          | 101        | 00000000    | 01100101    | **-101**             |

Since `'\0' - 'e' = -101`, the result of `my_strcmp("What", "Whatever")` is **`-101`**.

## How to Compile and Run

### Using GCC
```sh
gcc task2.c -o task2
./task2
```

### Example Run

```sh
Len = 5
Copied: World
0
Palindrome? No
```

---
