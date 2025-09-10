#!/bin/bash
# -p prompts and stores input
read -p "Enter Number: " NUM

# for loop runs 1 to 10
for ((i=1; i<=10; i++))
do
    multiple=$((NUM * i))   # arithmetic expansion
    echo "${multiple}"
done

