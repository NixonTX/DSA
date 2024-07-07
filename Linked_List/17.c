// Insertion of a Node at a desired position

#include<stdio.h>
#include<stdlib.h>

int main() {

   struct node{
    int data;
    struct node* next;
  };

  struct node* head, *newnode, *temp;
  head = 0;

  int choice = 1, count = 0, pos, i = 1;

  while(choice != 0) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = 0;

    if(head == 0) {
      head = newnode;
      temp = newnode;
    }
    else { 
      temp->next = newnode;
      temp = newnode;
    }
    
    printf("Do You Wanna Continue(0, 1)? ");
    scanf("%d", &choice);
  }

  temp = head;
  while (temp != 0)
  {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
    printf("\nCount is %d\n", count);
  //=======================================//

  printf("Enter the position: ");
  scanf("%d", &pos);

  if(pos > count + 1 || pos < 1) {
    printf("Invalid position");
  } else {
    temp = head;
    struct node* prev = 0;
    while(i < pos) {
      prev = temp;
      temp = temp -> next;
      i++;
    }

    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    //newnode->next = temp-> next;
    newnode->next = temp;
    if (prev == 0) {
      head = newnode;
    } else {
      prev->next = newnode;
    }
    //temp->next = newnode;
  }
  //====================================//
  count = 0;
  temp = head;
  while (temp != 0)
  {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
    printf("\nCount is %d", count);

  return 0;
}