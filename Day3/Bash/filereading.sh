#!/bin/bash

i=1
while read line; do
	echo "$i. $line"
	((i++))
done < file.txt
