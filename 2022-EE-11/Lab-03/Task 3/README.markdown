# Bash Script: Factorial, Array Operations, and Associative Array Lookup

## Problem
This Bash script performs three tasks: calculates factorials for given numbers, manages a fruit array (display and append), and implements a country-capital lookup using an associative array.

## Approach
The script is organized into three main components:
- **Factorial Function**: Computes the factorial of a number using a loop.
- **Fruit Array Operations**: Displays a list of fruits, counts them, and appends a new fruit.
- **Country-Capital Lookup**: Uses an associative array to store country-capital pairs and retrieves capitals with case-insensitive matching.

## How to Run
1. **Prerequisites**: Requires a Unix-like environment (e.g., Linux, macOS, WSL) with Bash.
2. **Save the Script**: Save as `script.sh`.
3. **Make Executable**: Run:
   ```bash
   chmod +x script.sh
   ```
4. **Execute**: Run the script:
   ```bash
   ./script.sh
   ```
5. **Output**: The script automatically runs factorial calculations, fruit array operations, and country-capital lookups. No user input is required.

## Examples
### Sample Run
```bash
$ chmod +x script.sh
$ ./script.sh
Factorial of 5 is: 120
Factorial of 0 is: 1
Factorial of 7 is: 5040
Factorial of 10 is: 3628800

Fruits in the array:
1. apple
2. banana
3. orange
4. grape
5. strawberry
Total fruits: 5

Added 'mango' to the array:
Fruits in the array:
1. apple
2. banana
3. orange
4. grape
5. strawberry
6. mango
Total fruits: 6

Testing country-capital lookup:
The capital of USA is: Washington D.C.
The capital of JAPAN is: Tokyo
Error: Country 'SPAIN' not found in database
Available countries: USA UK France Germany Japan Canada Australia India
```

## Syntactical Shorthands Explained
- `#!/bin/bash`: Shebang specifying Bash as the interpreter.
- `factorial() { ... }`: Defines a function named `factorial`.
- `local num=$1`: Declares a local variable `num` assigned the first function argument (`$1`).
- `for ((i=1; i<=num; i++))`: C-style for loop iterating from 1 to `num`.
- `$((result * i))`: Arithmetic expansion for multiplication in the factorial calculation.
- `echo`: Outputs text or variables; standalone `echo` adds a blank line.
- `fruits=("apple" ...)`: Declares an indexed array of fruits.
- `for i in "${!fruits[@]}"`: Iterates over array indices (`${!fruits[@]}` expands to all indices).
- `${fruits[i]}`: Accesses the element at index `i`.
- `${#fruits[@]}`: Returns the number of elements in the array.
- `fruits+=("mango")`: Appends "mango" to the array.
- `declare -A countries`: Declares an associative array for country-capital pairs.
- `countries=(["key"]="value" ...)`: Initializes the associative array with key-value pairs.
- `country=$(echo "$country" | tr '[:lower:]' '[:upper:]')`: Converts input to uppercase using `tr` for case-insensitive matching.
- `[[ -n "${countries[$country]}" ]]`: Tests if the country key exists and has a non-empty value (`-n` checks for non-empty).
- `${countries[$country]}`: Retrieves the value (capital) for the country key.
- `${!countries[@]}`: Lists all keys in the associative array.
- `if ...; then ...; else ...; fi`: Conditional structure for lookup logic.