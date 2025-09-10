# Log Analysis Script

## Problem
Write a Bash script that analyzes a log file:
- Counts the total number of entries (lines) in the log.
- Lists all unique usernames.
- Counts the number of actions performed per username.

## Approach
1. Set the filename, e.g., `filename="E4_2.log"`.
2. Use `wc -l` to count the total number of lines (entries) in the log.
3. Use `awk '{print $2}'` to extract the username from each line.
4. Use `sort | uniq` to get the list of unique usernames.
5. Use `sort | uniq -c` to count actions per username and format output with `awk`.

## How to Run
1. Save the script as `E4_2.sh`.
2. Make it executable:
   ```bash
   chmod +x E4_2.sh
    ./E4_2.sh

## Example Run

If E4_2.log contains:

2025-09-07 Hafiz login
2025-09-07 Bilal logout
2025-09-07 Hafiz upload
2025-09-07 Ali login


The output will be:

Total no of entries: 
4

Unique Usernames: 
Ali
Bilal
Hafiz

Count action per username
2 Hafiz
1 Ali
1 Bilal

## Known Limitations

The filename is hardcoded; changing the log file requires editing the script.

Assumes usernames are always the second field in each log entry.

Does not handle empty files or non-existent files gracefully.

## Sources & AI Usage

This Bash script was AI-assisted (ChatGPT). I used AI to understand:

How to extract specific columns from a text file using awk.

How to sort and count unique entries using sort and uniq.

How to combine commands with pipes to process log files efficiently.

All code was implemented manually after guidance, with logic verified for correctness.

## What I Verified

I tested the script on multiple log files:

Total entries – Verified that the wc -l output matches the actual number of lines.

Unique usernames – Checked that only distinct usernames are printed.

Count of actions per username – Confirmed that the counts are accurate by comparing with manual counting.

Edge cases – Tested files with single entries, repeated usernames, and empty lines to ensure correct behavior.