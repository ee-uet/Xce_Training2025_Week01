# Lab 1: Basic Shell Scripting

## Problem
1. **Hello World (Exercise 1.1)**: Create a basic script with shebang line that prints "Hello, World!"
2. **Variables and User Input (Exercise 1.2)**: Script that asks for user's name, stores it in a variable, and prints greeting
3. **Command-line Arguments (Exercise 1.3)**: Script that accepts two numbers as arguments and calculates their sum

## Approach

### Hello World
1. Add shebang line for bash interpreter
2. Use echo command to print message
3. Make script executable with chmod

### User Input
1. Use read command to get user input
2. Store input in variable
3. Use variable in echo statement for personalized greeting

### Command-line Arguments
1. Access command-line arguments using $1, $2
2. Validate correct number of arguments
3. Perform arithmetic using $(()) syntax

## How to Run

### Make Scripts Executable
```bash
chmod +x *.sh
```

### Hello World
```bash
./hello.sh
```

### User Input
```bash
./user_input.sh
```

### Command Arguments
```bash
./command_args.sh 5 10
```

## Example Output

### Hello World
```
Hello, World!
```

### User Input
```
Hello User, Script Initialized!
Enter your name: John
HELLO, John, Welcome to the Script
```

### Command Arguments
```
The sum of 5 and 10 is: 15
```

## Design Notes
- All scripts include proper shebang lines
- Command arguments script includes input validation
- User input script provides clear prompts

## Key Concepts Demonstrated
- **Shebang Line**: `#!/bin/bash` for script interpretation
- **Variables**: Storing and using data
- **User Input**: `read` command for interactive input
- **Command-line Arguments**: Accessing `$1`, `$2`, etc.
- **Arithmetic**: `$(())` for mathematical operations
- **Input Validation**: Checking argument count


## Assumptions & Edge Cases
- Assumes numeric input for command arguments
- Basic input validation for argument count
- No validation for non-numeric arguments

## Known Limitations
- Command arguments script doesn't validate if inputs are actually numbers
- No error handling for invalid arithmetic operations
- Basic user input handling without advanced validation

## Sources & AI Usage
- Original template code from lab manual
- Standard bash scripting techniques