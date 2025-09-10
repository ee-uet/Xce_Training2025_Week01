# Makefile: Shell Script Project Build and Management

## Problem
This Makefile automates the management of a shell script project, handling syntax validation, linting, testing, installation, uninstallation, packaging, and information display for shell scripts in a `scripts` directory with corresponding tests in a `tests` directory.

## Approach
The Makefile organizes tasks into multiple targets:
- Defines directories for scripts (`scripts`), tests (`tests`), installation (`/usr/local/bin`), and documentation (`/usr/local/share/doc/shell-project`).
- Automatically detects `.sh` files in `SCRIPT_DIR` and test scripts (`test_*.sh`) in `TEST_DIR`.
- Supports syntax checking, linting with `shellcheck`, making scripts executable, running tests, installing/uninstalling scripts, creating a distribution package, and displaying project details.

## Walkthrough
1. **Configuration**:
   - `SHELL := /bin/bash`: Uses Bash for Makefile commands.
   - `SCRIPT_DIR`, `TEST_DIR`, `INSTALL_DIR`, `DOC_DIR`: Specify project directories.
   - `SCRIPTS = $(wildcard $(SCRIPT_DIR)/*.sh)`: Collects all `.sh` files in `scripts`.
   - `TEST_SCRIPTS = $(wildcard $(TEST_DIR)/test_*.sh)`: Collects test scripts in `tests`.
2. **Targets**:
   - `all: check-syntax`: Default target validates script syntax.
   - `check-syntax`: Runs `bash -n` on each script, exiting on syntax errors.
   - `shellcheck`: Lints scripts with `shellcheck` if installed, or provides installation instructions.
   - `make-executable`: Sets executable permissions (`chmod +x`) on scripts.
   - `test`: Runs syntax checks, makes scripts executable, and executes test scripts, failing if any test fails.
   - `install`: Installs scripts to `INSTALL_DIR` without `.sh` extensions after passing checks and tests.
   - `uninstall`: Removes installed scripts from `INSTALL_DIR`.
   - `package`: Creates a `tar.gz` package in `dist/shell-project-1.0` with scripts, tests, Makefile, and a README.
   - `info`: Lists scripts with their second line (often a description), test scripts, and the install directory.
   - `clean`: Deletes `dist` directory and temporary test files (`/tmp/test_file_*`).
   - `dev`: Combines syntax checks, `shellcheck`, and tests for development workflows.
3. **Execution**:
   - Uses `for` loops to iterate over scripts/tests.
   - Employs `$$` for shell variable expansion (e.g., `$$script`).
   - Includes error handling for missing files or failed tests.

## How to Run
1. **Prerequisites**: Requires Bash and `make` in a Unix-like environment (e.g., Linux, macOS, WSL). `shellcheck` is optional for linting.
2. **Prepare Files**: Place shell scripts in `scripts/` and test scripts (named `test_*.sh`) in `tests/`.
3. **Check Syntax**:
   ```bash
   make
   ```
   Validates syntax of all scripts.
4. **Run Tests**:
   ```bash
   make test
   ```
   Executes tests after syntax checks and making scripts executable.
5. **Install** (requires root privileges):
   ```bash
   sudo make install
   ```
   Installs scripts to `/usr/local/bin`.
6. **Uninstall** (requires root privileges):
   ```bash
   sudo make uninstall
   ```
7. **Create Package**:
   ```bash
   make package
   ```
   Generates `dist/shell-project-1.0.tar.gz`.
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
10. **Show Info**:
    ```bash
    make info
    ```
    Displays project details.

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
- `SHELL := /bin/bash`: Specifies Bash for Makefile execution.
- `$(wildcard ...)`: Matches files (e.g., `*.sh` for scripts).
- `@`: Suppresses command echo, showing only output.
- `for script in $(SCRIPTS); do ...; done`: Iterates over scripts in a shell loop.
- `$$`: Escapes `$` for shell variable expansion (e.g., `$$script`).
- `bash -n "$$script"`: Checks script syntax without running it.
- `command -v shellcheck >/dev/null 2>&1`: Tests if `shellcheck` is installed, redirecting output/errors.
- `shellcheck $(SCRIPTS)`: Runs `shellcheck` linting on all scripts.
- `chmod +x`: Sets executable permissions.
- `test_failed=0`: Tracks test failures in the `test` target.
- `[ $$test_failed -eq 0 ]`: Checks if all tests passed.
- `basename "$$script" .sh`: Removes `.sh` extension from script names.
- `mkdir -p`: Creates directories, including parents, without errors if they exist.
- `cp "$$script" "$(INSTALL_DIR)/$$script_name"`: Copies scripts to install directory.
- `tar czf`: Creates a compressed tarball.
- `head -2 | tail -1`: Extracts the second line of a script (often a comment).
- `rm -rf`: Removes files/directories recursively without prompting.
- `.PHONY`: Declares non-file targets (e.g., `all`, `clean`).