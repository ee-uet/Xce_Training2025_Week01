#!/bin/bash
output=$(./script1.sh)
if [[ "$output" == *"Hello from script1!"* ]]; then
  echo "Test for script1 passed!"
  exit 0
else
  echo "Test for script1 failed!"
  exit 1
fi