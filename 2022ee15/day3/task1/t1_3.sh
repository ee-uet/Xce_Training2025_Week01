#!/bin/bash
NUM_1=$1   # first argument
NUM_2=$2   # second argument

# $(( )) performs integer arithmetic
add=$((NUM_1 + NUM_2))
echo "Sum is ${add}"

