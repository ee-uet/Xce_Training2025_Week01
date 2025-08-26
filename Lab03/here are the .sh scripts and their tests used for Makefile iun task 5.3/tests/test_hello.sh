#!/bin/bash
set -euo pipefail
out=$(bash ./my_shell_scripts/scripts/hello.sh)
[ "$out" = "Hello from Hello.sh" ]
