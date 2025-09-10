# Task 8: Enumerations

## Problem
- Define an enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
- Write a program that takes a number (1–7) as input and prints the corresponding weekday

## Approach
1. Define enumeration with weekday constants
2. Get user input (1-7)
3. Convert input to enum value by subtracting 1
4. Use switch-case to map enum values to weekday names

## How to Run

### Compilation
```bash
gcc -o enum_weekday enum_weekday.c
```

### Execution
```bash
./enum_weekday
```

## Example Output
```
Enter a number frm 1 to 7: 3
Wednesday
```

## Design Notes
- Enum values start from 0 (MON=0, TUE=1, etc.)
- User input 1-7 mapped to enum values 0-6
- Switch-case provides clean mapping from enum to string

## Enum Value Mapping
- 1 → MON (Monday)
- 2 → TUE (Tuesday)  
- 3 → WED (Wednesday)
- 4 → THU (Thursday)
- 5 → FRI (Friday)
- 6 → SAT (Saturday)
- 7 → SUN (Sunday)

## Assumptions & Edge Cases
- Assumes integer input from user
- Default case handles invalid input (numbers outside 1-7)
- Uses explicit type casting to enum type

## Known Limitations
- No input validation for non-integer input
- Basic error handling for out-of-range values

## Sources & AI Usage
- Original template code from lab manual
- Standard enum usage pattern from Slides shared in class
- No AI assistance for enumeration logic