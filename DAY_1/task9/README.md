# Task 0.9 – Struct and Distance Calculation

## Problem
- Define a `struct Point` to represent a 2D point with `x` and `y` coordinates.  
- Read two points from the user.  
- Calculate and print the **Euclidean distance** between the two points using the formula:  

\[
distance = \sqrt{(x2 - x1)^2 + (y2 - y1)^2}
\]

---

## Approach
1. Define a `struct Point` with two integer members: `x` and `y`.  
2. Take input for two points (`p1` and `p2`).  
3. Use the `sqrt()` and `pow()` functions from `<math.h>` to calculate the distance.  
4. Print the result with 2 decimal precision using `%.2f`.  

---

## How to Run
1. Save the code in a file, e.g., `task_9.c`.  
2. Compile the program with math library linked:  
   ```bash
   gcc task_9.c -o task_9 -lm
    ./task_9

## Example Output
Enter coordinates of first point (x y): 2 3
Enter coordinates of second point (x y): 7 9
Euclidean Distance = 7.81

## Known Limitations

Requires including <math.h> and linking with -lm while compiling.

Only works with integer inputs (does not accept floating-point coordinates).