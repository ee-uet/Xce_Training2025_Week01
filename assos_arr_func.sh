#!/bin/bash
declare -A associ_arr

associ_arr["Pakistan"]="Islamabad"
associ_arr["India"]="Delhi"
associ_arr["China"]="Beijing"
associ_arr["Japan"]="Tokyo"

func_assos_arr() {
	if [[ -v associ_arr[$1] ]]; then
		echo "Capital of $1 is ${associ_arr[$1]}"
	else
		echo "I don't know"
	fi
}
func_assos_arr "$1"
