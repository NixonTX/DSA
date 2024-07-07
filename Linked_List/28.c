// Insert at a given position

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* newnode;

void insertatbeg() {
    // No need to redefine head and tail variables here
    // They are already declared as global variables
    struct node* temp = head; // Temporarily store the current head

    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = temp; // Point new node's next to the current head
    temp->prev = newnode; // Update previous of current head
    head = newnode; // Update head to the new node
}

void createDLL() {
    int choice = 1;

    while(choice) {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do you want to continue(0, 1)? ");
        scanf("%d", &choice);
    }

    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nlength is %d\n", count);
}

int main() {
    createDLL();

    int pos, i = 1, count = 0;
    struct node* temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    // Calculate the length of the list
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    if(pos < 1 || pos > count + 1) { // Modified condition to check against count + 1
        printf("Invalid position\n");
    } else if (pos == 1) {
        insertatbeg();
    } else {
        struct node* temp = head;
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        // Traverse to the node before the position
        while(i < pos-1) {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        if(temp->next != NULL) // Check if temp->next is not NULL to avoid dereferencing NULL
            temp->next->prev = newnode;
        temp->next = newnode;
    }

    // Print the updated list
    printf("Updated list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
