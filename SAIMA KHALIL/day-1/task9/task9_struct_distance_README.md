## Struct Point Distance Calculator

This program demonstrates the use of `struct`. It calculates the Euclidean distance between two points entered by the user.

---

### Code Explanation

#### Struct Declaration
```c
struct Point {
    int x;
    int y;
};
```
- defines a Point with x and y coordinates.
Logic
- declare two variables of type struct Point: p1 and p2.
- prompt the user to enter x and y coordinates for both points.

- calculate distance using the formula:
distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)

- prints the distance with 5 decimal places.

---
#### Example Run

Enter coordinates of 1st point x and y : 1 2
Enter coordinates of 2nd point x and y : 4 6
Distance between points (1, 2) and (4, 6) is: 5.00000

---

#### Run
```bash
gcc task9_struct_distance.c -o task9_struct_distance -lm
./task9_struct_distance
```
