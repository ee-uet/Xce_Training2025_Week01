#!/bin/bash
echo "2023-10-26 Junaid login" > logfile.txt
echo "2023-10-26 Asim logout" >> logfile.txt
echo "2023-10-27 Junaid update" >> logfile.txt
echo "2023-10-27 Fatima login" >> logfile.txt
echo "2023-10-28 Junaid login" >> logfile.txt
total_entries=$(wc -l < logfile.txt)
echo "Total entries: $total_entries. Kya baat!"

echo "---"


echo "Hamare unique doston ke naam:"
awk '{print $2}' logfile.txt | sort | uniq

echo "---"
echo "Kaun kya kar raha hai, dekho..."
awk '{print $2 " " $3}' logfile.txt | sort | uniq -c
