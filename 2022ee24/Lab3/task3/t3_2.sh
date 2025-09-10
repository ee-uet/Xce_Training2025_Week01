#!/bin/bash

FRUITS=("orange" "banana" "apple")

function print()
{
    LEN=${#FRUITS[@]}
    for i in "${FRUITS[@]}"; do
        echo "$i"
    done
    echo ""
    echo "Method2"
    echo ""
    for ((j=0;j<$LEN;j++))
    do
        echo "${FRUITS[$j]}"
    done
    echo ""
}
print
FRUITS+=("grapes")
print