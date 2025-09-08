#include <stdio.h>
#include <stdlib.h>

// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    // Pointer to the next node
    struct Node *next;
};

// Function to insert a new node at the beginning
struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    // Allocate memory for the new node
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = value;
    new->next = head;
    return new;
}

// Function to delete a node by value
struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node* temp = head;
    struct Node* pre = NULL;

    // Case 1: If head node itself contains the value
    if(temp != NULL && temp->data == value){
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Search for the value in the list
    while((temp != NULL) && (temp->data != value)){
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    free(temp);
    return head;
}

// Function to print the linked list
void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;

    //insert some elements
    head = insert_begin(head,10);
    head = insert_begin(head,20);
    head = insert_begin(head,30);

    //print linked list
    printf("Print Linked list: ");
    print_list(head);
    //delete node
    head = delete_value(head,30);
    printf("Print Linked list after deleting node: ");
    print_list(head);    

}

// ======================= Main =======================
int main() {
    
    task4_1_linkedlist();

    return 0;
}
