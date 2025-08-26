#!/bin/bash
fruits=("aam" "kelay" "seb")
print_fruits() {
    echo "Dekho, hamare paas ye fruits hain:"
    for fruit in "${fruits[@]}"
    do
        echo "$fruit"
    done
}
print_fruits
fruits+=("anaar")

echo "Ek aur fruit daala hai!"
print_fruits
