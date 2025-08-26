#!/bin/bash
echo "Chalo, $1 ka table dekhein..."
for i in {1..10}
do
    result=$(($1 * i))
    echo "$1 multiplied by $i is... $result!"
done
