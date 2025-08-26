#!/bin/bash
factorial() {
	if (( $1 == 0 | $1 == 1)); then
		echo 1
	else
		local prev=$(factorial $(($1 - 1)))
		echo $(( $1 * prev))
	fi
}
for (( i=0; i<5; i++))
do
	result=$(factorial i)
	echo "Factorial of $i is $result"
done

