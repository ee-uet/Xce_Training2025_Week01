#Create a script that accepts two numbers as command-line arguments
#Calculate and print the sum of these numbers
#Run the script with different number pairs
#!/bin/bash
# Check if two arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Provide exactly two numbers as arguments." #bash no.of arg=$# , -ne=not equal
    exit 1 #stop hjti script execution
fi
# Read the command-line arguments
num1=$1 
num2=$2
# Calculate the sum
sum=$((num1 + num2))
# Print the result
echo "The sum of $num1 and $num2 is: $sum" 