#!/bin/bash

COUNT=$#
SUM=0
if [ $COUNT -eq 2 ]; then
SUM=$(($1 + $2))
echo "$SUM"
elif [ $COUNT -eq 0 ]; then
echo "No input arguments"
else
echo "Error! Only 2 arguments allowed"
fi