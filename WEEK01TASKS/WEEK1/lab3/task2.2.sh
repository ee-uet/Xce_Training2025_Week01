#!/bin/bash
num=$1
for ((i=1;i<11;i++ ))
  do echo "$num*$i = $(( num * i ))"
 done  
