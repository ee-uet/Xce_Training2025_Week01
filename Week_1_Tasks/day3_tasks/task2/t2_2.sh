#!/bin/bash

read -p"Enter Number: " NUM
for ((i=1;i<=10;i++))
do multiple=$((NUM * i))
echo "${multiple}" 
done