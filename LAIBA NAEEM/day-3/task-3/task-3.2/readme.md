# Problem 
- Create an array of fruits
- Write a function that prints each fruit in the arrayi:
- Add a new fruit to the array and call the function again


#
**Approach**
- Start the script with the shebang line #!/bin/bash.

- Define a function named fruits that takes an array as arguments using "$@".

- Inside the function:

    - Use a for loop to iterate over each element of the array.

    - Print each element using echo.

- Create an array arr with some fruit names.

- Call the fruits function with the array elements and store the result in a variable using result=$(fruits "${arr[@]}").

- Print the fruits using echo.

- Add a new fruit to the array using arr+=("watermelon").

- Call the function again to display the updated array.
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
Array: ("Apple" "banana" "mango" "strawberry" "peach")
- Call the function
- Funtion will print each fruit
Apple  
banana  
mango  
strawberry  
peach  

#
**Verification / What I Learned**

- I understood the syntax and working of the script using the lab slides.

- To understand how to access array elements and use special symbols like ("${@}"), 
  ("${arr[@]}"), etc., I used AI to clarify all the terms.

