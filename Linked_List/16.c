// Insertion of a Node at the End

#include<stdio.h>
#include<stdlib.h>

int main() {
  struct node{
    int data;
    struct node* next;
  };

  struct node*head, *newnode, *temp;
  head = 0;

  int choice = 1, count = 0;

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
    printf("\nCount is %d", count);

  // =======================================================//
  newnode = (struct node*) malloc(sizeof(struct node));

  printf("\nEnter the data you want to insert: ");
  scanf("%d", &newnode->data);

  newnode -> next = 0;
  temp = head;

  while(temp -> next != 0) {
    temp = temp -> next;
  }

  temp->next = newnode;
  //========================================================//

  count = 0;
  temp = head;
  while (temp != 0)
  {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
    printf("\nCount is %d", count);


}