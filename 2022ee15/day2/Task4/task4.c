#include <stdio.h>
#include <stdlib.h>

// Linked List Node structure
struct Node {
    int data;
    struct Node *next;
};

// Insert a new node at the beginning
struct Node* insert_begin(struct Node *head, int value) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    new_node->data = value;
    new_node->next = head;
    return new_node; // new node becomes the new head
}

// Delete a node by value
struct Node* delete_value(struct Node *head, int value) {
    if (head == NULL) {
        return head; // list empty
    }

    // Case 1: node to delete is head
    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp); // free memory
        return head;
    }

    // Case 2: search in rest of list
    struct Node *current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp); // free memory
    }

    return head;
}

// Print the linked list
void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Task runner
void task4_1_linkedlist() {
    struct Node *head = NULL;

    // Insert nodes at beginning
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    head = insert_begin(head, 40);

    printf("Linked list after insertion:\n");
    print_list(head);

    // Delete a node by value
    head = delete_value(head, 20);
    printf("Linked list after deleting 20:\n");
    print_list(head);
}

int main() {
    task4_1_linkedlist();
    return 0;
}

