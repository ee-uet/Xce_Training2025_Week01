# Task 2 — Operators and Expressions

## Problem
- Write a program that:
  - Takes two integers as input.
  - Performs all arithmetic operations: `+`, `-`, `*`, `/`, `%`.
  - Extends into a simple calculator using a `switch` statement:
    - User chooses the operator (`+ - * / %`).
    - The program executes the selected operation.

## Approach
- Use `scanf` to read two integers.
- Print results for all arithmetic operators.
- Use `switch-case` for a menu-style calculator.
- Handle invalid operator input with a default case.

## How to Run
    ```bash
    gcc t2.c -o t2
    ./t2

## Example Run
    Enter 1st Int: 10
    Enter 2nd Int: 3
    Add: 13
    Subtract: 7
    Multiply: 30
    Divide: 3
    Remainder: 1
    Enter Operator (+, -, *, /, %): *
    Multiply: 30
