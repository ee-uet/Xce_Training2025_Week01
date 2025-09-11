# Problem
- Exercise 1.1 (Hello World): Write a shell script that prints "Hello, World!" to the terminal.

- Exercise 1.2 (Variables and User Input): Create a script that asks for the user's name, stores it in a variable, and prints a greeting using that name.

- Exercise 1.3 (Command-line Arguments): Create a script that accepts two numbers as command-line arguments, calculates their sum, and prints it.
#
**Approach**
1. Hello World Script:

   - Start the script with the shebang line #!/bin/bash to specify the shell.

   - Use echo to print "Hello, World!".

   - Run the script in the terminal.

2. Variables and User Input:

   - Use the read -p command to prompt the user for their name.

   - Store the input in a variable Name.

   - Print a greeting using echo "Hello, $Name!".

   - Test with different names to verify it works.

3. Command-line Arguments and Sum Calculation:

   - Use $0 for the script name, $1 for the first number, and $2 for the second number.

   - Calculate the sum using SUM=$(($1 + $2)).

   - Print the result with echo "SUM = $SUM".

   - Run the script with different number pairs to check correctness.
#
**How to run**  
Open terminal and navigate to the folder where your script is saved.

- Make the script executable (only needed once):  
    chmod +x hello.sh


- Run the script normally:  
    ./hello.sh

For command-line arguments (Exercise 1.3), provide numbers after the script name:    
  ./hello.sh 5 7
$0 will show the script name.
$1 and $2 will hold the numbers you pass.
#
**Example**  
#
Exercise 1.1  
Hello World!  
#
Exercise 1.2  
Enter your Name:Laiba  
Hello, Laiba!  
#
Exercise 1.3  
Enter 0th argument: ./code.sh  
Enter 1st argument: 4  
Enter 2nd argument: 5  
SUM = 9  
**Verification / What I Learned**

I did not use AI for these tasks. I understood the syntax and working of the script using the lab slides.
