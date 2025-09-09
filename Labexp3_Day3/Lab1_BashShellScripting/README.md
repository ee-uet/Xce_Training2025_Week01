## Overview

This repository contains three basic bash scripting exercises that introduce core concepts like script execution, variables, user input, and command-line arguments.

## Exercises

### Exercise 1.1: Hello World (`hello.sh`)
- **Objective**: Create your first bash script
- **Concepts**: Shebang, echo command, script execution
- **Skills**: Basic script structure and execution permissions

### Exercise 1.2: Variables and User Input (`var_usr_in.sh`)
- **Objective**: Handle user input and variables
- **Concepts**: Variables, `read` command, string interpolation
- **Skills**: Interactive scripts and data storage

### Exercise 1.3: Command-line Arguments (`cmd_ln_arg.sh`)
- **Objective**: Process command-line parameters
- **Concepts**: Positional parameters (`$1`, `$2`), arithmetic operations
- **Skills**: Script parameters and mathematical calculations

## Getting Started

### Prerequisites
- Unix/Linux environment or WSL on Windows
- Bash shell (usually pre-installed)
- Basic terminal knowledge

### Making Scripts Executable
Before running any script, make it executable:
```bash
chmod +x script_name.sh
```

### Running the Scripts

**Exercise 1.1:**
```bash
./hello.sh
```

**Exercise 1.2:**
```bash
./var_usr_in.sh
# Follow the prompt to enter your name
```

**Exercise 1.3:**
```bash
./cmd_ln_arg.sh 5 10
# Output: Sum is 15
```

## Learning Outcomes

After completing these exercises, you will understand:

- **Script Structure**: How to create and structure bash scripts
- **Execution Permissions**: Making scripts executable with `chmod`
- **Variables**: Storing and using data in scripts
- **User Interaction**: Getting input from users with `read`
- **Command-line Arguments**: Processing parameters passed to scripts
- **Arithmetic Operations**: Performing calculations in bash
- **Output**: Displaying results with `echo`

## Key Concepts

### Shebang (`#!/bin/bash`)
- Tells the system which interpreter to use
- Must be the first line of the script

### Variables
- Store data: `NAME="John"`
- Access data: `$NAME` or `${NAME}`

### User Input
- `read` command captures user input
- `-p` flag provides a prompt

### Command-line Arguments
- `$1`, `$2`, etc. represent positional parameters
- `$0` is the script name itself

### Arithmetic Operations
- `$(($1 + $2))` performs arithmetic expansion
- Alternative: `$((expression))`

## File Structure
```
├── hello.sh           # Basic hello world script
├── var_usr_in.sh      # User input and variables
├── cmd_ln_arg.sh      # Command-line arguments
└── README.md          # This file
```

## Tips for Success

1. **Always test your scripts** with different inputs
2. **Check permissions** if a script won't run
3. **Use meaningful variable names** for clarity
4. **Add comments** to explain complex logic
5. **Validate input** in real-world scripts

## Common Issues

- **Permission denied**: Run `chmod +x script.sh`
- **Command not found**: Use `./script.sh` not just `script.sh`
- **No such file**: Ensure you're in the correct directory

## Next Steps

After mastering these basics, explore:
- Conditional statements (`if`, `else`)
- Loops (`for`, `while`)
- Functions
- Error handling
- Advanced parameter processing

---
