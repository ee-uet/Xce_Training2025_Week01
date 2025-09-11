#!/bin/bash
declare -A cc
cc[Pakistan]="Islamabad"
cc[China]="Beijing"
cc[India]="New Delhi"
cc[Japan]="Tokyo"
cc[Nepal]="Kathmandu"
cc[Bangladesh]="Dhaka"
cc[SriLanka]="Colombo"
cc[Turkey]="Ankara"
cc[SaudiArabia]="Riyadh"
cc[Afghanistan]="Kabul"
cc[Italy]="Rome"
capital(){
echo "enter country name: "
read country
if [[ -n ${cc[$country]} ]] then
echo "The capital of this country is ${cc[$country]}"
else
	echo "Sorry, I don't know the capital of this country"
fi
}
capital
