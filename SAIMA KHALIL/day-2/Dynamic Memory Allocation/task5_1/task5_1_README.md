# Dynamic Array  

This program demonstrates **dynamic memory allocation** to store an array of integers and to compute their **sum**, and then calculate the **average**.

---

## Code Explanation

1. **Input Number of Elements**  
   User specifies how many integers they want to input.

2. **Dynamic Memory Allocation**  
   Memory is allocated for `n` integers using `malloc`. 

3. **Reading Array Elements & Calculating Sum**  
   The program reads each element into the dynamically allocated array and computes the sum.

4. **Calculating Average**  
   Average is calculated by dividing the sum by `n`.

5. **Output**  
   Prints the sum and average of the array elements.

6. **Freeing Memory**  
   Allocated memory is freed using `free()` and pointer is set to `NULL` to prevent dangling pointers.

---

#### Example Run
Enter number of elements in array: 5
Enter 5 integers:
10 20 30 40 50
Sum: 150, Average: 30.00


---

#### Run

```bash
gcc task5_1.c -o task5_1
./task5_1
```
