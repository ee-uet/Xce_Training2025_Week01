# Lab 1: Basic Shell Scripting

This lab introduces **basic shell scripting** concepts in Bash. You will learn how to create scripts, use variables, accept user input, and handle command-line arguments.

---

## Exercise 1.1: Hello World

**Problem Statement:**  
Create a simple Bash script that prints "Hello, World!" to the terminal.

**Working:**  
1. Create a new file named `exer1.1.sh`.  
2. Add the **shebang line** to specify the shell interpreter:  
   ```bash
   #!/bin/bash
3. Use the `echo` command to print the message:
   ```bash
    echo "Hello World!"
   ```
4. Make the script executable using:
   ```bash
   chmod +x exer1.1.sh
   ```
5. Run the script:
   ```bash
   ./exer1.1.sh
   ```
Output:
```
Hello World!
```


## Exercise 1.2: Variables and User Input  
This Bash script asks for the **user's name**, stores it in a **variable**, and then prints a **personalized greeting**.  

---

## Approach
- Prompt the user to enter their name using `echo`.  
- Use `read` to capture the user input and store it in a variable.  
- Print a greeting message by referencing the variable.  

---

## How to Run
1. Save the script as `exer1.2.sh`.  
2. Give it execute permission and run:  
   ```bash
   chmod +x exer1.2.sh
   ./exer1.2.sh
   ```

## Exercise 1.3: Command-Line Arguments

**Problem Statement:**  
Create a Bash script that accepts two numbers as command-line arguments, calculates their sum, and prints the result.

**Working:**  

1. Create a new script file named `exer1.3.sh`.  
2. Add the shebang line to specify the shell interpreter:  
   ```bash
   #!/bin/bash
   ```
3. Assign command-line arguments to variables:
   ```bash
   num1=$1
   num2=$2
   ```
4. Calculate the sum using arithmetic expansion:
   ```bash
   sum=$((num1 + num2))
   ```
5. Print the result:
   ```bash
   echo "Sum of $num1 and $num2 is $sum"
   ```
6. Make the script executable and run with two numbers:
   ```bash
   chmod +x sum.sh
   ./sum.sh 5 7
   ```
Output Example:
```
Sum of 5 and 7 is 12
```
## Known Limitations
- Only works with integers.

## Sources & AI Usage
- Bash syntax - `ChatGPT`
- Taking input from user in bash - `ChatGPT`