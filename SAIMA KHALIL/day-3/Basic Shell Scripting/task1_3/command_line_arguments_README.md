# Bash Script: Sum of Two Numbers  

This script takes **exactly two numbers as command-line arguments**, calculates their sum, and then prints the result.  

---

## Code Explanation  

1. **Argument Count Check**  
   ```bash
   if [ "$#" -ne 2 ]; then
       echo "Provide exactly two numbers as arguments."
       exit 1
   fi
   ```
Here,
$# : total number of arguments passed to the script.

-ne 2 : checks if the number of arguments is not equal to 2.

If condition is true, it prints an error message and exits the script with status 1.

---

**Assigning Arguments**

**Sum Calculation**
sum=$((num1 + num2))

**$((...)) :** used for arithmetic operations in 

---

#### Example Run
$ ./sum.sh 5 10
The sum of 5 and 10 is: 15

If arguments are missing or more than two are given:

$ ./sum.sh 5
Provide exactly two numbers as arguments.

---

#### Run
```bash
chmod +x command_line_arguments.sh   # make script executable
./command_line_arguments.sh 7 8
```