function factorial(){  
    if [ "$1" -lt 0 ]; then
        echo "Factorial is not defined for negative numbers."
        return 1
    elif [ "$1" -eq 0 ]; then
        echo 1
    else
        local result=1
        for (( i=1; i<=$1; i++ )); do
            result=$((result * i))
        done
        echo $result
    fi
 } 
# Check if an argument is provided 
if [ "$#" -ne 1 ]; then
    echo "Provide exactly one number as an argument."
    exit 1
fi
# Read the command-line argument
number=$1
# Calculate and print the factorial
factorial_result=$(factorial $number)
if [ $? -eq 0 ]; then #$?  Bash me last executed command ka exit status.(yni exit stats 1 to nh hua)
    echo "The factorial of $number is: $factorial_result"   
 
