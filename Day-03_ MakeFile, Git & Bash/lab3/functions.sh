#!/bin/bash
fictorial(){
    if [ $1 -le 1 ];then
      echo 1
    else
      prod=$(fictorial $(($1 - 1)))
      echo $(( $1 * $prod))
    fi
}
result=$(fictorial $1)
echo "fictorial of $1 is ${result}"