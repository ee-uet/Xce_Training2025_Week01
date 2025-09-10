## first 10 Multiples of a Number 

This script calculates and prints the **1st 10 multiples** of a number provided by the user.

---

## Code Explanation

1. **Argument Check**  
   ```bash
   if [ "$#" -ne 1 ]; then
       echo "Provide exactly a number."
       exit 1
   fi
    ```
    Ensures the user provides exactly one argument.
    If not, the script exits with an error message.
3. Saves the provided number into the variable numberIterates from 1 to 10.
4. Calculates each multiple (number * i).

---

#### Example Run

$ ./multiples.sh 7
Multiple 1 of 7 is: 7
Multiple 2 of 7 is: 14
Multiple 3 of 7 is: 21
Multiple 4 of 7 is: 28
Multiple 5 of 7 is: 35
Multiple 6 of 7 is: 42
Multiple 7 of 7 is: 49
Multiple 8 of 7 is: 56
Multiple 9 of 7 is: 63
Multiple 10 of 7 is: 70

---

#### Run
```bash
chmod +x for_loop.sh   
./for_loop.sh 7
```