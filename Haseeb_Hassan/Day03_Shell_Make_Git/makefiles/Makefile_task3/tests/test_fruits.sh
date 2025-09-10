#!/bin/bash
# Test fruits.sh script

OUTPUT=$(bash ../fruits.sh)

if [[ "$OUTPUT" == *"apple"* || "$OUTPUT" == *"banana"* ]]; then
  echo "test_fruits.sh: PASS"
  exit 0
else
  echo "test_fruits.sh: FAIL"
  exit 1
fi
