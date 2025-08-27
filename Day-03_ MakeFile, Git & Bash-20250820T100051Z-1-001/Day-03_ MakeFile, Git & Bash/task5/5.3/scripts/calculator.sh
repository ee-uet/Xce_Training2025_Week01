#!/bin/bash
# Simple calculator script

calculate() {
    local operation=$1
    local num1=$2
    local num2=$3
    
    case $operation in
        "add")
            echo $((num1 + num2))
            ;;
        "subtract")
            echo $((num1 - num2))
            ;;
        "multiply")
            echo $((num1 * num2))
            ;;
        "divide")
            if [ $num2 -ne 0 ]; then
                echo $((num1 / num2))
            else
                echo "Error: Division by zero"
                return 1
            fi
            ;;
        *)
            echo "Error: Unknown operation"
            return 1
            ;;
    esac
}

# Main execution
if [ $# -eq 3 ]; then
    calculate "$1" "$2" "$3"
else
    echo "Usage: $0 <operation> <num1> <num2>"
    echo "Operations: add, subtract, multiply, divide"
    exit 1
fi