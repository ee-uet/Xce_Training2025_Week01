#!/bin/bash
if (( $1 % 2 != 0 )); then
	echo "The number is odd"
else
	echo "The number is even"
fi
