# Problem 
- Create a script that prints the first 10 multiples of a number (provided as an argument)
-  Use a for loop to calculate and print the multiples
-  Test with different numbers

#
**Approach**
- Start the script with the shebang line #!/bin/bash to specify the shell.

- Use $0 to display the script name and $1 to access the first command-line argument (the number).

- Use a for loop from 1 to 10 to generate multiples.

- Inside the loop, calculate the multiple using $(($1 * i)).

- Print each multiple using echo.
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
Enter 1st argument: 4
first 10 multiples are:
4 
8
12
16
20
24
28
32
36
40 
#
**Verification / What I Learned**

I did not use AI for this task. I understood the syntax and working of the script using the lab slides.

