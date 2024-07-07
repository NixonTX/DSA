// without head
// And to Traverse(display)
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
}*tail = NULL;

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
}

int main() {
  createCLL();

  return 0;
}