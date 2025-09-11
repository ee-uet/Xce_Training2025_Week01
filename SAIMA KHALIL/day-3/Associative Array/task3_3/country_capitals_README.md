# Associative Array Lookup  

This program   uses  **associative arrays ** to store countries and their corresponding **capitals**..  

---

## Code Explanation  

1. **Associative Array Declaration**  
   An associative array `capitals` is declared with country names as **keys** and capital cities as **values**.

2. **Storing Capitals**  
   The script stores mappings like:  
   - Pakistan  : Islamabad  
   - Japan  : Sialkot  
   - India  : Faislabad  
   - China  : Kasur  

3. **Function `get_capital`**  
   - Takes a country name as input.  
   - Checks if the country exists in the array (`-n` checks if value is non-empty).  
   - Prints the capital if found, otherwise prints an error message.  
   -Also,
    `declare` is used to define variables with specific attributes.  
    `-A` option tells bash to create an **associative array**

4. **User Input**  
   The script prompts the user to enter a country name.  

5. **Output**  
   - If the country exists, it prints the corresponding capital.  
   - If not, it shows an error message.  

---

#### Example Run  

Enter a country name to find its capital:
Pakistan
The capital of Pakistan is: Islamabad

Enter a country name to find its capital:
Nepal
Error: Something went wrong here ! .

#### Run

```bash
chmod +x country_capitals.sh
./country_capitals.sh
```