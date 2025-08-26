#!/bin/bash

num=$1

echo "First 10 multiples of $num:"

for((i=1;i<11;i++))
do
    echo "$((num * i))"
done
