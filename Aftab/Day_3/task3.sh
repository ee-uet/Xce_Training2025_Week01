#!/bin/bash
#factorial () {
#    if [ $1 -le 1 ]; then
#        echo 1
#    else
#        local prev=$(factorial $(($1 -1)))
#        echo $(($1 * $prev))
#fi 
#}

#task3.2
#fruits=("apple" "banana" "cherry")
#print_fruits() {
#  for fruit in "${fruits[@]}"; do
#    echo "$fruit"
#  done
#}
#fruits+=("orange")
#print_fruits

#task3.3
declare -A capitals
capitals=(
  ["USA"]="Washington D.C."
  ["France"]="Paris"
  ["Japan"]="Tokyo"
)
get_capital() {
  read -p "Enter a country: " country
  if [[ -n "${capitals[$country]}" ]]; then
    echo "The capital of $country is ${capitals[$country]}"
  else
    echo "Sorry, capital for $country not found."
  fi
}

get_capital
