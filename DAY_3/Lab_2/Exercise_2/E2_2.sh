#!/bin/bash
num=$1
echo "First 10 multiple of $num is"

for((i=1;i<11;i++))
do
multi=$((num*i))
echo "$num * $i = $multi"
done