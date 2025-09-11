# Problem 
- Write a script that implements a simple guessing game
-  Generate a random number between 1 and 10
-  Use a while loop to allow the user to guess until correct
- Provide "higher" or "lower" hints

#
**Approach**
- Start the script with the shebang line #!/bin/bash.

- Generate a random number between 1 and 10 using $RANDOM.

- Ask the user to enter a number using read -p and store it in a variable.

- Use a while loop to repeatedly check the user's guess until it matches the random number.

- Inside the loop:

- If the guess is less than the random number, print "Too low".

- If the guess is greater, print "Too high".

- Prompt the user to try again.

- When the user guesses correctly, print "Correct".
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
Enter number:5  
Number = 5  
Too low  
Try again  
4  
Too low  
Try again  
3  
Too low  
Try again  
2  
Too low   
Try again  
1  
Too low  
Try again  
5  
Too low  
Try again  
6  
Too low  
Try again  
7  
Correct  
#
**Verification / What I Learned**

I did not use AI for this task. I understood the syntax and working of the script using the lab slides.

