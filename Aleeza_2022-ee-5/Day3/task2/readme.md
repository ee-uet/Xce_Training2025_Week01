# Lab 2: Control Structures

# Exercise 2.1: If-Else Statement
This Bash script checks whether a **number** (provided as an argument) is **even or odd** using an `if-else` statement.  

---
## Approach
- Take the input number from the command line argument.  
- Use modulo `%` operator to check divisibility by 2.  
- If remainder is 0 → number is **even**, else → **odd**.  

---

## How to Run
1. Save the script as `exer2.1.sh`.  
2. Give it execute permission and run with a number:  
   ```bash
   chmod +x exer2.1.sh
   ./exer2.1.sh 7
   ```
## Commands Used

- `$1` : first command-line argument.
- `%` : modulo operator.

# Exercise 2.2: For Loop

This Bash script prints the first 10 multiples of a given number.

## Approach

- Take a number as input argument.
- Use a for loop to iterate from 1 to 10.
- Multiply input number by loop index and print each multiple.

## How to Run

- Save the script as exer2.2.sh.
- Run with a number:
```bash
chmod +x exer2.2.sh
./exer2.2.sh 5
```

## Sources and AI usage

- AI help in explaining Bash arithmetic inside loops.
- Learnt the difference between for with C-style syntax vs for in.

# Exercise 2.3: While Loop (Guessing Game)

This Bash script implements a number guessing game where the computer picks a random number between 0 and 9, and the user keeps guessing until correct.

## Approach

- Use `$RANDOM` to generate a random number between 0–9.
- Prompt the user to guess.
- Use a while loop that runs until guess matches the number.
- Give hints (Too Low / Too High).
- Print success message once correct guess is made.

## How to Run

- Save the script as exer2.3.sh.
- Run:
```bash
chmod +x exer2.3.sh
./exer2.3.sh
```

## Sources and AI usage

- AI clarified random number generation and how to use while with user input. - `ChatGPT`
