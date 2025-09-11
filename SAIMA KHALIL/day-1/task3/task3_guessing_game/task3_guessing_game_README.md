##  Number Guessing Game
This program is a simple **number guessing game**.  
The computer randomly selects a number between `1` and `100`, and the user tries to guess it.  

---

### Code Explanation
#### Logic
1. Generates a random number using:
   ```c
   random_number = (rand() % 100) + 1;
   ```

    %100 is used here to ensure the number is between 1 and 100.
s
2. User is repeatedly prompted to guess a number.

3. If guess == random_number :
print "You got it right!"

4. If guess < random_number :
print "You are low!"

5. If guess > random_number :
print "You are high!"
6. Loop continues until the correct number is guessed.

---
#### Example Run
Guess number :
50
Well,You are high!
Guess number :
20
Well,You are low!
Guess number :
35
Well,You got it right!

---
#### Run
```bash
gcc task3_guessing_game.c -o task3_guessing_game
./task3_guessing_game
```