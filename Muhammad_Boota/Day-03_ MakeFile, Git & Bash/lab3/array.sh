#!/bin/bash
declare -A capital
capital["Pakistan"]="Islamabad"
capital["India"]="Dehli"
capital["Amercia"]="Washington, D.C"

get_capital(){
    read -p "Please enter country name:" country
    if [[ -n"${capital[$country]}" ]];then
        echo "capital is ${capital[$country]}"
    else 
        echo "No capital is found in array"
    fi
}
get_capital