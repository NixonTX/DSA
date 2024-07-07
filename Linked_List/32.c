// deletion from a given position
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* prev;
  struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;
struct node* tail = NULL;

void deletebeg() {
  struct node* temp = NULL;
  if(head == NULL) {
    printf("List is Empty");
    return;
  } else {
    temp = head;
    head = head->next;
    head->prev = NULL;

    free(temp);
  }
}

void deletend() {
  if(tail == NULL) {
    printf("List is Empty");
    return;
  }
  tail = tail->prev;
  if(tail != NULL) {
    tail->next = NULL;
  } else {
    head = NULL;
  }

  free(temp);
}

void deletefrompos() {
  int pos, i = 1;
  struct node* temp = head;

  printf("Enter position: ");
  scanf("%d", &pos);

  if(pos < 1) {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1) {
    deletebeg();
    return;
  }

  while(i < pos) {
    temp = temp-> next;
    i++;
  }
  
  if (temp == tail) {
    deletend();
    return;
  }

  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(temp);
}

int main() {
  
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

  deletefrompos();
  
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