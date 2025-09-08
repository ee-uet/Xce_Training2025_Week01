# Part 4 – Linked List Challenge

## Problem
Implement a **singly linked list** in C with the following operations:
1. Insert a node at the **beginning** of the list.
2. Delete a node by its **value**.
3. Print the linked list.

---

## Approach
- Defined a `struct Node` with:
  - `int data` → stores the value
  - `struct Node *next` → pointer to next node
- **Insert at beginning**:
  - Allocate memory using `malloc`.
  - Point the new node’s `next` to the old head.
  - Update head to the new node.
- **Delete by value**:
  - If the value is in the head, adjust head and free memory.
  - Otherwise, traverse the list keeping track of the previous node.
  - Update links to skip the deleted node and free memory.
- **Print**:
  - Traverse the list until `NULL` and print all node values.

---

## How to Run
1. Save the file as `task4_1.c`.
2. Compile:
   ```bash
   gcc task4_1.c -o task4_1
    ./task4_1

## Example Output
Print Linked list: 30 20 10 
Print Linked list after deleting node: 20 10 

## Known Limitations
no function to insert at end.

no function to search for a value.

no free_list() to release all allocated memory.

no Handle case when value does not exist during deletion.