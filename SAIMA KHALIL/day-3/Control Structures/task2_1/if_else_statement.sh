
#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "Provide exactly one number as an argument."
    exit 1
fi      
number=$1
# Check if the number is even or odd        
if (( number % 2 == 0 )); then
    echo "$number is even."
else
    echo "$number is odd."
fi
