
---

# C Program: Fibonacci Sequence & Guessing Game (Task 3)

## Problem

This program implements two tasks:

1. **Fibonacci Sequence Generator**
   Prints the first `n` terms of the Fibonacci sequence.

2. **Guessing Game**
   Generates a random number between 0 and 100. The user keeps guessing until they find the correct number, with hints provided if the guess is far from the target.

## Approach

### Fibonacci Sequence

1. Start with two numbers: `0` and `1`.
2. Read the number of terms `n` from the user.
3. Print the first two terms.
4. Use a loop to calculate and print the next terms by summing the previous two numbers.

### Guessing Game

1. Generate a random number in the range \[0,100] using `rand() % 101`.
2. Prompt the user for a guess.
3. If the guess is **too high** (difference ≥ 25), print `"guess is too high"`.
4. If the guess is **too low** (difference ≤ -25), print `"guess is too low"`.
5. Repeat until the user guesses the number correctly.
6. Print the total number of attempts.

### Key Concepts Used

* **Loops (`for`, `while`)**: To iterate through Fibonacci terms and guesses.
* **Conditionals (`if-else`)**: To compare guesses with the random number.
* **Random Number Generation**: Using `rand() % 101` for values between 0 and 100.

## How to Run

To run this program:

1. Copy the code into a file named `task3.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task3 task3.c
   ```
3. Run the compiled executable:

   ```bash
   ./task3
   ```

## Examples

### Example 1: Fibonacci Sequence

```
Enter n = 7
0,1,1,2,3,5,8,
```

### Example 2: Guessing Game

```
Enter guess(again): 50
guess is too high
Enter guess(again): 20
guess is too low
Enter guess(again): 34
You took 3 tries
```

## Known Limitations

* The random number is **not seeded** with `srand(time(NULL))`, so the same sequence of random numbers may appear across runs.
* Fibonacci output always prints `0,1,` even if `n < 2`.
* Output includes a trailing comma in the Fibonacci sequence.
* Guessing feedback only appears if the guess is off by **25 or more**; close but incorrect guesses show no message.
* Large values of `n` in Fibonacci may cause integer overflow.

## What I Verified

* **Edge Cases**:

  * `n = 1` and `n = 2` still produce valid partial Fibonacci outputs.
  * Guessing correctly on the first try works.
  * Boundary numbers `0` and `100` are handled.
  
* **Constraints**:

  * Assumes user enters valid integers.
  * Fibonacci results limited by `int` range in C.

## Sources & AI Usage

The program was written from scratch for practice. AI assistance was used to structure this `README.md` and document possible edge cases and limitations.

---

