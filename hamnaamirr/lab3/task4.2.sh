#!/bin/bash
log=logs.log
currentdate=$( date +"%Y-%m-%d")
username=$(whoami)
useraction=$1
echo "$currentdate $username $useraction" >> "$log"

