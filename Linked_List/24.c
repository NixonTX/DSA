// with functions

#include<stdio.h>
#include<stdlib.h>

 struct node {
    int data;
    struct node* next;
    struct node* prev;
  };
  struct node* head, * newnode, *temp;
  int choice = 1;


void create() {
  head = NULL;

  while(choice) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      newnode->prev = temp;
      temp = newnode;
    }

    printf("Do you wanna continue(0, 1)? ");
    scanf("%d", &choice);
  }
}

void display() {
  
  int count = 0;

  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("\nlength is %d\n", count);
}


int main() {
  create();
  display();

  return 0;
}