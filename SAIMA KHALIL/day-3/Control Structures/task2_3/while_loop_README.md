#  Guessing Number

This script implements a **number guessing game** in bash where the program generates a random number between 1 and 10, and the user has to guess it.

---

## Code Explanation

1. **Generate Random Number**  
   ```bash
   random_number=$((RANDOM % 10 + 1))
    ```
    RANDOM is a built-in Bash variable that generates random numbers.
    % 10 + 1 ensures the number is between 1 and 10.
2. Starts with a value different from random_number to enter the loop.
3. Keeps asking until the user’s guess matches the random number.
4. Prompts the user for a guess.
5. If the guess is lower than the number then tells user it’s higher.
If the guess is higher than the number then tells user it’s lower.
If correct then congratulates the user and ends the loop.

---

#### Example Run
$ ./guess.sh
Guess a number between 1 and 10: 3
High ha number tmara!
Guess a number between 1 and 10: 7
Low ha number tmara!
Guess a number between 1 and 10: 5
Congratulations! You guessed the number <3 5.

---

#### Run
```bash
chmod +x while_loop.sh   
./while_loop.sh
```
