#!/bin/bash
set -euo pipefail
out=$(bash ./my_shell_scripts/scripts/add.sh)
[ "$out" = "Sum of 2 and 3 is : 5" ]
