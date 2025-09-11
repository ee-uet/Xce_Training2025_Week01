# C Program: Singly Linked List (Insert & Delete by Value)

## Overview
This program demonstrates a simple **singly linked list** in C with the following operations:
- **Insert at Beginning**  
- **Delete Node by Value**  
- **Print Linked List**

---

## Code Structure

### Struct Definition
```c
struct Node {
    int data;
    struct Node *next;
};
```
- Each node contains:
  - `data` → integer value
  - `next` → pointer to the next node

---

### Functions

1. **`insert_begin(struct Node *head, int value)`**  
   - Creates a new node.  
   - Inserts it at the **beginning** of the list.  
   - Returns the new head pointer.  

2. **`delete_value(struct Node *head, int value)`**  
   - Searches for a node with the given value.  
   - Deletes the node (if found).  
   - Updates links and frees memory.  
   - Returns the updated head.  

3. **`print_list(struct Node *head)`**  
   - Iterates through the list.  
   - Prints all node values in `value -> ... -> NULL` format.  

4. **`task4_1_linkedlist()`**  
   - Demonstrates insertion, deletion, and printing with example data.  

---
## Example Output

```sh
Linked List is 30 -> 20 -> 10 -> NULL
Linked List is 30 -> 20 -> NULL
```

---

##  How the Code Works

1. **Insertion**
   - Insert `10` → List = `10`  
   - Insert `20` → List = `20 -> 10`  
   - Insert `30` → List = `30 -> 20 -> 10`  

2. **Printing**
   - Iterates through nodes until `NULL` is reached.  

3. **Deletion**
   - Delete `10` → Removes the last node in current list.  
   - Updated list = `30 -> 20`  

---

##  Key Points
- Memory is allocated dynamically using `malloc`.  
- Deleted nodes are freed using `free`.  
- Operations are efficient for insertion at beginning (O(1)).  
- Deletion requires traversal (O(n)).  

---
## How to Compile and Run

### Using GCC
```sh
gcc task4.c -o task4
./task4
```

---

