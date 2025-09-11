## Factorial    

This bash script calculates the **factorial** of a given number using a **function**.  

---

## Code Explanation  

1. **Defining the Function**  
   ```bash
   function factorial(){  
       if [ "$1" -eq 0 ]; then
           echo 1
       else
           local result=1
           for (( i=1; i<=$1; i++ )); do
               result=$((result * i))
           done
           echo $result
       fi
   }
    ```
    The function factorial takes one argument ($1).
    If the number is 0, factorial is 1.
    Otherwise, a loop multiplies numbers from 1 upto the argument provided.

2. 
    Stores the user input in number.
    Calls the function and saves the result.
3. $? stores the exit status of the last executed command.
    If it equals 0, the factorial is printed.

#### Example Run
$ ./factorial.sh 5
The factorial of 5 is: 120

$ ./factorial.sh 0
The factorial of 0 is: 1

$ ./factorial.sh
Provide exactly one number as an argument.

#### Run    
```bash
chmod +x factorial.sh   # make script executable
./factorial.sh 5
```
