// Circular LL

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
} *temp, *head = NULL;

void display() {
  struct node* temp;
  if(head == NULL) {
    printf("List is Empty");
  } else {
    temp = head;

    while(temp->next != head) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("%d", temp->data);
  }
}

int main() {
  int choice = 1;
  struct node* newnode;
  while(choice) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = 0;
    if(head == NULL) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
    temp->next = head;
    printf("1 for continue; 0 for exit ");
    scanf("%d", &choice);
  }
  // printf("%d\n", temp->next->data);

  display();
  return 0;
}