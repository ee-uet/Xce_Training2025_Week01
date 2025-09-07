## Overview

This lab contains three exercises that explore functions, regular arrays, and associative arrays in bash scripting, including recursion and data structure manipulation.

## Exercises

### Exercise 3.1: Functions (`fact_cal_func.sh`)
- **Objective**: Calculate factorial using recursive functions
- **Concepts**: Function definition, recursion, local variables
- **Skills**: Mathematical computations and function design

### Exercise 3.2: Arrays (`array_func.sh`)
- **Objective**: Work with indexed arrays
- **Concepts**: Array declaration, iteration, array length
- **Skills**: Data storage and retrieval from collections

### Exercise 3.3: Associative Arrays (`assos_arr_func.sh`)
- **Objective**: Key-value pair storage and lookup
- **Concepts**: Associative arrays, parameter validation, error handling
- **Skills**: Dictionary-like data structures and user interaction

## Getting Started

### Making Scripts Executable
```bash
chmod +x *.sh
```

### Running the Scripts

**Exercise 3.1 - Factorial Calculator:**
```bash
./fact_cal_func.sh
# Output: Displays factorial of numbers 0-4
```

**Exercise 3.2 - Fruit Array:**
```bash
./array_func.sh
# Output: Lists all fruits with index numbers
```

**Exercise 3.3 - Country-Capital Lookup:**
```bash
./assos_arr_func.sh Pakistan
# Output: Capital of Pakistan is Islamabad

./assos_arr_func.sh Germany
# Output: I don't know
```

## Learning Outcomes

After completing these exercises, you will understand:

- **Function Creation**: Defining and calling custom functions
- **Recursion**: Functions that call themselves
- **Array Operations**: Creating, accessing, and iterating through arrays
- **Associative Arrays**: Key-value pair data structures
- **Parameter Handling**: Processing function and script arguments
- **Error Handling**: Validating input and handling edge cases

## Key Concepts

### Functions
- Function definition: `function_name() { ... }`
- Local variables: `local variable_name`
- Return values through `echo` or `return`
- Recursive function calls

### Arrays
- Declaration: `array_name=("item1" "item2" "item3")`
- Access: `${array_name[index]}`
- Length: `${#array_name[@]}`
- Iteration with for loops

### Associative Arrays
- Declaration: `declare -A array_name`
- Assignment: `array_name["key"]="value"`
- Key existence check: `[[ -v array_name[key] ]]`
- Access: `${array_name[key]}`

## File Structure
```
├── fact_cal_func.sh      # Recursive factorial function
├── array_func.sh         # Array operations and functions
├── assos_arr_func.sh     # Associative array lookup
└── README.md             # This file
```

## Key Features

### Factorial Function
- Handles base cases (0 and 1)
- Uses recursion for calculation
- Demonstrates local variable usage

### Array Function
- Displays indexed list of items
- Shows array length calculation
- Demonstrates array iteration

### Associative Array Function
- Country-capital lookup system
- Input validation and error handling
- Command-line parameter processing

## Tips

1. **Test edge cases** - try factorial of 0, empty arrays, unknown keys
2. **Understand scope** - local vs global variables in functions
3. **Debug recursion** - add echo statements to trace function calls
4. **Experiment** - modify arrays and test different scenarios

## Common Issues

- **Array syntax**: Remember `[@]` for all elements, `[index]` for specific
- **Associative arrays**: Must use `declare -A` before assignment
- **Function parameters**: Use `$1`, `$2`, etc. within functions
- **Recursion limits**: Very large numbers may cause stack overflow

---
