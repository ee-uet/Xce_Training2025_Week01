# C Program: Euclidean Distance Using Structures

## Overview
This program demonstrates:
- Defining and using a `struct` in C
- Taking input for two points in 2D space
- Calculating the **Euclidean distance** between the two points using the formula:

\[
distance = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
\]

---

## Code Structure
- `struct Point`
  - Holds `x` and `y` coordinates of a point.
- `task09_struct_distance()`
  - Prompts the user to enter coordinates of two points.
  - Uses the **Euclidean distance formula** with `sqrt()` from `<math.h>`.
  - Prints the computed distance.
- `main()`
  - Calls `task09_struct_distance()`.

---

## How the Code Works
1. A `struct Point` is defined to store `x` and `y` coordinates.  
2. The program asks the user for two points.  
3. The distance is calculated using the formula:  
   \[
   \sqrt{(p2.x - p1.x)^2 + (p2.y - p1.y)^2}
   \]  
4. The result is displayed with **two decimal places**.  

---

## Example Run

### Input
Enter coordinates of first point (x y): 3 4
Enter coordinates of second point (x y): 7 1

---

### Output
Euclidean Distance = 5.00

---

## How to Compile and Run

### Using GCC
```sh
gcc task9.c -o task9 -lm
./task9
