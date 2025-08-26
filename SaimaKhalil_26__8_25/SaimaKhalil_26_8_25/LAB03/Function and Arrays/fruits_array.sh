#Exercise 3.2: Arrays
#1. Create an array of fruits
#2. Write a function that prints each fruit in the arrayi:
#3. Add a new fruit to the array and call the function again
#!/bin/bash
# Create an array of fruits
fruits=("Apple" "Banana" "Cherry" "Date")
# Function to print each fruit in the array
print_fruits() {
    echo "Fruits in the array:"
    for fruit in "${fruits[@]}"; do #@ means all elements of the array
        echo "- $fruit"
    done
}   
# Call the function to print the initial array
print_fruits
# Add a new fruit to the array
fruits+=("Kiwi")  
# Call the function again to print the updated array
print_fruits    
