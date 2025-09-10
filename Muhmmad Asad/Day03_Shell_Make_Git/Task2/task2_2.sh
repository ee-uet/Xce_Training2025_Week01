#!/bin/bash
read -p "enter the multiple: " VALUE
for ((i=1; i<=10; i++)) 
do
echo "$VALUE x $i = $((VALUE*i))"
done

