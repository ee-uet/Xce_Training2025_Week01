## Command-Line Arguments Sum  

This program demonstrates the use of command-line arguments using `argc` and `argv`. It calculates the sum of two integers provided as arguments.

---

### Code Explanation

#### Parameters
- `argc` : Argument count, includes the program name.  
- `argv` : Array of strings representing the arguments.  

#### Logic
1. Check if exactly **two arguments** are provided (excluding program name).  
   ```c
   if (argc != 3) 
   ```

2. Converts the string arguments to integers using atoi.
   ```c
   int num1 = atoi(argv[1]);
   int num2 = atoi(argv[2]);
   ```

3. Prints the sum of the two numbers.

---
#### Example Run

./task10 5 8
Sum is: 13

 ./task10 5
Something went wrong here!

---

#### Run
```bash
gcc task10_cmd_args.c -o task10_cmd_args
./task10_cmd_args 9 8
```
---