#!/bin/bash
output=$(./script1.sh)
if [ "$output" = "Hello from VS Code!" ]; then
   echo "Test passed!"
   exit 0
else 
 echo "Test failed!"
 exit 1
fi