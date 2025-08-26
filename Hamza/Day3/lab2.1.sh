#!/bin/bash
if [ $(($1 % 2)) -eq 0 ]; then
    echo "Arey wah! $1 toh even hai, shabash!"
else
    echo "Nah, bhai. $1 toh odd hai. No tension!"
fi
