# Exercise 5.3: Makefile for a Shell Script Project

## Overview
This exercise demonstrates how to use a **Makefile** to manage a project containing multiple shell scripts.  
The Makefile provides automation for:
1. **Syntax checking** of shell scripts.  
2. **Running unit tests** (if available).  
3. **Installing scripts** into a system directory.  

---

## Project Structure
```

exercise3/
├── scripts/
│   ├── script1.sh
│   ├── script2.sh
│   └── script3.sh
├── tests/
│   ├── test\_script1.sh
│   ├── test\_script2.sh
│   └── test\_script3.sh
└── Makefile.mak

````

- `scripts/` → Contains the main shell scripts.  
- `tests/` → Contains test scripts for validation.  
- `Makefile.mak` → Automates checking, testing, and installing.  

---

## Makefile Features

### Variables
- `SCRIPTS` → All `.sh` files inside `scripts/`.  
- `TESTS` → All `.sh` files inside `tests/`.  
- `INSTALL_DIR` → Default installation path (`/usr/local/bin`), can be overridden.  

### Targets
1. **all**  
   Runs both `check` and `test`.

2. **check**  
   Validates syntax of all shell scripts using `bash -n`.

3. **test**  
   Executes all test scripts inside `tests/`.  
   If no test scripts are found, it prints a message.

4. **install**  
   Installs all scripts into the `INSTALL_DIR`.  
   - Copies scripts.  
   - Makes them executable.  

5. **clean**  
   Dummy clean target (since shell scripts don’t generate build files).  

---

##  Usage

### 1. Check syntax of all scripts
```bash
make -f Makefile.mak check
````

### 2. Run tests

```bash
make -f Makefile.mak test
```

### 3. Install scripts (default `/usr/local/bin`)

```bash
sudo make -f Makefile.mak install
```

### 4. Clean

```bash
make -f Makefile.mak clean
```

---

## Verification

1. **Syntax Check**

   * Ran `make -f Makefile.mak check`.
   * Output confirmed all scripts passed syntax checking.

2. **Tests**

   * Ran `make -f Makefile.mak test`.
   * Each test script (`test_script1.sh`, `test_script2.sh`, `test_script3.sh`) executed successfully.
   * Final output showed `All tests passed.`

3. **Installation**

   * Installed scripts into `/usr/local/bin` using:

     ```bash
     sudo make -f Makefile.mak install
     ```
   * Verified by running:

     ```bash
     which script1.sh
     ```

     and confirming it pointed to `/usr/local/bin/script1.sh`.

---

## Key Features

* Handles **multiple shell scripts automatically**.
* Ensures **script quality via syntax checking**.
* Runs **unit tests** to validate correctness.
* Provides a flexible **install target** with customizable directories.

## Reference
- Slides
- AI
