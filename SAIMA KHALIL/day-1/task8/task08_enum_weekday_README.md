## Enum Weekday

This program demonstrates the use of `enum`  to represent weekdays. The user enters a number from 1 to 7, and the program prints the corresponding day.

---

### Code Explanation

#### Enum Declaration
```c
enum Weekday { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };
```
- Assigns sequential integers starting from 1 to each day of the week.
Input and Switch

- User inputs an integer day.

- switch statement checks the value of day and prints the corresponding day name.

- default case handles invalid input
---
#### Example Run
Enter a number from 1 to 7 for the day of the week: 3
Wednesday
Enter a number from 1 to 7 for the day of the week: 9
Something went wrong here!

---
#### Run
```bash
gcc task08_enum_weekday.c -o task08_enum_weekday
./task08_enum_weekday
```
---