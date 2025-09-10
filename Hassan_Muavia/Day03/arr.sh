#!/bin/bash
declare -A arr
arr["pakistan"]="islamabad"
arr["srilanka"]="colombo"
arr["afghanistan"]="kabul"
arr["russia"]="moscow"
capital(){
	read -p "Enter a country: " country
	if [[ -v arr[$country] ]]; then
		echo "${arr[$country]}"
	else
		echo "i don't know the capital of this country. sorry!"
	fi
}
capital
