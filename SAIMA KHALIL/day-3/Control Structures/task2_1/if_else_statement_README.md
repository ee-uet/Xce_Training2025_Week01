# Even or Odd Checker

This script checks whether a given number  is **even** or **odd**.

---

## Code Explanation

1.**Argument Check**  
   ```bash
   if [ "$#" -ne 1 ]; then
       echo "Provide exactly one number as an argument."
       exit 1
   fi
   ```
  this ensures exactly one number is provided as input.
  exits if the argument count is not correct.
2. Saves the user-provided number in the variable number.
3. Uses the modulo operator % to check divisibility by 2.
4.If divisible, prints even, otherwise odd.

---

#### Example Run
$ ./evenodd.sh 10
10 is even.

$ ./evenodd.sh 7
7 is odd.


---

#### Run

```bash
chmod +x if_else.sh   
./if_else.sh 7

```

