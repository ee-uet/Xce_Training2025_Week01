# Lab 3: Functions and Arrays

## Problem
1. **Functions (Exercise 3.1)**: Create a function that calculates factorial of a number and call it with different numbers
2. **Arrays (Exercise 3.2)**: Create an array of fruits, write a function to print each fruit, add new fruit and call function again
3. **Associative Arrays (Exercise 3.3)**: Create associative array of country-capital pairs with function to lookup capitals and error handling

## Approach

### Factorial Function
1. Define function that takes number as parameter
2. Use for loop to calculate factorial iteratively
3. Return result and call function with different inputs
4. Use local variables to avoid conflicts

### Array Operations
1. Initialize array with fruit names
2. Create function to iterate and print all array elements
3. Demonstrate adding new elements to existing array
4. Show array expansion functionality

### Associative Arrays
1. Define associative array with country-capital pairs
2. Create lookup function that searches for country
3. Implement proper error handling for missing entries
4. Display available options when country not found

## How to Run

### Make Scripts Executable
```bash
chmod +x *.sh
```

### Factorial Function
```bash
./factorial.sh
```

### Array Operations
```bash
./array_fruits.sh
```

### Associative Arrays
```bash
./associative_arrays.sh
```

## Example Output

### Factorial Function
```
Enter number to know its factorial: 5
The factorial of 5 is 120
```

### Array Operations
```
Initial fruits:
List of fruits:
apple
Orange
Mango
Enter a new fruit name: banana

Updated fruits:
List of fruits:
apple
Orange
Mango
banana
```

### Associative Arrays
```
Enter the Country name: Pakistan
Country: Pakistan, Capital: Islamabad

Enter the Country name: France
Your Country is not in the list!
Available countries: Pakistan India China
```

## Design Notes
- Factorial uses iterative approach with local variables
- Array operations demonstrate dynamic array expansion
- Associative arrays use proper bash syntax with declare -A
- Error handling provides helpful feedback

## Key Concepts Demonstrated
- **Function Definition**: `function name() { ... }` syntax
- **Local Variables**: Preventing variable conflicts in functions
- **Array Declaration**: `ARRAY=("item1" "item2")` syntax
- **Array Iteration**: `"${ARRAY[@]}"` for all elements
- **Array Expansion**: `ARRAY+=("new_item")` for adding elements
- **Associative Arrays**: `declare -A` and `["key"]="value"` syntax
- **Key Iteration**: `"${!ARRAY[@]}"` for getting keys
- **Error Handling**: Conditional checks and user feedback

## Assumptions & Edge Cases
- Factorial assumes positive integer input
- Array functions handle empty arrays gracefully
- Associative array handles case-sensitive country names
- All functions include basic input validation

## Known Limitations
- Factorial doesn't validate for negative numbers or non-integers
- Array operations don't check for duplicate entries
- Country lookup is case-sensitive
- No input sanitization for special characters

## Algorithm Details

### Factorial Calculation
```bash
function factorial() {
    local num=$1
    local result=1
    for ((count=1; count<=num; count++))
    do
        result=$((result * count))
    done
    echo $result
}
```

### Array Expansion
```bash
FRUITS+=("$new_fruit")  # Adds element to existing array
```

### Associative Array Lookup
```bash
for country_name in "${!country_pairs[@]}"; do
    if [[ "$country" == "$country_name" ]]; then
        echo "Country: $country, Capital: ${country_pairs[$country]}"
    fi
done
```

## Sources & AI Usage
- Original template code from lab manual
- Googled syntax for bash functions and arrays