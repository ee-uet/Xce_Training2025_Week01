# Task 4: Advanced Challenge - Linked List

## Problem
Implement a simple linked list with the following operations:
- Insert a node at the beginning
- Delete a node by value
- Print the list

## Approach
1. Define Node structure with data and next pointer
2. Implement insert_begin() to add nodes at head
3. Implement delete_value() to remove nodes by value
4. Implement print_list() to display all nodes
5. Test all operations with sample data

## How to Run

### Compilation
```bash
gcc -o linked_list linked_list.c
```

### Execution
```bash
./linked_list
```

## Example Output
```
30 
20 
10 
End of Linked List!
20 
10 
End of Linked List!
```

## Design Notes
- Uses dynamic memory allocation with malloc()
- Handles edge cases for empty list and head deletion
- Proper memory cleanup with free() on deletion

## Key Concepts Demonstrated
- **Dynamic Memory Allocation**: Using malloc() for new nodes
- **Pointer Manipulation**: Linking nodes with next pointers
- **List Traversal**: Walking through linked list structure
- **Memory Management**: Freeing deleted nodes with free()
- **Edge Case Handling**: Empty list and head node deletion

## Algorithm Details

### Insert at Beginning
1. Allocate memory for new node
2. Set new node's data
3. Point new node to current head
4. Update head to point to new node

### Delete by Value
1. Handle special case if head contains target value
2. Traverse list to find target node
3. Update previous node's next pointer
4. Free memory of deleted node

### Print List
1. Start from head node
2. Print data and move to next node
3. Continue until reaching NULL

## Assumptions & Edge Cases
- Handles empty list insertion
- Handles deletion of non-existent values
- Handles deletion of head node
- Includes memory allocation failure checking

## Known Limitations
- No input validation for node values
- Basic error handling for memory allocation
- Single-direction traversal only (singly linked list)
- No function to free entire list at end

## Memory Management
- Proper malloc() error checking
- Appropriate free() calls on deletion
- No memory leaks in normal operation

## Sources & AI Usage
- Original template code from lab manual
- Went through Caltech Slides for linked list concepts
- Dynamic memory management techniques
- No AI assistance for data structure logic