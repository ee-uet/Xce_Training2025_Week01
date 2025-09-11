
---

# C Program: Simple Calculator (Task 2)

## Problem

This program implements a basic calculator that takes two integers and an arithmetic operator as input. It performs one of the following operations based on the operator provided:

* Addition
* Subtraction
* Multiplication
* Division

The program uses a `switch-case` structure to perform the appropriate arithmetic operation.

## Approach

The program performs the following steps:

1. Takes two integers as input (`num1` and `num2`).
2. Takes an operator (`+`, `-`, `*`, `/`) as input.
3. Uses a `switch-case` statement to perform the operation based on the operator:

   * `+` for addition
   * `-` for subtraction
   * `*` for multiplication
   * `/` for division
4. Prints the result of the operation.
5. If the operator is not recognized, it prints "invalid op!".

### Key Concepts Used:

* **Switch-Case**: A control flow statement that allows for multiple conditional branches based on the value of a variable.
* **Arithmetic Operations**: Basic operations such as addition, subtraction, multiplication, and division.

## How to Run

To run this program:

1. Copy the code into a file named `task2.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task2 task2.c
   ```
3. Run the compiled executable:

   ```bash
   ./task2
   ```


## Examples

### Example 1: Addition

```
Enter num1 = 5
Enter num2 = 3
Enter op = +
5 + 3 = 8
```

### Example 2: Invalid Operator

```
Enter num1 = 10
Enter num2 = 5
Enter op = ^
Invalid op!
```

## Known Limitations

* The program does not handle edge cases where the user provides invalid input (non-integer values or incorrect operators).
* The program performs integer division and truncates the result. For floating-point division, the program would need to handle `float` or `double` types instead of `int`.

## What I Verified

* **Constraints**: The program assumes that the user will input valid integers for the operands and a valid operator. It also assumes integer division for the `/` operator.

## Sources & AI Usage

The program was written from scratch to demonstrate the use of basic arithmetic operations and control flow in C. AI assistance was used to help structure this `README.md`.

---

