#!/bin/bash
for ((i=1;i<11;i++)) do
mul=$(($1 * i))
echo "$1*$i=$mul"
done