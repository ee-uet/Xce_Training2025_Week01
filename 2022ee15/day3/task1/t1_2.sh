#!/bin/bash
# -p flag shows prompt and stores input in variable
read -p "Enter Name: " NAME
echo "Hello ${NAME}"   

read -p "Enter Number: " NUM
echo "You entered: ${NUM}"

