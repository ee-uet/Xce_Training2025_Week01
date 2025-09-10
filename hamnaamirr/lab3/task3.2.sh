#!/bin/bash
fruits=("apple" "orange" "banana" "mango")
len=${#fruits[@]}
print () {
  for (( i=0;i<len;i++ )); do
    echo ${fruits[$i]}
  done
}
print

