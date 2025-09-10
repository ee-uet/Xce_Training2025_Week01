# Problem 
- Create a log file with entries of the format: "YYYY-MM-DD username action"
-  Write a script that:  
    a. Counts the total number of entries  
    b. Lists unique usernames  
    c. Counts actions per user  

#
**Approach**
- Start the script with the shebang line #!/bin/bash.

- Store the log file name in a variable: log="task4.2.txt".

- To count total entries:

   - Use wc -l < "$log"

   - < "$log" redirects the contents of the file to wc -l.

   - wc -l counts the number of lines in the file, giving total log entries.

- To find unique users:

    - Use cut -d' ' -f2 "$log" to extract the second field (assumed user column) using space ' ' as a delimiter.

    - Pipe | sort to sort the user names alphabetically.

    -  Pipe | uniq to filter only unique user names.

- To count actions per user:

    -  Again extract the second field using cut -d' ' -f2 "$log".

    - Pipe | sort to sort them.

    - Pipe | uniq -c to count occurrences of each unique user, showing how many actions each user performed.  
  
Note: Piping is a way to take the output of one command and send it directly as input to another command.
#
**How to run**  
Open terminal and navigate to the folder where your script is saved.

- Make the script executable (only needed once):  
    chmod +x code.sh


- Run the script normally:  
    ./code.sh

For command-line arguments, provide numbers after the script name.

#
**Verification / What I Learned**

- I understood the syntax and working of the script using the lab slides.

- I also learned about piping (|) and how it passes output from one command to another.

- To fully understand commands like wc, cut, sort, and uniq, I used Google and AI to clarify their usage and examples.


