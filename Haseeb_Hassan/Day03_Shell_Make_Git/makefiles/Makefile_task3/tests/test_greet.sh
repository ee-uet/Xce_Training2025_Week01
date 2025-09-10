#!/bin/bash
# Test greet.sh script

OUTPUT=$(bash ../greet.sh)

if [[ "$OUTPUT" == *"Hello"* ]]; then
  echo "test_greet.sh: PASS"
  exit 0
else
  echo "test_greet.sh: FAIL"
  exit 1
fi
