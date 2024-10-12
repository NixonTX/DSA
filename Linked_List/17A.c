// Insertion of a Node at a desired position (without prev)

#include <stdio.h>
#include <stdlib.h>

int main() {

    struct node {
        int data;
        struct node* next;
    };

    struct node* head = NULL;
    struct node* newnode, *temp;
    int choice = 1, count = 0, pos, i;

    // Creating the linked list
    while (choice != 0) {
        newnode = (struct node*) malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("Do You Wanna Continue (0, 1)? ");
        scanf("%d", &choice);
    }

    // Displaying the list and counting nodes
    temp = head;
    printf("Current list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nCount is %d\n", count);

    // Insertion at a desired position
    printf("Enter the position to insert a new node: ");
    scanf("%d", &pos);

    if (pos > count + 1 || pos < 1) {
        printf("Invalid position\n");
    } else {
        temp = head;
        i = 1;

        // If inserting at the head (position 1)
        if (pos == 1) {
            newnode = (struct node*) malloc(sizeof(struct node));
            printf("Enter data for the new node: ");
            scanf("%d", &newnode->data);

            newnode->next = head;
            head = newnode;
        } else {
            // Traverse to the node just before the desired position
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }

            // Create a new node
            newnode = (struct node*) malloc(sizeof(struct node));
            printf("Enter data for the new node: ");
            scanf("%d", &newnode->data);

            // Adjust pointers for insertion
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    // Display the list after insertion
    temp = head;
    printf("Updated list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nCount is %d\n", count + 1);

    return 0;
}
