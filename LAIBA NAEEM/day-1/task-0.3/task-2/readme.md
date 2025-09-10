# Problem
Guessing Game:
- Computer generates a random number between 1–100.
- User repeatedly guesses until correct.
- Program responds with "Too High" or "Too Low" hints.
##
**Approach**
- I generate a random number between 1 and 100 using (rand() % 100) + 1

- Then I ask the user to guess the number

- I check the guess inside a loop:

  - if the guess is greater than the random number → print "Too High"

  - if the guess is smaller than the random number → print "Too Low"

  - if the guess is equal to the random number → print "Correct" and end the game

- The loop keeps running until the user guesses the right number
##
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
##
**Example**   
Enter your guess: 85  
Too High   
Enter your guess: 54  
Too Low  
Enter your guess: 87  
Too High  
Enter your guess: 84  
Correct
##
**Known Limitations**  
- If the user is unlucky or keeps guessing randomly, the game can take a very long time to finish.
- There is no set limit on the number of guesses.