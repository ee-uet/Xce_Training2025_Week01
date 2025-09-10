## File I/O  
This program demonstrates **file handling** using a text file (`saima.txt`).  
It performs two operations:  
1. Writing integers to a file  
2. Reading integers back from the file  

---

### Code Explanation  
#### File Pointer  
- `FILE *file;` : declaring a file pointer to handle file operations.  

#### Writing to File
- Open file in write mode: 
`file = fopen("saima.txt", "w");`
- Take 5 integers from the user and write to file using `fprintf`.
- Close file using `fclose(file);`.

#### Reading from File
- Open file in read mode: 
`file = fopen("saima.txt", "r");`
- Read 5 integers using `fscanf`.
- Print numbers and close the file.
---

#### Example Run
Enter 5 integers :
10
20
30
40
50

Numbers read from file are:
10 20 30 40 50

File operations completed successfully.
Okbye!


---
 
#### Run
```bash
gcc task6_file_io.c -o task6_file_io
./task6_file_io
```
