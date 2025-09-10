# File Reading  

This script creates a text file with some content and then reads it **line by line**, printing each line with its corresponding **line number**.

---

## Code Explanation

**Create File with Content**  
   ```bash
   echo -e "Line 1: Hello Guys\n Line 2: I'm Saima :DD \nLine 3: Ok bye!\nLine 4: Bht hgya bs,thak gi hun." > file_content.txt
   ```

**Other important points:**
-e : enables interpretation of special characters like \n (newline).

> : writes output to the file.
sample file file_content.txt is created with multiple lines.
-f ensures the given file exists before reading.
read -r line : reads one line at a time without interpreting backslashes.
and keeps track of line numbers using line_number variable.

---

#### Example Run
$ ./file_reading.sh
1: Line 1: Hello Guys
2: Line 2: I'm Saima :DD
3: Line 3: Ok bye!
4: Line 4: Bht hgya bs,thak gi hun.

---

#### Sources Used
AI and website to see how to read file.

#### Run
```bash
chmod +x file_reading.sh    
./file_reading.sh
```
