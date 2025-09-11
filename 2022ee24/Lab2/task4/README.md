
---

# C Program: Linked List Operations (Task 4)

## Problem

This program demonstrates **basic singly linked list operations** in C:

1. **Insert at Beginning** – Adds a new node at the start of the list.
2. **Delete by Value** – Removes a node containing a specific value.
3. **Print List** – Displays the linked list in a readable format.

The program creates a linked list, performs insertion and deletion, and then prints the list before and after deletion.

---

## Approach

### Data Structure

* Defined a `struct Node` with:

  * `int data` – stores node value.
  * `struct Node *next` – pointer to the next node.

### Functions

1. **`insert_begin(struct Node *head, int value)`**

   * Dynamically allocates memory for a new node.
   * Links it to the current head.
   * Returns the new node as the head.

2. **`delete_value(struct Node *head, int value)`**

   * Traverses the list to find a node with the given value.
   * Adjusts links to remove that node.
   * Special handling if the node to be deleted is the head.
   * Returns the updated head pointer.

3. **`print_list(struct Node *head)`**

   * Traverses and prints all node values in the format:

     ```
     value -> value -> ... -> NULL
     ```

4. **`task4_1_linkedlist()`**

   * Demonstrates functionality:

     * Inserts `10`, `12`, `13` at the beginning.
     * Prints list.
     * Deletes `12`.
     * Prints updated list.

---

## Key Concepts Used

* **Dynamic memory allocation** with `malloc`.
* **Linked list traversal** using pointers.
* **Pointer manipulation** to maintain list structure after insert/delete.

---

## How to Run

1. Save the program as `task4.c`.
2. Compile with GCC:

   ```bash
   gcc -o task4 task4.c
   ```
3. Run:

   ```bash
   ./task4
   ```

---

## Example Run

```
13 -> 12 -> 10 -> NULL
13 -> 10 -> NULL
```

---

## Known Limitations

* Memory allocated for traversal pointers (`ptr`, `ptr2`) is unnecessary and causes minor memory leaks.
* Deleted nodes are disconnected but not freed (`free()` not called).
* Program only deletes the **first occurrence** of a value.

---

## What I Verified

* Insert at beginning works correctly.
* Delete by value updates the head when needed.
* Printing correctly shows linked list before and after deletion.

---

## Sources & AI Usage

Code was written manually. AI assistance was used to prepare this `README.md`.

---
