// Reversing a Circular LL

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
} *tail = NULL;

void createCLL() {
  int choice = 1;
  struct node* newnode;
  while(choice){
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    if(tail == NULL) {
      tail = newnode;
      tail->next = newnode;
    } else {
      newnode->next = tail->next;
      tail->next = newnode;
      tail = newnode;
    }

    printf("1 for continue; 0 for exit ");
    scanf("%d", &choice);
  }
};

void reverseCLL() {
  struct node* current, *prev, *nextnode;
  current = tail->next;
  nextnode = current->next;

  if (tail == NULL) {
    printf("List Empty");
  } else if (tail->next == tail) {  // In case of only one Node
    printf("Only one Node, ie %d", tail);
  } else {
    while(current != tail) {
      prev = current;
      current = nextnode;
      nextnode = current->next;
      current->next = prev;
    }

    nextnode->next = tail;
    tail = nextnode;
  }
};

void display() {
  struct node* temp = tail;

  if(tail == NULL) {
    printf("List is Empty");
  } else {
      temp = tail->next;
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != tail->next);
  }
};

int main() {
  createCLL();
  display();
  reverseCLL();
  printf("\n");
  display();

  return 0;
}