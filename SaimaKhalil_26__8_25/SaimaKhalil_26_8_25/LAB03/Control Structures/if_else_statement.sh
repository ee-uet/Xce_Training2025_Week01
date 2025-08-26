#1. Write a script that checks if a number (provided as an argument) is even or odd
#2. Use an if-else statement to print the result
#3. Test with various numbers
#!/bin/bash
# Check if an argument is provided
if [ "$#" -ne 1 ]; then
    echo "Provide exactly one number as an argument."
    exit 1
fi      
# Read the command-line argument
number=$1
# Check if the number is even or odd        
if (( number % 2 == 0 )); then
    echo "$number is even."
else
    echo "$number is odd."
fi
