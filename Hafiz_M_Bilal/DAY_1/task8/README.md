# Task 0.8 – Enum Weekday

## Problem
- Use an **enum** to represent weekdays (Monday to Sunday).  
- Map an integer input (1–7) to the corresponding day of the week.  
- Print the day name, or an error message for invalid input.  

---

## Approach
1. Define an `enum Weekday` with values:  
MON = 1, TUE, WED, THU, FRI, SAT, SUN
2. Take user input (`day`), an integer between 1–7.  
3. Use a `switch` statement to map the integer to the appropriate weekday.  
4. Print the weekday name if valid, otherwise print an error message.  

---

## How to Run
1. Save the code in a file, `task_8.c`.  
2. Compile the program:  
```bash
gcc task_8.c -o task_8
./task_8

## Example Output
Enter a number (1-7): 5
Friday

## Known Limitations

Only works with integer input (1–7).

No input validation for non-numeric values (e.g., letters will cause runtime error).