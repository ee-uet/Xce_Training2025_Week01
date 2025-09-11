# Shell Script: Basic Input/Output and Arithmetic

## Problem
This shell script demonstrates basic input/output operations and arithmetic in a Unix-like environment. It prints a greeting, prompts for a user's name, and calculates the sum of two input numbers.

## Approach
The script uses fundamental shell scripting constructs:
- Prints "Hello, World" as a basic output.
- Prompts for a user's name and displays a personalized greeting.
- Takes two numbers as input, computes their sum, and displays the result.
- Waits for user input to exit.

## How to Run
1. **Prerequisites**: Ensure a Unix-like environment (e.g., Linux, macOS, or WSL on Windows) with a shell (e.g., Bash).
2. **Save the Script**: Save the script as `script.sh`.
3. **Make Executable**: Run the following command to make the script executable:
   ```bash
   chmod +x script.sh
   ```
4. **Execute**: Run the script:
   ```bash
   ./script.sh
   ```
5. **Follow Prompts**: Enter your name, two numbers, and press Enter to exit.

## Examples
### Sample Run
```bash
$ chmod +x script.sh
$ ./script.sh
Hello, World

Enter your name: Alice
Hello, Alice!

Enter two numbers: 5 10
The sum is: 15

Enter to exit.
```

## Syntactical Shorthands Explained
- `#!/bin/sh`: Shebang line specifying the script should be interpreted by the Bourne shell (or a compatible shell like Bash).
- `echo`: Prints text to the console. The standalone `echo` creates a blank line.
- `read -p "Prompt: " VAR`: Reads user input with a prompt (`-p`) and stores it in the variable `VAR`. Used for `NAME`, `n1`, and `n2`.
- `$NAME`: Variable substitution to access the value of `NAME`.
- `$((n1 + n2))`: Arithmetic expansion to compute the sum of `n1` and `n2`. The result is stored in the `sum` variable.
- `$sum`: Variable substitution to display the computed sum.