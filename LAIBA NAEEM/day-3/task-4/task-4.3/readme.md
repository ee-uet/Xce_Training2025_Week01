# Problem 
- Write a script that creates a backup of a specified directory
-  The backup should be a compressed tar file with the current date in its name
- Implement error handling for cases where the directory doesn't exist

#
**Approach**
- Start with the shebang line #!/bin/bash.

- Take the directory path from the user using read -p.

- Get the current date in YYYY-MM-DD format using DATE=$(date +%F).

- Create a backup file name: BACKUP_NAME="${Directory}_backup_$DATE.tar.gz".

- Use tar -czf "$BACKUP_NAME" "$Directory" to compress the directory:

  - -c: create archive

  - -z: gzip compression

  - -f: specify the output file name

- Check if the backup file exists using if [[ -f "$BACKUP_NAME" ]] to confirm success.

- Print "Backup successful!" if the file exists, otherwise "Backup failed!".
#
**How to run**  
Open terminal and navigate to the folder where your script is saved.

- Make the script executable (only needed once):  
    chmod +x code.sh


- Run the script normally:  
    ./code.sh

Enter the directory path when prompted.
#
**Example**  
User Input: /mnt/c/Users/123/Documents/test_dir  
Backup file created:
 /mnt/c/Users/123/Documents/test_dir_backup_2025-09-06.tar.gz
#
**Known Limitations**  
If the directory path is incorrect or does not exist, tar will fail.
#
**Verification / What I Learned**

- I understood the syntax and working of the script using the lab slides.

- I used Google and AI to learn how tar works, how to format dates, and check file creation.


