#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head; // Point new node to current head
    return new_node; // New node becomes the new head
}

struct Node* delete_value(struct Node *head, int value) {
    struct Node *current = head;
    struct Node *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) { // Deleting head(i-e its the first node or head node)
                struct Node *temp = head;
                head = head->next; // Move head to next node
                free(temp); // Free old head
            } else {
                prev->next = current->next; // Bypass current node
                free(current); // Free current node
            }
            return head; // Return new head
        }
        prev = current;
        current = current->next;
    } 
    printf("Value %d not found in list.\n", value);
    return head; // Return unchanged head if value not found
} 
 
void print_list(struct Node *head) {
    struct Node *current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }   
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
} 

void task4_1_linkedlist() {
    struct Node *head = NULL; // Initialize empty list
    head = insert_begin(head, 10);  
    head = insert_begin(head, 20);
    head = insert_begin(head, 30); // Insert nodes at beginning
    print_list(head); // Print list
    head = delete_value(head, 20); // Delete node with value 20
    print_list(head); // Print list after deletion
    head = delete_value(head, 100); // Attempt to delete non-existent value
    print_list(head); // Print list after attempted deletion
  
} 

int main(){
    task4_1_linkedlist();
    return 0;
}