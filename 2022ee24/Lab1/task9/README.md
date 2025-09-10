
---

# C Program: Distance Between Two Points (Task 9)

## Problem

This program calculates the **Euclidean distance** between two points in a 2D plane.
The user enters coordinates of two points, and the program computes the distance using the formula:

$$
d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
$$

## Approach

1. Define a `struct Point` with members `x` and `y` for coordinates.
2. Prompt the user to input two points in the format `x,y`.
3. Compute the differences:

   * $\Delta x = x_2 - x_1$
   * $\Delta y = y_2 - y_1$
4. Use the `sqrt()` function from `<math.h>` to calculate the distance.
5. Print the result as a floating-point number.

### Key Concepts Used

* **Structures (`struct`)**: To group related data (coordinates).
* **Math Library**: `sqrt()` for square root calculation.
* **Formatted Input**: `scanf("%d,%d", &x, &y)` to parse coordinates with a comma.

## How to Run

1. Copy the code into a file named `task9.c`.
2. Compile with the math library linked:

   ```bash
   gcc -o task9 task9.c -lm
   ```

   (The `-lm` flag links the math library.)
3. Run the program:

   ```bash
   ./task9
   ```

## Examples

### Example 1: Input (0,0) and (3,4)

```
Enter P1(x,y) = 0,0
Enter P2(x,y) = 3,4
dist = 5.000000
```

### Example 2: Input (1,2) and (4,6)

```
Enter P1(x,y) = 1,2
Enter P2(x,y) = 4,6
dist = 5.000000
```

### Example 3: Input (-1,-1) and (2,3)

```
Enter P1(x,y) = -1,-1
Enter P2(x,y) = 2,3
dist = 5.000000
```

## Known Limitations

* Input format must be `x,y` with a comma (e.g., `3,4`).
* No validation for non-integer or invalid input.
* Output is always shown with 6 decimal places (default `%f` format).

## What I Verified

* **Correctness**: Formula gives accurate results.
* **Edge Cases**: Distance between same points `(x,y)` = `(x,y)` returns `0`.
* **Precision**: Output is in floating-point, so it handles non-integer distances correctly.

## Sources & AI Usage

The program was implemented manually. AI assistance was used to write this `README.md`

---
