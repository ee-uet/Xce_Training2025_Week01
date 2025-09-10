# Task 2 – Pointers and Arrays/Strings

## Problem
1. **Custom String Functions**  
   Implement your own versions of:
   - `strlen()`
   - `strcpy()`
   - `strcmp()`  
   using **pointer arithmetic only** (no `<string.h>`).

2. **Palindrome Checker**  
   Write a program that checks if a given string is a **palindrome** (case insensitive).

---

## Approach

### 🔹 Custom String Functions
- **`my_strlen()`**: Use pointer increment to count characters until the null terminator.  
- **`my_strcpy()`**: Copy characters using pointer assignment in a loop.  
- **`my_strcmp()`**: Compare characters using pointer dereferencing.

### 🔹 Palindrome Checker
- Use two pointers → one at the **start** and one at the **end** of the string.  
- Compare characters **case-insensitively** while moving pointers toward the center.  
- Return **0 if mismatch found**, **1 if palindrome**.


##  How to Run

### Custom String Functions
```bash
gcc -o custom_string_functions custom_string_functions.c
./custom_string_functions
````

### Palindrome Checker

```bash
gcc -o palindrome_checker palindrome_checker.c
./palindrome_checker
```



## Example Output

### Custom String Functions

```
Len = 6
Copied: World
Compare: -1
```

### Palindrome Checker (if given correct input)

```
Palindrome? Yes
```


## Design Notes

* String functions use only **pointer arithmetic**.
* Palindrome checker uses the **two-pointer technique**.
* Functions follow **standard C library behavior** patterns.


## Key Concepts Demonstrated

* **Pointer Iteration**: Moving through strings with pointer increment.
* **String Termination**: Checking for null terminator (`'\0'`).
* **Two-Pointer Technique**: Start and end pointers moving toward center.
* **Character Comparison**: Direct character comparison using dereferencing.

---

## Assumptions & Edge Cases

* Uses custom `my_strlen()` for string length calculation.
* Case-insensitive palindrome checking using `tolower` from `<ctype.h>`.
* Assumes **null-terminated strings**.
* Handles **empty strings** and **single-character strings** correctly.
* `my_strcmp()` returns `-1`, `0`, or `1` for lexicographical comparison.

---

## Known Limitations

* **Buffer overflow risk**: `my_strcpy()` doesn’t check destination buffer size.
* **No null pointer validation**: Functions don’t handle invalid pointers.


## Sources & AI Usage

* Original template code from **lab manual**.
* Standard string manipulation algorithms from slides shared in class.
* Two-pointer palindrome checking technique.
* Case-insensitive conversion using `tolower` from `<ctype.h>` inspired by
  [Stack Overflow](https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c).

