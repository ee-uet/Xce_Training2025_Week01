
## Problem
- **t3_1:** Create a factorial function  
- **t3_2:** Work with arrays and add elements  
- **t3_3:** Use associative arrays with country-capital pairs  

## Approach
- Defined functions using `function name { … }`  
- Used loops (`for`, `for-in`) for factorial and arrays  
- Used `declare -A` for associative arrays and `-v` for existence check  

## How to Run
1. **Make scripts executable:**
   ```bash
   chmod +x t3_1 t3_2 t3_3
2. **Run each task:**
Factorial:
    ./t3_1
Arrays:
    ./t3_2
Associative Arrays:
    ./t3_3
    
## Test Cases
t3_1
$ ./t3_1
    Enter Number: 5
    Factorial is: 120

t3_2
$ ./t3_2
    Apple
    Banana
    Orange
    Add one more fruit in array
    Apple Banana Orange Mango

t3_3
$ ./t3_3
    Enter a Country Name: Pakistan
    The capital of Pakistan is Islamabad

$ ./t3_3
    Enter a Country Name: Japan
    The capital of Japan is not in the data

## Known Limitations
1. t3_1 only handles positive integers (no input validation).
2. t3_2 prints array but does not check duplicates.
3. t3_3 requires exact spelling of keys (case-sensitive).

