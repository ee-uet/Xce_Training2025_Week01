## Overview

This lab contains three exercises that demonstrate fundamental control structures in bash scripting: if-else statements, for loops, and while loops.

## Exercises

### Exercise 2.1: If-Else Statement (`ev_od.sh`)
- **Objective**: Check if a number is even or odd
- **Concepts**: Conditional statements, arithmetic operations, modulo operator
- **Skills**: Decision making in scripts

### Exercise 2.2: For Loop (`fr_lop.sh`)
- **Objective**: Generate multiplication table
- **Concepts**: For loops, arithmetic operations, command-line arguments
- **Skills**: Iteration and repetitive tasks

### Exercise 2.3: While Loop (`while_gs_gm.sh`)
- **Objective**: Number guessing game
- **Concepts**: While loops, random numbers, user interaction
- **Skills**: Interactive programs and game logic

## Getting Started

### Making Scripts Executable
```bash
chmod +x *.sh
```

### Running the Scripts

**Exercise 2.1 - Even/Odd Checker:**
```bash
./ev_od.sh 7
# Output: The number is odd

./ev_od.sh 8
# Output: The number is even
```

**Exercise 2.2 - Multiplication Table:**
```bash
./fr_lop.sh 5
# Output: Displays 5 times table (1x5=5, 2x5=10, etc.)
```

**Exercise 2.3 - Guessing Game:**
```bash
./while_gs_gm.sh
# Follow prompts to guess the number between 1-10
```

## Learning Outcomes

After completing these exercises, you will understand:

- **Conditional Logic**: Using if-else for decision making
- **Loop Structures**: For and while loops for repetition
- **Arithmetic Operations**: Mathematical calculations in bash
- **Random Numbers**: Generating random values
- **Interactive Scripts**: Creating user-engaging programs
- **Game Logic**: Implementing simple game mechanics

## Key Concepts

### If-Else Statements
- `if (( condition )); then ... else ... fi`
- Arithmetic comparisons with `(( ))`
- Modulo operator `%` for remainder

### For Loops
- C-style syntax: `for ((i=1; i<=10; i++))`
- Variable increment and conditions
- Loop body execution

### While Loops
- `while (( condition )); do ... done`
- Continuous execution until condition is false
- Interactive input within loops

### Random Numbers
- `RANDOM` variable generates random integers
- Range control with modulo: `(RANDOM % 10) + 1`

## File Structure
```
├── ev_od.sh           # Even/odd checker
├── fr_lop.sh          # Multiplication table
├── while_gs_gm.sh     # Number guessing game
└── README.md          # This file
```

## Tips

1. **Test edge cases** - try different numbers and inputs
2. **Understand operators** - `%` for modulo, `*` for multiplication
3. **Practice debugging** - add echo statements to see variable values
4. **Experiment** - modify the scripts to learn more

## Common Issues

- **Syntax errors**: Check spacing around `(( ))` and `[[ ]]`
- **Missing arguments**: Scripts may need command-line parameters
- **Infinite loops**: Ensure while loop conditions can become false

---
