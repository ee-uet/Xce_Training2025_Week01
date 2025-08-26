#!/bin/bash
declare -A capitals
capitals=(["italy"]="rome" ["germany"]="berlin" ["france"]="paris")
 get_capital(){
	read -p "enter country name " name
	if [[ -n "${capitals[$name]}" ]]; then
		echo "capital of $name is ${capitals[$name]}"
	else
		echo "dont know capital"
	fi
}
get_capital
