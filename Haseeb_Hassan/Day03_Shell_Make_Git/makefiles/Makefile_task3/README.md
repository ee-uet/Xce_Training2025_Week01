# Lab 3 - Makefile Task 3: Script Testing and Management

## Problem

Create a comprehensive Makefile system to manage, test, and deploy bash scripts. The project involves:

- Managing multiple bash scripts (`greet.sh`, `fruits.sh`)
- Implementing automated syntax checking
- Running unit tests for script functionality
- Providing installation capabilities to system directories
- Maintaining clean project structure with proper organization

The goal is to demonstrate advanced Makefile features including `.PHONY` targets, conditional execution, loops, and system integration.

## Approach

The solution implements a multi-stage build and test system:

1. **Script Management**: Using variables to define script lists for easy maintenance
2. **Syntax Validation**: Automated syntax checking using `bash -n` before testing
3. **Automated Testing**: Running test scripts from a dedicated `tests/` directory
4. **System Integration**: Installing scripts to system-wide locations with proper permissions
5. **Phony Targets**: Using `.PHONY` to ensure targets always execute regardless of file existence
6. **Error Handling**: Implementing proper exit codes and error propagation

### Project Structure
```
├── greet.sh           # Interactive greeting script
├── fruits.sh          # Fruit array demonstration script
├── Makefile          # Build automation and testing
└── tests/            # Test directory
    ├── test_greet.sh  # Tests for greet.sh
    └── test_fruits.sh # Tests for fruits.sh
```

## How to Run

### Prerequisites
- Bash shell environment
- Make utility
- Write permissions for installation (sudo access for system install)
- Test scripts in `tests/` directory

### Available Make Targets

1. **Run all checks and tests (default)**
   ```bash
   make
   # or
   make all
   ```

2. **Syntax check only**
   ```bash
   make check
   ```

3. **Run tests only**
   ```bash
   make test
   ```

4. **Install scripts system-wide**
   ```bash
   sudo make install
   ```

5. **Clean project**
   ```bash
   make clean
   ```

### Making Scripts Executable
```bash
chmod +x *.sh tests/*.sh
```

### Complete Workflow
```bash
# Make scripts executable
chmod +x *.sh tests/*.sh

# Run syntax check and tests
make

# Install to system (requires sudo)
sudo make install
```

## Examples

### Syntax Check Output
```bash
$ make check
Checking scripts for syntax errors...
Checking greet.sh...
Checking fruits.sh...
All scripts passed syntax check.
```

### Test Execution
```bash
$ make test
Running tests...
Running tests/test_greet.sh...
test_greet.sh: PASS
Running tests/test_fruits.sh...
test_fruits.sh: PASS
```

### Full Make Run
```bash
$ make
Checking scripts for syntax errors...
Checking greet.sh...
Checking fruits.sh...
All scripts passed syntax check.
Running tests...
Running tests/test_greet.sh...
test_greet.sh: PASS
Running tests/test_fruits.sh...
test_fruits.sh: PASS
```

### Installation Process
```bash
$ sudo make install
Checking scripts for syntax errors...
Checking greet.sh...
Checking fruits.sh...
All scripts passed syntax check.
Installing scripts to /usr/local/bin...
Installed greet.sh to /usr/local/bin
Installed fruits.sh to /usr/local/bin
```

### Script Functionality

**greet.sh execution:**
```bash
$ ./greet.sh
Enter your name: John
Hello, John!
```

**fruits.sh execution:**
```bash
$ ./fruits.sh
banana apple pemogranate guava
banana apple pemogranate guava Orange
```

## Known Limitations

1. **Interactive Testing**: The `test_greet.sh` doesn't handle the interactive input properly - it will hang waiting for user input

2. **Test Coverage**: Tests are basic and don't cover edge cases or error conditions

3. **Input Validation**: Original scripts lack input validation and error handling

4. **Test Directory Dependency**: Tests assume they're run from the parent directory (`../script.sh`)

5. **Permission Requirements**: Installation requires sudo privileges which may not be available in all environments

6. **Output Formatting**: The fruits.sh script outputs array elements as a single string rather than individual lines

7. **Incomplete Cleanup**: The clean target doesn't actually clean anything meaningful

8. **Test Isolation**: Tests don't run in isolated environments and could interfere with each other

## Technical Details

### Makefile Features Used

**Variables:**
- `SCRIPTS := greet.sh fruits.sh` - List of scripts to manage
- `INSTALL_DIR := /usr/local/bin` - Installation target directory

**Phony Targets:**
- `.PHONY: all check test install clean` - Ensures targets always run

**Advanced Features:**
- Shell loops within make targets
- Conditional directory checking with `[ -d tests ]`
- Error propagation with `|| exit 1`
- File permission setting with `install -m 755`

**Shell Integration:**
- `@echo` for user feedback (@ suppresses command echo)
- `bash -n` for syntax validation
- `install` command for proper file deployment

### Test Strategy

The testing approach uses:
- **Output Validation**: Checking if expected strings appear in script output
- **Exit Code Propagation**: Proper success/failure reporting
- **Modular Design**: Separate test file for each script

### Security Considerations

- Installation requires elevated privileges
- Scripts installed with proper executable permissions (755)
- No input sanitization in original scripts

## Sources & AI Usage

- GNU Make documentation for advanced Makefile features
- Bash scripting best practices for syntax checking
- Unix system administration practices for script installation
- Standard testing methodologies for shell scripts
- No AI tools were used in developing this Makefile system