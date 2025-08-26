#!/bin/bash
num=$1
if [ $((num%2)) -eq 0 ]
then
        echo "Number is even"
else
        echo "Number is odd"
fi

