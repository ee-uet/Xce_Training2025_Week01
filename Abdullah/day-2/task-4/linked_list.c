#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    // Allocate memory for new node
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    // Check for memory allocation failure
    if (new_Node == NULL){
      printf("Memory Allocation failed!");
      return head;}
    // Initialize new node
    new_Node->data = value;
    new_Node->next = head;
    head = new_Node;
    return head;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node *current = head;
    struct Node *prev = NULL;

    //if head is to be deleted its pointer must be changed to next node & free head
    if ((current != NULL) && (current->data == value)) {
      head = current->next;
      free(current);
      return head;
      }
    while ((current != NULL)&&(current->data != value)) { //traverse the list until value is found
      prev = current;
      current = current->next;
    }
    if (current == NULL) {
      return head;
      }
      
    prev->next = current->next;
    free(current);
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *current = head;
    while (current != NULL) {
      printf("%d \n", current->data);
      current = current->next;
      }
    printf("End of Linked List!\n");      
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;
    
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);

    printf("Current Linked List:\n");
    print_list(head);

    printf("Deleting value 30 from the list...\n");
    head = delete_value(head, 30);
    
    printf("After Deletion:\n");
    print_list(head);
}

int main() {
    task4_1_linkedlist();
    return 0;
}