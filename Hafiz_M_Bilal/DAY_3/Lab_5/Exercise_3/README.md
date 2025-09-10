# Shell Scripts Project: Exercise 3

## Problem
The task is to automate **syntax checking, testing, and installation** of multiple shell scripts using a Makefile. The goal is to ensure scripts are correct, tested, and deployed to a specified directory.

## Approach
1. **Shell Files Detection**: Uses `$(wildcard *.sh)` to include all shell scripts in the directory.
2. **Syntax Checking**: Uses `shellcheck` to verify the syntax of each script.
3. **Testing**: If a `Tests` directory exists, executes all `.sh` test scripts within it.
4. **Installation**: Copies all shell scripts to a defined installation directory (`install_dir`) with executable permissions.
5. **Makefile Rules**:
   - `all`: Default rule, runs `check`.
   - `check`: Syntax check all shell scripts using `shellcheck`.
   - `test`: Runs all test scripts in the `Tests` folder.
   - `install`: Installs all shell scripts to the defined directory with permissions `755`.

## How to Run
1. Open terminal in project directory.
2. To check shell scripts syntax:
```bash
make check
To run tests (if Tests directory exists):

make test


To install scripts to the specified directory:

make install

## Example Output

Running make check might display:

Checking myscript.sh file syntax
my_script.sh: OK
Successfully checked syntax of all files


Running make test:

Run Tests
Run this test Tests/test_example.sh
Test completed successfully
Run all tests successfully


Running make install:

Installing myscript.sh to this path /home/hafiz/Documents/X_training/C/DAY_3/Lab_5/Exercise_3/instal

## Known Limitations

Requires shellcheck to be installed for syntax checking.

Tests only run if Tests directory exists; otherwise, skipped.

Installation path must exist, otherwise install command will fail.

Unix/Linux-specific; may require modifications for Windows systems.

## Sources & AI Usage

This Makefile was AI-assisted (ChatGPT). I used AI to understand:

How to loop over multiple shell scripts using Makefile variables.

How to check syntax with shellcheck.

How to run test scripts conditionally if a Tests/ directory exists.

How to install scripts to a specific directory with proper permissions (install -m 755).

All logic was implemented manually and adapted to my project.

## What I Verified

I tested the Makefile by:

Syntax check (make check) verified all .sh files pass without errors.

Test run (make test)  verified all test scripts in Tests/ run successfully.

Install (make install) confirmed scripts are copied with correct permissions to the installation directory.

Edge cases → verified behavior when scripts are missing or Tests/ folder doesn’t exist.