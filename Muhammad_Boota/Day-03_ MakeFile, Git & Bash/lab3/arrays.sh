#!/bin/bash
fruits=("apple" "banana" "orange")

print_fruits(){
    for fruit in "$@"
    do
    {
        echo "$fruit"
    }
    done
}
print_fruits "${fruits[@]}"
fruits+=("graphs")
echo "after adding new fruit"
print_fruits "${fruits[@]}"
