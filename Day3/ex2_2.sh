#!/bin/bash


count=1
while [ $count -le 10 ]
do
    echo "$(($1 * $count))"
    ((count++))
done