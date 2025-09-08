# Line Numbering Script

## Problem
Write a Bash script that:
- Reads a text file line by line.
- Prints each line prefixed with its line number.

## Approach
1. Set the filename, e.g., `filename="E4_1.txt"`.
2. Initialize a counter `line_no=1`.
3. Use a `while` loop with `IFS= read -r line` to read each line from the file.
4. Print the line number followed by the line content.
5. Increment the line number counter after each line.

## How to Run
1. Save the script as `E4_1.sh`.
2. Make it executable:
   ```bash
   chmod +x E4_1.sh
    ./E4_1.sh

## Example Run

If E4_1.txt contains:

Hello World
This is a test
Line numbering example


The output will be:

1 : Hello World
2 : This is a test
3 : Line numbering example

## Known Limitations

The filename is hardcoded; must edit the script to change it.

Does not handle non-existent files gracefully (no error message if file missing).

Lines are numbered sequentially starting from 1 only.