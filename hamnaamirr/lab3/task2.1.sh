#!/bin/bash
age=$1
if (( $age % 2 == 0 )); then
  echo "even"
else
   echo "odd"
fi
