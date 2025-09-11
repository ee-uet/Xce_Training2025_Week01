# Problem 
- Create a function that calculates the factorial of a number
- Call this function with different numbers in your script
- Print the results

#
**Approach**
- Start the script with the shebang line #!/bin/bash.

- Define a function named factorial that takes one argument (the number).

- Inside the function:

    - Initialize a variable ans to 1.

    - Use a for loop from the number down to 1.

    - Multiply ans by the loop variable i in each iteration.

    - The function returns the factorial by printing ans.

- Call the function with different numbers (3 and 4) and store the result in a variable using answer=$(factorial n).

- Print the results using echo.
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
1. Calculating factorial of 3  
Call the function: factorial 3
Loop execution:

   - i = 3 → ans = 1 × 3 = 3

   - i = 2 → ans = 3 × 2 = 6

   - i = 1 → ans = 6 × 1 = 6
answer = 6
2. Calculating   factorial of 4
Call the function: factorial 4
Loop execution:

   - i = 4 → ans = 1 × 4 = 4

   - i = 3 → ans = 4 × 3 = 12

   - i = 2 → ans = 12 × 2 = 24

   - i = 1 → ans = 24 × 1 = 24
#
**Verification / What I Learned**

I did not use AI for this task. I understood the syntax and working of the script using the lab slides.

