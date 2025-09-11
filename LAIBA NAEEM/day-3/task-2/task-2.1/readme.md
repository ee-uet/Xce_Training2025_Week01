# Problem 
Write a script that checks:
- if a number (provided as an argument) is even or odd
- Use an if-else statement to print the result
- Test with various numbers.
#
**Approach**
- Start the script with the shebang line #!/bin/bash to specify the shell.

- Use $0 to display the script name and $1 to access the first command-line argument.

- Use an if-else statement to check if the number is even or odd:  
     If $1 % 2 == 0, the number is even.
     Otherwise, the number is odd.

- Print the result using echo.
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
1.
Enter 0th argument: ./code.sh  
Enter 1st argument: 5  
number is odd  
2.
Enter 0th argument: ./code.sh  
Enter 1st argument: 4  
number is even  
#
**Verification / What I Learned**

I did not use AI for this task. I understood the syntax and working of the script using the lab slides.

