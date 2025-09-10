# Text Processing

This script creates a **log file** with multiple entries and analyzes it to provide the :

1. Total number of log entries
2. Unique usernames
3. Count of actions per user

---

## Code Explanation

**Create File with Log Entries**
```bash
echo -e "2022-10-01 user1 login\n2022-10-02 user2 logout\n2022-10-03 user1 update\n2022-10-04 user3 login\n2022-10-05 user2 update" > log.txt
here,
-e : enables interpretation of special characters like \n (newline).
 > : writes output to the file (also overwrites).
 ```
**Explanation of some other key commands:**

[[ -f $file ]]: checks if the file exists
wc -l : counts the number of lines i-e (total entries)
wc -w : counts the number of words
cut -d ' ' -f 2 : extracts the username (2nd column)
sort -u : sorts and removes duplicate usernames
awk '{print $2}' | sort | uniq -c : counts actions per user

#### Example Run
$ ./text_processing.sh
Total number of entries: 5
Unique usernames:
user1
user2
user3
Actions per user:
      2 user1
      2 user2
      1 user3


---
#### Sources Used
AI and website to see how to extract specific column.

#### Run
chmod +x text_processing.sh
./text_processing.sh
