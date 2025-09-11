#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning 
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data= value;
    newnode -> next= head;
    head = newnode ;
    return head;
    
}

struct Node* delete_node(struct Node* head, int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Node found\n");

            if (prev == NULL) {
                head = temp->next;
            } else {
                
                prev->next = temp->next;
            }

            free(temp);  
            break;       
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
      struct Node *temp = head;
     while (temp != NULL ) {
     printf("linked list is %d\n",temp->data);
     temp = temp->next;
}
}
void task4_1_linkedlist() {
    struct Node *head = NULL;         
    head = insert_begin(head, 10);  
    head = insert_begin(head, 20);    
    head = insert_begin(head, 30);
    head = insert_begin(head, 40);   
    head = delete_node(head,40);
    head = delete_node(head,30);
    head = delete_node(head,20);
    head = delete_node(head,10);
    print_list(head); 
}

// ======================= Main =======================
int main() {
 
    // --- Part 4 ---
    task4_1_linkedlist();

 
    return 0;
}
