
---

# C Program: Enum Weekday Mapper (Task 8)

## Problem

This program maps a number (1–7) entered by the user to a corresponding day of the week using an `enum` and a `switch-case` statement.

## Approach

1. Define an `enum Weekday` with values:

   * `Mon = 1`, `Tue = 2`, `Wed = 3`, `Thr = 4`, `Fri = 5`, `Sat = 6`, `Sun = 7`.
2. Prompt the user for an integer input (`n`).
3. Use a `switch-case` statement to print the corresponding day of the week.

### Key Concepts Used

* **Enumerations (`enum`)**: To assign meaningful names to integer constants.
* **Switch-Case**: To map numeric input to weekday names.

## How to Run

To run this program:

1. Copy the code into a file named `task8.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task8 task8.c
   ```
3. Run the compiled executable:

   ```bash
   ./task8
   ```

## Examples

### Example 1: Input 1

```
Input day number: 1
Monday
```

### Example 2: Input 6

```
Input day number: 6
Saturday
```

### Example 3: Input 7

```
Input day number: 7
Sunday
```

## Known Limitations

* The program does not handle invalid inputs (e.g., numbers outside 1–7).
* Input assumes an integer is entered.

## Sources & AI Usage

The program was written from scratch for practice. AI assistance was used to prepare this `README.md`

---
