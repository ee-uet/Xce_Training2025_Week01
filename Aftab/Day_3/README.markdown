# README: Bash Scripting Tasks

This README provides an overview of the tasks implemented in the provided Bash scripts, detailing their functionality, workings, test cases, and expected outputs. Each task demonstrates fundamental Bash scripting concepts, including user input, conditionals, loops, functions, arrays, file operations, and text processing with `awk`.

## Task 1

### Task 1.1: Hello World
**TODO**: Print a simple "Hello, World!" message.

**Working**: 
Uses `echo` to output the string "Hello, World!" to the console.

**Test Case**: Run the script with the command uncommented.

```
echo "Hello, World!"
```

**Output**:
```
Hello, World!
```

### Task 1.2: Greet User
**TODO**: Prompt for a user's name and greet them.

**Working**: 
Uses `read -p` to prompt for the user's name, stores it in the `NAME` variable, and prints a personalized greeting using `echo`.

**Test Case**: Run the script with input `Alice`.

```
read -p "Enter your name: " NAME
echo "Hello, $NAME!"
```

**Output**:
```
Enter your name: Alice
Hello, Alice!
```

### Task 1.3: Sum of Two Numbers
**TODO**: Take two numbers as command-line arguments and print their sum.

**Working**: 
Accesses command-line arguments `$1` and `$2`, computes their sum using arithmetic expansion `$(($1+$2))`, and prints the result.

**Test Case**: Run the script with `./script.sh 5 3`.

```
echo "The sum of $1 and $2 is: $(($1+$2))"
```

**Output**:
```
The sum of 5 and 3 is: 8
```

## Task 2
### Task 2.1: Even or Odd
**TODO**: Check if a number is even or odd.

**Working**: 
Takes a command-line argument, checks if it’s even using modulo (`$1%2`), and prints whether the number is even or odd using an `if` statement.

**Test Case**: Run the script with `./script.sh 4`.

```
if [ $(($1%2)) == 0 ]; then
    echo "Number is Even!"
else
    echo "Number is Odd!"
fi
```

**Output**:
```
Number is Even!
```

### Task 2.2: Multiplication Table
**TODO**: Print the multiplication table for a given number up to 10.

**Working**: 
Takes a command-line argument and uses a `for` loop to print its multiples from 0 to 10 using arithmetic expansion `$(($1*$i))`.

**Test Case**: Run the script with `./script.sh 3`.

```
for ((i=0; i<11; i++))
do
    echo "$i multiple of $1 is: $(($1*$i))"
done
```

**Output**:
```
0 multiple of 3 is: 0
1 multiple of 3 is: 3
2 multiple of 3 is: 6
3 multiple of 3 is: 9
4 multiple of 3 is: 12
5 multiple of 3 is: 15
6 multiple of 3 is: 18
7 multiple of 3 is: 21
8 multiple of 3 is: 24
9 multiple of 3 is: 27
10 multiple of 3 is: 30
```

### Task 2.3: Guessing Game
**TODO**: Implement a number guessing game with a random number.

**Working**: 
Generates a random number between 1 and 10 using `RANDOM`. Prompts the user to guess until correct, providing feedback ("high" or "low") based on the guess.

**Test Case**: Run the script and guess numbers (e.g., 7, then 5 for random number 5).

```
random=$(( (RANDOM % 10)+1 ))
read -p "Enter your guess: " guess
while [ $guess != $random ]
do
    read -p "Try again: " guess
    if [ $guess -gt $random ]; then
        echo "Guessed number is high. Try lower"
    elif [ $guess -lt $random ]; then
        echo "Guessed number is low. Try higher"
    fi
done
echo "You guessed correctly!"
```

**Output** (assuming random number is 5):
```
Enter your guess: 7
Try again: 7
Guessed number is high. Try lower
Try again: 5
You guessed correctly!
```

## Task 3
### Task 3.1: Factorial Function
**TODO**: Implement a recursive factorial function.

**Working**: 
Defines a `factorial` function that recursively calculates the factorial of a number, with base case returning 1 for inputs ≤ 1.

**Test Case**: Call `factorial 5`.

