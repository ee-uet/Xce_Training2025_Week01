# Lab 3 Week 1 - Bash Scripting

## Problem

This lab focuses on fundamental bash scripting concepts and practical applications. The tasks cover various programming constructs including:

- Basic arithmetic operations and user input handling
- File processing and text manipulation
- Control structures (loops, conditionals)
- Functions and arrays
- Associative arrays (hash maps)
- File system operations and backup creation
- Interactive programs and games

The lab consists of 12 different bash scripts demonstrating these concepts through practical examples.

## Approach

The lab tasks were implemented using core bash scripting features:

1. **Basic Scripts**: Simple arithmetic and user interaction
2. **File Operations**: Reading, processing, and analyzing text files
3. **Control Structures**: Implementing loops and conditional logic
4. **Data Structures**: Working with indexed and associative arrays
5. **Functions**: Creating reusable code blocks
6. **System Operations**: File backup and directory management

Each script focuses on a specific concept while maintaining simplicity and readability.

## How to Run

### Prerequisites
- Linux/Unix environment with bash shell
- Required files: `sample.txt`, `log.txt` (should be in the same directory)

### Making Scripts Executable
```bash
chmod +x *.sh
```

### Running Individual Scripts

1. **Sum Calculator**
   ```bash
   ./sum.sh 5 10
   ```

2. **File Reader**
   ```bash
   ./readfile.sh
   ```

3. **Multiplication Table**
   ```bash
   ./multiples.sh 7
   ```

4. **Log Analysis**
   ```bash
   ./log_analysis.sh
   ```

5. **Hello Script**
   ```bash
   ./hello.sh
   ```

6. **Number Guessing Game**
   ```bash
   ./guess.sh
   ```

7. **Greeting Script**
   ```bash
   ./greet.sh
   ```

8. **Fruit Array**
   ```bash
   ./fruit.sh
   ```

9. **Factorial Calculator**
   ```bash
   ./factorial.sh
   ```

10. **Even/Odd Checker**
    ```bash
    ./check_even_odd.sh 8
    ```

11. **Capital Finder**
    ```bash
    ./capital.sh
    ```

12. **Directory Backup**
    ```bash
    ./backup.sh /path/to/directory
    ```

## Examples

### Sum Calculator
```bash
$ ./sum.sh 15 25
The sum of 15 and 25 is : 40
```

### Multiplication Table
```bash
$ ./multiples.sh 3
First 10 multiples of 3:
3
6
9
12
15
18
21
24
27
30
```

### Number Guessing Game
```bash
$ ./guess.sh
Guess a number between 1 and 10
Enter your guess: 5
Guess is low
Enter your guess: 8
Guess is high
Enter your guess: 7
 Correct! The number was 7
```

### Even/Odd Checker
```bash
$ ./check_even_odd.sh 4
number is even

$ ./check_even_odd.sh 7
number is odd
```

### Capital Finder
```bash
$ ./capital.sh
enter country name italy
capital of italy is rome
```

### Directory Backup
```bash
$ ./backup.sh /home/user/documents
backup successfull backup_2024-08-23.tar.gz
```

## Known Limitations

1. **Input Validation**: Most scripts lack comprehensive input validation and error handling
2. **Case Sensitivity**: The capital finder script is case-sensitive for country names
3. **File Dependencies**: Some scripts require specific files (`sample.txt`, `log.txt`) to be present
4. **Limited Error Messages**: Basic error reporting without detailed troubleshooting information
5. **Hardcoded Values**: Some scripts have hardcoded values (like the 1-10 range in guessing game)
6. **Array Display**: In `fruit.sh`, the array elements are displayed as a single string rather than individual items
7. **Backup Overwrite**: The backup script may overwrite existing backups with the same date
8. **No Input Sanitization**: Scripts don't sanitize user input for special characters or malicious content

## Sources & AI Usage

- Bash scripting concepts and syntax referenced from standard bash documentation
- No external libraries or frameworks used
- All scripts written using built-in bash commands and features
- No AI tools were used in the development of these scripts