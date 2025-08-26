#!/bin/bash
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

fruits_array=("Apple" "Banana" "Orange" "Mango")
fruits(){
   for f in "${fruits_array[@]}"; do
       echo "$f"
   done
  }
fruits
fruits_array+=("Strawberry")
echo "After adding fruit: "
fruits

declare -A capitals
capitals=(
    ["Pakistan"]="Islamabad"
    ["England"]="London"
    ["USA"]="Washington DC"
)

read -p "Enter a country: " country
if [[ -v capitals[$country] ]]; then
    echo "Capital of $country is ${capitals[$country]}"
else
    echo "$country not found!"
fi
