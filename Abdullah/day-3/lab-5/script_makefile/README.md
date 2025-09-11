# Exercise 5.3: Makefile for Shell Script Project

## Problem
Create a project with multiple shell scripts and write a Makefile that checks scripts for syntax errors, runs unit tests (if available), and installs scripts to a specified directory.

## Approach
1. Define wildcard patterns to find shell scripts and tests
2. Create syntax checking target using bash -n
3. Implement test running capability
4. Add installation target with proper file permissions
5. Use PHONY targets for all non-file operations
6. Include configurable installation directory

## Required Directory Structure
```
script_makefile/
├── Makefile
├── scripts/
│   ├── hello.sh
│   ├── backup.sh
│   └── utils.sh
└── tests/
    ├── test_hello.sh
    └── test_backup.sh
```

## Sample Script Files

### scripts/hello.sh
```bash
#!/bin/bash
echo "Hello from script!"
```

### scripts/backup.sh
```bash
#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi
echo "Backing up $1..."
```

### tests/test_hello.sh
```bash
#!/bin/bash
# Simple test for hello script
output=$(../scripts/hello.sh)
if [[ "$output" == "Hello from script!" ]]; then
    echo "PASS: hello.sh test"
    exit 0
else
    echo "FAIL: hello.sh test"
    exit 1
fi
```

## How to Run

### Setup
```bash
# Create the directory structure
mkdir -p scripts tests
# Create sample scripts and tests
# Copy the Makefile
```

### Makefile Operations
```bash
make check     # Check all scripts for syntax errors
make test      # Run all test scripts
make install   # Install scripts to default directory
make all       # Run check and test
make clean     # Clean operation (no files to remove)

# Custom installation directory
make install INSTALL_DIR=/usr/local/bin/
```

## Example Output
```bash
$ make check
Checking scripts/hello.sh
Checking scripts/backup.sh
Checking scripts/utils.sh

$ make test
Testing tests/test_hello.sh
PASS: hello.sh test
Testing tests/test_backup.sh
PASS: backup.sh test

$ make install
Installing scripts/hello.sh to install/
Installing scripts/backup.sh to install/
Installing scripts/utils.sh to install/
Installed all scripts to install/
```

## Makefile Structure
```makefile
SCRIPTS := $(wildcard scripts/*.sh)
TESTS := $(wildcard tests/*.sh)
INSTALL_DIR ?= install/

.PHONY: all check test install clean

all: check test

check: 
	@for script in $(SCRIPTS); do \
		echo "Checking $$script"; \
		bash -n $$script || exit 1; \
	done

test: 
	@for test in $(TESTS); do \
		echo "Testing $$test"; \
		bash $$test || exit 1; \
	done

install: 
	@mkdir -p $(INSTALL_DIR)
	@for script in $(SCRIPTS); do \
		echo "Installing $$script to $(INSTALL_DIR)"; \
		install -m 0755 $$script $(INSTALL_DIR); \
	done
	@echo "Installed all scripts to $(INSTALL_DIR)"

clean:
	@echo "Nothing to clean for script project"
```

## Key Concepts Demonstrated
- **Wildcard Expansion**: Finding scripts and tests automatically
- **Loop Construction**: Shell loops within makefile targets
- **Conditional Assignment**: `?=` for default variable values
- **PHONY Targets**: All targets are non-file operations
- **Script Validation**: Using `bash -n` for syntax checking
- **File Permissions**: `install -m 0755` for executable permissions
- **Error Propagation**: `|| exit 1` to stop on first failure

## Critical Fixes Applied
- **FIXED: Tab Indentation**: Converted all spaces to tabs
- **FIXED: Syntax Error**: Corrected backslash placement in loops
- **Added proper PHONY declarations**: All targets properly declared
- **Improved loop structure**: Cleaner shell loop syntax

## Advanced Features
- **Automatic Script Discovery**: No need to manually list scripts
- **Configurable Installation**: Override INSTALL_DIR as needed
- **Error Handling**: Stops on first syntax error or test failure
- **Progress Feedback**: Clear indication of operations being performed
- **Permission Management**: Sets appropriate executable permissions

## Makefile Techniques Used
- **Shell Integration**: Running bash commands within make
- **Variable Assignment**: Default values with conditional assignment
- **Loop Control**: For loops with proper error handling
- **Directory Creation**: Automatic installation directory setup
- **Silent Operations**: `@` prefix for cleaner output

## Error Handling Strategy
```makefile
bash -n $$script || exit 1;
```
This checks syntax and exits immediately if any script has errors.

```makefile
bash $$test || exit 1;
```
This runs tests and stops if any test fails.

## Installation Process
1. Creates installation directory if it doesn't exist
2. Copies each script with executable permissions (755)
3. Provides feedback for each installation
4. Confirms completion

## Assumptions & Edge Cases
- Scripts located in scripts/ subdirectory
- Tests located in tests/ subdirectory
- All .sh files are shell scripts
- Tests are executable and return proper exit codes
- Installation directory is writable

## Known Limitations
- Assumes bash shell for all scripts
- No validation of script shebang lines
- Tests must be self-contained executables
- No uninstall capability
- Limited to .sh file extension

## Best Practices Demonstrated
1. **Consistent directory structure** for organization
2. **Automated discovery** of scripts and tests
3. **Proper error handling** throughout operations
4. **Configurable behavior** with variable overrides
5. **Clear feedback** during operations
6. **Standard permissions** for installed scripts

## Testing Strategy
- Unit tests should be independent
- Tests should return 0 for success, non-zero for failure
- Test files follow naming convention (test_*.sh)
- Tests can be run individually or as a suite

## Sources & AI Usage
- Original template from lab manual
- Looked up Makefile syntax in GNU Make documentation
- Googled best practices for shell scripting
- Used AI for specific syntax corrections and improvements