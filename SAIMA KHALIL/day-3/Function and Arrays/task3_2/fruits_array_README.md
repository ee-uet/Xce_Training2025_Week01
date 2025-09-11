# Bash Script: Fruits Array Example  

This script demonstrates how to use **arrays in Bash**, iterate through them, and add new elements dynamically.  

---

## Code Explanation  

1. **Declaring an Array**  
   ```bash
   fruits=("Apple" "Banana" "Cherry" "Date")
   ```
   Creates an array named fruits with four initial values.
   The function print_fruits loops through all elements of the array using 
   "${fruits[@]}" (@ means all elements here).
   Each fruit is printed with a - prefix.

2. **Appending a New Element**
    ```bash
    fruits+=("Kiwi")
    ```
    Adds "Kiwi" to the existing array.

---

#### Example Run
$ ./fruits.sh
Fruits in the array:
- Apple
- Banana
- Cherry
- Date
Fruits in the array:
- Apple
- Banana
- Cherry
- Date
- Kiwi

---
#### Run
```bash
chmod +x fruits_array.sh   
./fruits_array.sh
```