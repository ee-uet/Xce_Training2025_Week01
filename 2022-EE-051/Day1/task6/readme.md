# C Program: File Input/Output (I/O)

## Overview
This program demonstrates:
- Writing integers to a file using `fprintf`
- Reading integers back from the file using `fscanf`
- Handling file open errors gracefully
- Using file modes (`"w"` for write, `"r"` for read)

---

## Code Structure
- `task06_file_io()`
  - Opens a file `numbers.txt` in **write mode**
  - Reads 5 integers from the user and writes them to the file
  - Closes the file
  - Reopens `numbers.txt` in **read mode**
  - Reads back the integers and prints them to the console
- `main()`
  - Calls `task06_file_io()`

---

## How the Code Works
1. Opens `numbers.txt` in **write mode**.  
   - If the file cannot be created, an error message is shown.  
2. Reads **5 integers** from the user.  
3. Writes the integers to the file, one per line.  
4. Closes the file.  
5. Reopens `numbers.txt` in **read mode**.  
   - If the file cannot be opened, an error message is shown.  
6. Reads the integers from the file and displays them on the console.  

---
## How to Compile and Run

### Using GCC
```sh
gcc task6 -o task6
./task6

