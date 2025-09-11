#!/bin/bash
random=$(( RANDOM % 10 +1))
while true;
 do
   read -p "enter a num" guess 
    if ((  $random > $guess  )); then
         echo "low"
      elif (($random < $guess )); then
         echo "high"
      else
         echo  "equal"
         break
       fi
   
done
