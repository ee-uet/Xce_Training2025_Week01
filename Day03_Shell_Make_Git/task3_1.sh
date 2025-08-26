#!/bin/bash

factorial() {
	local n=$1
	if [ $n -eq 1 ]; then
		echo 1
	else
		local prev=$(factorial $(( n - 1 )))
		echo $(( n * prev ))
	fi
}
echo "factorial of 5"
factorial 5
echo "factorial of 3"
factorial 3
