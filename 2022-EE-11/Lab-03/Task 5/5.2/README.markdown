# Makefile: Shell Script Project Build and Management

## Problem
This Makefile automates the management of a shell script project, including syntax checking, testing, installation, packaging, and cleanup of shell scripts stored in a `scripts` directory, with tests in a `tests` directory.

## Approach
The Makefile:
- Defines directories for scripts (`scripts`), tests (`tests`), installation (`/usr/local/bin`), and documentation (`/usr/local/share/doc/shell-project`).
- Automatically detects `.sh` files in `scripts` and test scripts (`test_*.sh`) in `tests`.
- Provides targets for syntax checking, linting with `shellcheck`, making scripts executable, running tests, installing/uninstalling, packaging, and displaying project information.

## Walkthrough
1. **Configuration**:
   - `SHELL := /bin/bash`: Specifies Bash as the shell for Makefile commands.
   - `SCRIPT_DIR`, `TEST_DIR`, `INSTALL_DIR`, `DOC_DIR`: Define project directories.
   - `SCRIPTS = $(wildcard $(SCRIPT_DIR)/*.sh)`: Finds all `.sh` files in `scripts`.
   - `TEST_SCRIPTS = $(wildcard $(TEST_DIR)/test_*.sh)`: Finds test scripts in `tests`.
2. **Targets**:
   - `all: check-syntax`: Default target to check script syntax.
   - `check-syntax`: Runs `bash -n` to validate syntax of all scripts.
   - `shellcheck`: Runs `shellcheck` for linting if available, with installation instructions if not.
   - `make-executable`: Sets executable permissions (`chmod +x`) on scripts.
   - `test`: Runs syntax checks, makes scripts executable, and executes test scripts, failing if any test fails.
   - `install`: Installs scripts to `INSTALL_DIR` without `.sh` extension after passing checks and tests.
   - `uninstall`: Removes installed scripts from `INSTALL_DIR`.
   - `package`: Creates a `tar.gz` package in `dist/shell-project-1.0` with scripts, tests, Makefile, and a README.
   - `info`: Displays script names, their second line (often a description), and test script information.
   - `clean`: Removes `dist` directory and temporary test files.
   - `dev`: Runs syntax checks, `shellcheck`, and tests for development.
3. **Execution**:
   - Loops iterate over scripts/tests using `for` loops.
   - Commands use `$$` to escape variables for shell expansion (e.g., `$$script`).
   - Error handling ensures scripts/tests exist and execute successfully.

## How to Run
1. **Prerequisites**: Requires Bash and `make` in a Unix-like environment (e.g., Linux, macOS, WSL). `shellcheck` is optional for linting.
2. **Prepare Files**: Place shell scripts in `scripts/` and test scripts in `tests/` (named `test_*.sh`).
3. **Build**:
   ```bash
   make
   ```
   Checks syntax of all scripts.
4. **Run Tests**:
   ```bash
   make test
   ```
   Executes all test scripts after syntax checks.
5. **Install** (requires root privileges):
   ```bash
   sudo make install
   ```
   Installs scripts to `/usr/local/bin`.
6. **Uninstall** (requires root privileges):
   ```bash
   sudo make uninstall
   ```
7. **Package**:
   ```bash
   make package
   ```
   Creates a `dist/shell-project-1.0.tar.gz` package.
8. **Clean**:
   ```bash
   make clean
   ```
   Removes generated files.
9. **Development Checks**:
   ```bash
   make dev
   ```
   Runs syntax checks, `shellcheck`, and tests.

## Examples
### Sample Run
Assuming `scripts/` contains `script1.sh` and `script2.sh`, and `tests/` contains `test_script1.sh`:
```bash
$ make
Checking syntax of shell scripts...
Checking scripts/script1.sh...
Checking scripts/script2.sh...
All scripts have valid syntax!
$ make test
Checking syntax of shell scripts...
Checking scripts/script1.sh...
Checking scripts/script2.sh...
All scripts have valid syntax!
Making scripts executable...
Running unit tests...
Running tests/test_script1.sh...

All tests passed!
$ make install
Checking syntax of shell scripts...
[Output as above]
Making scripts executable...
Running unit tests...
[Output as above]
Installing scripts to /usr/local/bin...
Installing scripts/script1.sh as script1...
Installing scripts/script2.sh as script2...
Installation complete!
$ make package
Checking syntax of shell scripts...
[Output as above]
Running unit tests...
[Output as above]
Creating distribution package...
Package created: dist/shell-project-1.0.tar.gz
$ make info
=== Shell Script Project Information ===
Scripts found:
  - scripts/script1.sh
    # Description from script1.sh
  - scripts/script2.sh
    # Description from script2.sh

Test scripts found:
  - tests/test_script1.sh

Install directory: /usr/local/bin
$ make clean
Cleaning up...
rm -rf dist/
rm -f /tmp/test_file_*
Clean complete!
```

## Syntactical Shorthands Explained
- `SHELL := /bin/bash`: Sets Bash as the Makefile’s shell.
- `$(wildcard ...)`: Finds files matching a pattern (e.g., `*.sh`).
- `@`: Suppresses command echo, showing only output.
- `for script in $(SCRIPTS); do ...; done`: Loops over scripts in a shell command.
- `$$`: Escapes `$` for shell variable expansion (e.g., `$$script`).
- `bash -n`: Checks script syntax without execution.
- `shellcheck`: Runs `shellcheck` for linting if available.
- `command -v shellcheck >/dev/null 2>&1`: Checks if `shellcheck` is installed.
- `chmod +x`: Makes scripts executable.
- `test_failed=0`: Tracks test failures in the `test` target.
- `[ $$test_failed -eq 0 ]`: Tests if all tests passed.
- `basename "$$script" .sh`: Strips `.sh` from script names.
- `mkdir -p`: Creates directories, including parents, without error if they exist.
- `tar czf`: Creates a compressed tarball.
- `head -2 | tail -1`: Extracts the second line of a file (often a comment).
- `.PHONY`: Declares non-file targets (e.g., `all`, `clean`).
- `rm -rf`: Removes files/directories recursively without prompting.