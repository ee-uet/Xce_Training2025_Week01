#!/bin/bash
fruits=("apple" "orange" "mango")
#echo "${#fruits[@]}"
function print_fruits() {
	for fruit in "${fruits[@]}";
	do
		echo -n "$fruit "
	done
echo ""
}

print_fruits
echo "Adding new fruit"
fruits+=("banana")
print_fruits
