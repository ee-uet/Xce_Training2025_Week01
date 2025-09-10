# C Program: Enum Weekday Mapper

## Overview
This program demonstrates the use of **`enum` in C** by mapping a number (1–7) to the corresponding day of the week.  
- The user enters a number between **1 and 7**.  
- The program converts it into an **enumerated type (`enum Weekday`)**.  
- It then prints the correct weekday name using a `switch` statement.  

---

## Code Structure
- `enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };`  
  - Defines constants for weekdays (internally `MON = 0`, `TUE = 1`, …, `SUN = 6`).  

- `task08_enum_weekday()`  
  - Takes user input (`day`).  
  - Adjusts input to enum by doing `day - 1` (since `enum` starts from 0).  
  - Uses a `switch` statement to print the weekday name.  
  - If input is outside the range `1–7`, prints `"Invalid input!"`.  

- `main()`  
  - Calls `task08_enum_weekday()`.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task8.c -o task8
./task8
