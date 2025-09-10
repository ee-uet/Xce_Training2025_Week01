# Capitals Lookup Script

## Problem
Write a Bash script that:
- Stores countries and their capitals using an associative array.
- Prompts the user to enter a country name.
- Prints the corresponding capital if it exists, or an error message otherwise.

## Approach
1. Declare an associative array `capitals` with country-capital pairs.
2. Define a function `get_capital()` that:
   - Prompts the user to enter a country.
   - Checks if the country exists in the array using `[[ -v capitals[$country] ]]`.
   - Prints the capital if it exists, or an error message if it does not.
3. Call the function to perform the lookup.

## How to Run
1. Save the script as `E3_3.sh`.
2. Make it executable:
   ```bash
   chmod +x E3_3.sh
    ./E3_3.sh

## Example Run
Enter the name of Country: Pakistan
The capital of Pakistan is: Islamabad

Enter the name of Country: Germany
Sorry, this country is not in my array

## Known Limitations

Only the predefined countries in the array can be queried.

Input is case-sensitive; "pakistan" will not match "Pakistan".

No input validation beyond checking array existence.

## Sources & AI Usage

This Bash script was AI-assisted (ChatGPT). I used AI to understand:

How to declare and initialize associative arrays in Bash.

How to check if a key exists in an associative array using -v.

How to read user input and use it to access array values.

I wrote the script myself after guidance, and all logic is implemented in Bash without copying full code from any source.

## What I Verified

I verified the script’s correctness by testing several scenarios:

Existing keys – Entering countries that exist in the array correctly returns their capital.

Example: Input "Japan" → Output "Tokyo" 

Non-existing keys – Entering a country not in the array prints a proper error message.

Example: Input "Germany" → Output "Sorry, this country is not in my array" 

Case sensitivity – Verified that only exact matches work; lowercase or misspelled keys are treated as missing.

Empty input – Entering nothing triggers the “not in array” message correctly.