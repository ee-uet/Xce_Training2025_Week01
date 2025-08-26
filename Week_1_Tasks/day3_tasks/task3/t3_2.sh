#!/bin/bash

fruits=("Apple" "Banana" "Orange")

function arr()
{
 for fruit in "${fruits[@]}";
 do
 echo "${fruit}"
 done   
}

arr

fruits+=("Mango")
echo "Add one more fruit in array"
echo "${fruits[@]}"


