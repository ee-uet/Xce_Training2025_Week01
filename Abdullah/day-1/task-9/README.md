# Task 9: Structures (Intro)

## Problem
- Define a struct Point { int x; int y; };
- Write a program that takes two points and calculates the Euclidean distance between them

## Approach
1. Define Point structure with x,y coordinates
2. Get coordinates for two points from user
3. Apply Euclidean distance formula: √[(x₂-x₁)² + (y₂-y₁)²]
4. Use math.h functions: sqrt() and pow()

## How to Run

### Compilation
```bash
gcc -o struct_distance struct_distance.c -lm
```
Note: `-lm` flag is required to link math library

### Execution
```bash
./struct_distance
```

## Example Output
```
Enter coordinates of p1(x,y): 1 2
Enter coordinates of p2(x,y): 4 6
Eucledian Distance : 5.000
```

## Design Notes
- Uses struct to encapsulate point coordinates
- Math library functions used for accurate calculation
- Result displayed with 3 decimal places

## Mathematical Formula
Euclidean Distance = √[(x₂-x₁)² + (y₂-y₁)²]

For points (1,2) and (4,6):
- Distance = √[(4-1)² + (6-2)²] = √[9 + 16] = √25 = 5.000

## Assumptions & Edge Cases
- Assumes integer coordinates input
- Uses double precision for distance calculation
- Handles any valid integer coordinate values

## Known Limitations
- Input coordinates limited to integers
- Typo in output: "Eucledian" instead of "Euclidean"
- No input validation for coordinate values

## Sources & AI Usage
- Original template code from lab manual
- Standard Euclidean distance formula
- Math library functions: sqrt(), pow()
- No AI assistance for distance calculation logic