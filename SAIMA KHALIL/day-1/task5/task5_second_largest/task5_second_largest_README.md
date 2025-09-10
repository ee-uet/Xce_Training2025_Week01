## Find Second Largest Element in an Array
This program scans an integer array entered by the user and prints the **largest** and **second largest** elements.

---

### Code Explanation
#### Variables
- `arr[100]` : stores user input array (up to 100 integers).  
- `n` : number of elements entered by user.  
- `largest` : stores the largest element.  
- `second_largest` : stores the second largest element.  

#### Logic
1. User enters `n` and then inputs array elements.  
2. If `n < 2`, program exits with a message (we need at least 2 numbers).  
3. Initialize `largest` and `second_largest` using the **first two elements** of the array.  
4. Traverse the array:
   - If the current element is greater than `largest`,  
     - Move `largest` to `second_largest`.  
     - Update `largest` with current element.  
   - Else if the current element is greater than `second_largest` **and not equal to `largest`**, update `second_largest`.  
5. Print the results.  

---

#### Limitations:
If duplicate largest values exist, then the second largest will also be the same as the largest.  
e.g : in `{5, 5, 3}`, the `second_largest` will also be `5`.


---

#### Example Run
1-
Enter number of elements in array: 5
Enter 5 integers:
10 25 47 25 30
Largest element: 47
Second largest element: 30

2-
Enter 5 integers:
10 25 12 25 14
Largest element: 25
Second largest element: 25

---

#### Run:
```bash
gcc task5_second_largest.c -o task5_second_largest
./task5_second_largest
```