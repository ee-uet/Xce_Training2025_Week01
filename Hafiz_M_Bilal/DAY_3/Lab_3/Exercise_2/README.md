# Fruits Array Script

## Problem
Write a Bash script that demonstrates:
- Storing values in an array.
- Printing array elements using a function.
- Adding new elements dynamically.

## Approach
1. Declare an array `Fruits` with some initial values.
2. Define a function `fruit_print()` that:
   - Iterates over the array with `for fruit in "${Fruits[@]}"`.
   - Prints each fruit.
3. Call the function to display initial fruits.
4. Append a new fruit (`pineapple`) to the array.
5. Call the function again to show the updated list.

## How to Run
1. Save the script as `E3_2.sh`.
2. Make it executable:
   ```bash
   chmod +x E3_2.sh
   ./E3_2.sh

## Example Run
Fruits in array: 
apple
banana
orange
-----------------------
Fruits in array: 
apple
banana
orange
pineapple

## Known Limitations

Fruits are hardcoded; user input is not yet supported.

Array operations depend on Bash (not POSIX sh).

No error handling (e.g., empty array).
