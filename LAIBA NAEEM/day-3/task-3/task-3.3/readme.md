# Problem 
- Create an associative array of country-capital pairs
- Write a function that asks the user for a country and returns its capital
- Implement error handling for countries not in the array
#
**Approach**
- Start the script with the shebang line #!/bin/bash.

- Use declare -A to create an associative array named capital, mapping country names to their capitals.

- Define a function capitals that takes two arguments:

- A name reference to the array using local -n copy=$1 (so the function can access the original array).

- Use a for loop to iterate over the keys of the array ("${!copy[@]}").

- Compare each key with the input country name:

     - If a match is found, print the country and its capital.

     - If no match is found, print "not available".

- Use read -p to take the country name from the user.

- Call the function with the array and the input country name.
#
**How to run**  
Open terminal and navigate to the folder where your script is saved.

- Make the script executable (only needed once):  
    chmod +x code.sh


- Run the script normally:  
    ./code.sh

For command-line arguments, provide numbers after the script name.
#
**Example**    
1.  Enter country: India  
India = Delhi    
2. Enter country: Turkey  
not available
#
**Verification / What I Learned**

- I understood the syntax and working of the script using the lab slides.

- To understand how to access array elements, I used AI to clarify all the terms.

