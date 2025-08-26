#!/bin/bash
EXE=./bitops
PASS=0
FAIL=0
TOTAL=0

tests=(
    "5 countbit "
    "16 pow_2 "
    "18 pow_2 "
    "7 reverse"
    "8 set 3"
    "15 clear 2"
    "10  toggle 1" 
)

echo "running_test"

for t in "${tests[@]}"; do
    ((total++))
    inputs=($t)
    output=$($EXE <<EOF
${INPUTS[@]})
EOF
    )
    echo "total test: $TOTAL:"
    echo "Input: $t"
    echo "Output"
    echo "$output"
done
echo "total tests run: $total"


