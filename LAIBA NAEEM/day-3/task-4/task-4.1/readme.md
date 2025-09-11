# Problem 
- Create a text file with several lines of content
- Write a script that reads this file line by line
- Print each line prefixed with its line number

#
**Approach**
- Start the script with the shebang line #!/bin/bash.

- Initialize a variable n=1 to keep track of line numbers.

- Use a while loop with read lines to read the file line by line.

- Inside the loop:

    - Print the line number and the content of the line using echo.

    - Increment the line counter n by 1.

    - Use < task4.1.txt to redirect the file as input to the while loop, so that each line of the file is read one by one.
#
**How to run**  
Open terminal and navigate to the folder where your script is saved.

- Make the script executable (only needed once):  
    chmod +x code.sh


- Run the script normally:  
    ./code.sh

For command-line arguments, provide numbers after the script name.
#
**Example**    
Output of my code:  
Line no:1 HIHello World  
Line no:2 My name is Laiba and I am doing my task 4.1 of   lab 3
Line no:3 Bye!!  
#
**Verification / What I Learned**

- I understood the syntax and working of the script using the lab slides.



