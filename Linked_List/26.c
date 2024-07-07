// Insert at the end

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

  // Insertion at the End
  if (head != NULL) {
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
  }

  int count = 0;
  struct node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("\nlength is %d\n", count);
  
  return 0;

}