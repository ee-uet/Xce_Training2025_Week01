#  Directory Backup  

This script creates a **compressed backup** of a given directory using `tar` and stores it in a specified backup folder with the **current date** in the filename.

---

## Code Explanation

**Function **  
Takes two arguments:
dir_to_backup: directory you want to back up.
backup_dir: location where the backup should be saved.

And ensures the source directory exists before proceeding.
-p ensures the backup directory is created if it doesn’t exisT.
-c :create archive.
-z : compress with gzip.
-f : specify filename.
-C : change to the source directory before archiving.

---

#### Example Run
$ ./backup.sh
Backup of /mnt/c/Users/Hp/Desktop/XCELERIUM/LAB03/File Operations and Text Processing created successfully at /mnt/c/Users/Hp/Desktop/XCELERIUM/LAB03/backup/backup_2025-09-07.tar.gz

---

#### Sources Used:
AI and some websites to see commands.

---

#### Run

```bash
chmod +x file_backup.sh   
./file_backup.sh

```