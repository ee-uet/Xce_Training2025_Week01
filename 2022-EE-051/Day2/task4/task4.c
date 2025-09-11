#include <stdio.h>
#include <stdlib.h>

// Linked List
struct Node {
    int data;
    struct Node *next;
};
// Insert node at the beginning
struct Node *insert_begin(struct Node *head, int value) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}
// Delete any node by giving its value
struct Node *delete_value(struct Node *head, int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return head;
    if (!prev) head = head->next;
    else prev->next = temp->next;
    free(temp);
    return head;
}
// Print linked list
void print_list(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List is ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    struct Node *head = NULL;
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    print_list(head);
    head = delete_value(head, 10);
    print_list(head);
}

int main() {
    task4_1_linkedlist();
    return 0;
}
