#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    if (head != NULL)
    {
        new->next = head;
    }
    return new;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr2 = (struct Node*)malloc(sizeof(struct Node));
    ptr = head;
    ptr2 = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            if (ptr == head)
            {
                head = ptr->next;
                ptr = NULL;
                break;
            }
            ptr2->next = ptr->next;
            ptr->next = NULL;
            break;
        }
        ptr2 = ptr;
        ptr = ptr->next;
    }
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    free(ptr);
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;
    head = insert_begin(head,10);
    head = insert_begin(head,12);
    head = insert_begin(head,13);
    print_list(head);
    head = delete_value(head,12);
    print_list(head);
}

int main()
{
    task4_1_linkedlist();
    return 0;
}