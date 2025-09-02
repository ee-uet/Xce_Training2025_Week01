#!/bin/bash
factorial() {
	 if [ $1 -le 1 ]; 
	 then echo 1 
	 else 
		    local prev=$(factorial $(($1 - 1))) 
		       echo $(($1 * $prev)) 
	 fi 
 }
factorial 5
