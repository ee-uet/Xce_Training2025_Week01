## Singly Linked List Operations

This program demonstrates basic **singly linked list**  i-e insertion at the beginning, deletion of a node by value, and printing the linked list.

---

### Code Explanation

#### Structure  
```c
struct Node {
    int data;
    struct Node *next;
};
```
- data : stores the value of the node.

- next : pointer to the next node in the list.

#### Functions
1. insert_begin(struct Node *head, int value)
    First,it creates a new node with the given value.then,points the new node's next to the current head and returns the new node as the new head of the list.

2. delete_value(struct Node *head, int value)
    First,it searches for the first node with the specified value and if found and if it is the head, moves the head to the next node and frees the old head.otherwise, bypasses the node and frees it.if not found,it then prints a message.At end,it returns the updated head of the list.

3. print_list(struct Node *head)
    First,it traverses the linked list and prints each node's data followed by -> and ends with NULL .At last,it prints "List is empty." if the list has no nodes.

#### Example Run
Linked List: 30 -> 20 -> 10 -> NULL
Linked List: 30 -> 10 -> NULL
Value 100 not found in list.
Linked List: 30 -> 10 -> NULL

#### Run
```bash
gcc task4_1.c -o task4_1 
./task4_1 
```
---