# Problem
Implement a simple linked list with the following operations:
-	Insert a node at the beginning
-	Delete a node by value
-	Print the list
#
**Approach**

- Linked List Setup: Created a Node struct with two fields: data to store the value and next to point to the next node. This allows building a dynamic linked list.

1. Insert at Beginning:

   - For inserting a new node at the start, allocated memory dynamically using malloc().
   - Set the new node’s data field to the given value.
   - Made the new node’s next point to the current head.
   - Updated head to the new node, so it becomes the first node in the list.

2. Delete a Node: Traverse the linked list to find the node with the given value.

   Three cases considered:

   -  Node not found: Simply continue traversing until NULL.

   - Node is head: Update head to head->next.

   - Node is in middle or end: Update the previous node’s next to skip the node to be deleted.

   Freed the memory of the deleted node using free() to avoid memory leaks.

3. Print List:
   
   I traverse the list from head to NULL, printing each node’s data to visualize the list.

#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**    
Operations performed:

Insert 10 → List: 10

Insert 20 → List: 20 → 10

Insert 30 → List: 30 → 20 → 10

Insert 40 → List: 40 → 30 → 20 → 10

Deletion Operations:

Delete 40 (head)  List: 30 → 20 → 10

Delete 30 (head)  List: 20 → 10

Delete 20 (head)  List: 10

Delete 10 (head)  List is empty                 
#
**Resources and References**    
For understanding linked list operations and syntax, I referred to concepts already done in the previous lab course, so this was mainly a revision.

