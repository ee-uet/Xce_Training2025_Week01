#!/bin/bash
num=$1
echo "multiples are "
for ((i=1; i<=10; i++))
do echo "$((num * i))"
done
