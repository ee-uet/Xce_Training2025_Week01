#!/bin/bash
read -p "Please enter your name:" Name
echo "Hello! ${Name}, I hope you enjoying well."
read -sp "Please enter your password: " Password
echo
echo "your name is ${Name} pasword is ${Password} "
read -t 5 -p"if it is correct please type yes:" Ans

