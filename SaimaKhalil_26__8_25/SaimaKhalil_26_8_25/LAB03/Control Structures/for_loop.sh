#1. Create a script that prints the first 10 multiples of a number (provided as an argument)
#2. Use a for loop to calculate and print the multiples
#3. Test with different numbers
#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "Provide exactly a number."
    exit 1
fi
# Read the command-line argument
number=$1
# Loop to calculate and print the first 10 multiples
for ((i=1;i<=10;i++)) 
do    
    multiple=$((number * i))
    echo "Multiple $i of $number is: $multiple"
done        

 