#!/bin/bash
ans=1
read -p "Enter Number: " F
function factorial()
{
    for (( i=1;i<=$F;i++ ))
    do
        ans=$((ans*i))
    done
    echo "Factorial is: ${ans}"
}
factorial