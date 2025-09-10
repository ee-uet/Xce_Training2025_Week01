#!/bin/bash

# Exercise 1
# function to find the factorial of a number
factorial(){
   n=$1
   fact=1
   for(( i=1; i<=n; i++))
     do
	   fact=$(( fact * i))
	 done
	 echo $fact
}
echo "Factorial of 5 is $(factorial 5)"
echo "Factorial of 7 is $(factorial 7)"

# Exercise 2
# array of fruits
fruits_array=("Apple" "Banana" "Orange" "Mango")

# prints the fruits in the array
fruits(){
   for f in "${fruits_array[@]}"; do
       echo "$f"
   done
  }
fruits

# fruit is added in the array
fruits_array+=("Strawberry")

# prints the updated array after adding the fruit
echo "After adding fruit: "
fruits

# Exercise 3
# an associative array of country-capital pairs
declare -A capitals
capitals=(
    ["Pakistan"]="Islamabad"
    ["England"]="London"
    ["USA"]="Washington DC"
)

# asks the user for a country and returns its capital

read -p "Enter a country: " country
if [[ -v capitals[$country] ]]; then
    echo "Capital of $country is ${capitals[$country]}"
else
    echo "$country not found!"
fi
