#!/bin/bash
declare -A  capitals
capitals[Pakistan]="islamabad"
capitals[India]="Delhi"
capitals[Bangladesh]="Dhaka"
read -p "enter the country" country
if [[ -v capitals[$country] ]]; then
 echo "the capital of $country is  ${capitals[$country]}"
else
   echo "country does not exist in array"
fi
