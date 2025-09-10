./#!/bin/bash
num=$1
c=1
factorial() {
   for (( i=0;i<num;i++ )); do
       c=$((c * ( num - i ) ))
      done
}
factorial
      echo "c =$c" 


