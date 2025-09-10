# Task 4 — Simple Linked List

## Problem
Implement a simple singly linked list with the following operations:
- Insert a node at the beginning.
- Delete a node by value.
- Print the list.

## Approach
- Define a `struct Node` with `data` and `next`.
- For insertion, allocate a new node, set its data, and link it before the current head.
- For deletion, check if the head matches the value; otherwise traverse until the node is found and update links. Free memory to avoid leaks.
- For printing, traverse until `NULL` while printing each node.

## How to Run
1. **Compile the program:**
   ```bash
   gcc task4.c -o out
2. **Run the executable:**
    ./out

## Test Cases
1. Insert at beginning
Input sequence: Insert 10, 20, 30, 40
Expected list: 40 -> 30 -> 20 -> 10 -> NULL
2. Delete a node
Input: Delete 20
Expected list: 40 -> 30 -> 10 -> NULL
3. Delete head node
Input: Delete 40
Expected list: 30 -> 20 -> 10 -> NULL
4. Delete non-existent value
Input: Delete 99
Expected list unchanged.
Example Output
Linked list after insertion:
40 -> 30 -> 20 -> 10 -> NULL
Linked list after deleting 20:
40 -> 30 -> 10 -> NULL

## Known Limitations
1. No input from user (nodes are hardcoded).
2. Only supports integer data type.

## Sources & AI Usage
1. I understand the concepts of dynamic memory allocation, pointer manipulation, and how to maintain a singly linked list.


