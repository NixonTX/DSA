// Implementation of Circular LL
// (with head and tail)
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
} *head, *tail = NULL;

void createCLL() {
  int choice = 1;
  struct node* newnode;
  while(choice){
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    if(head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
      tail->next = newnode;
      tail = newnode;
    }
    tail->next = head;

    printf("1 for continue; 0 for exit ");
    scanf("%d", &choice);
  }
  
  struct node* temp = head;

  if(head == NULL) {
    printf("List is Empty");
  } else {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
  /*while(temp->next != head) {
      printf("%d ", temp->data);
      temp = temp->next;
    }*/
}

int main() {
  createCLL();

  return 0;
}