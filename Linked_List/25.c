// Insertion In Doubly LL
// at the beginning

// tail pointer : useful when dealing with DLL, contains the address of the last Node.
// insertion and deletion of the last Node is less time consuming when using a tail pointer.
        // drawback - takes memory.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
  };

int main() {
  struct node* head = NULL;
  struct node* tail = NULL;
  struct node* newnode;
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

  if (head != NULL) {
    // insertion at beginning
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;

    head->prev = newnode; // JL_YT - DSA - 2.11 - 15:40
                          // kind of sticking the new data in between head and first Node.
    newnode->next = head;
    head = newnode;
  }

  int count = 0;
  struct node* temp = head;
  //temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("\nlength is %d\n", count);
  
  return 0;

}