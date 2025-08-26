#!/bin/bash


function factorial()
{
    local n=$1
    if [ $n -le 1 ]; then
        echo 1
        return
    fi
    local prev=$(factorial $((n-1)))
    echo $((n*prev))
}

read -p "Enter a number: " NUM
echo "Factorial of $NUM: $(factorial $NUM)"