```
factorial() {
    if [ $1 -le 1 ]; then
        echo 1
    else
        local prev=$(factorial $(($1 -1)))
        echo $(($1 * $prev))
    fi
}
```

**Output**:
```
120
```

### Task 3.2: Fruits Array
**TODO**: Manage an array of fruits, append a new fruit, and print all.

**Working**: 
Defines an array of fruits (`apple`, `banana`, `cherry`), appends `orange` using `+=`, and prints all fruits using a `for` loop in the `print_fruits` function.

**Test Case**: Call `print_fruits` after appending `orange`.

```
fruits=("apple" "banana" "cherry")
fruits+=("orange")
print_fruits
```

**Output**:
```
apple
banana
cherry
orange
```

### Task 3.3: Capitals Lookup
**TODO**: Use an associative array to store country-capital pairs and look up capitals.

**Working**: 
Defines an associative array `capitals` with country-capital pairs. Prompts for a country and prints its capital if found, or an error message if not.

**Test Case**: Call `get_capital` with input `France`.

```
declare -A capitals
capitals=(
    ["USA"]="Washington D.C."
    ["France"]="Paris"
    ["Japan"]="Tokyo"
)
read -p "Enter a country: " country
if [[ -n "${capitals[$country]}" ]]; then
    echo "The capital of $country is ${capitals[$country]}"
else
    echo "Sorry, capital for $country not found."
fi
```

**Output**:
```
Enter a country: France
The capital of France is Paris
```

## Task 4
### Task 4.1: Read File Lines
**TODO**: Create a file with 4 lines and print them with line numbers.

**Working**: 
Creates `example.txt` with 4 lines using `echo`. Reads and prints each line with a line number using a `while` loop and `read`.

**Test Case**: Run the script to create and read `example.txt`.

```
touch example.txt
echo "line 1" > example.txt
echo "line 2" >> example.txt
echo "line 3" >> example.txt
echo "line 4" >> example.txt
current_line=1
while IFS= read -r line; do
    echo "$line"
    ((current_line++))
done < "example.txt"
```

**Output**:
```
line 1
line 2
line 3
line 4
```

### Task 4.2: Log File Analysis
**TODO**: Analyze a log file for total entries, unique users, and user activity counts.

**Working**: 
Creates `logfile.log` with sample login/logout entries. Counts total lines using a `while` loop, extracts unique users with `awk` and `sort`, and counts user activities with `awk`.

**Test Case**: Run the script to analyze `logfile.log`.

```
touch logfile.log
echo "2025-08-25 alice login" > logfile.log
echo "2025-08-25 bob login" >> logfile.log
echo "2025-08-25 alice logout" >> logfile.log
total_lines=0
while IFS= read -r line; do
    ((total_lines++))
done < logfile.log
echo "Total entries: $total_lines"
awk '{print $2}' logfile.log | sort | uniq
awk '{users[$2]++} END {for (user in users) print user ": " users[user]}' logfile.log
```

**Output**:
```
Total entries: 3
alice
bob
alice: 2
bob: 1
```

### Task 4.3: Backup Folder
**TODO**: Create a sample folder and back it up as a compressed tarball.

**Working**: 
Creates a folder `myfolder` with two sample files. Uses `tar` to create a compressed backup named with the current date (`myfolder_backup_YYYYMMDD.tar.gz`).

**Test Case**: Run the script to create and back up `myfolder`.

```
mkdir -p myfolder
echo "sample file 1" > myfolder/file1.txt
echo "sample file 2" > myfolder/file2.txt
backup_name="myfolder_backup_$(date +%Y%m%d).tar.gz"
tar -czf "$backup_name" myfolder
echo "Backup created: $backup_name"
```

**Output** (assuming run on 2025-09-10):
```
Backup created: myfolder_backup_20250910.tar.gz
```

## Notes
- Scripts assume Bash environment with standard utilities (`tar`, `awk`, `sort`, `uniq`).
- Task 4 creates files (`example.txt`, `logfile.log`, `myfolder`, and backup tarball) in the working directory.
- Random number generation in Task 2.3 uses `RANDOM` for a number between 1 and 10.
- Ensure command line arguments are provided where required (Tasks 1.3, 2.1, 2.2).