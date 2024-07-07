// Insertion of a Node in LL
// Inserting at the beginning
#include<stdio.h>
#include<stdlib.h>

int main() {
  struct node {
    int data;
    struct node*next;
  };
 // struct node*head, *newnode;

  struct node* head, *newnode, *temmp;
  head = 0;

  int choice = 1, count = 0;

  while(choice != 0) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = 0;

    if(head == 0) {
      head = newnode;
      temmp = newnode;
    }
    else { 
      temmp->next = newnode;
      temmp = newnode;
    }
    
    printf("Do You Wanna Continue(0, 1)? ");
    scanf("%d", &choice);
  }

  temmp = head;
  while (temmp != 0)
  {
    printf("%d ", temmp->data);
    temmp = temmp->next;
    count++;
  }
    printf("\nCount is %d\n", count);

// ====================================================== //
  newnode = (struct node*) malloc(sizeof(struct node));
  count = 0;

  printf("Enter data you wanna insert: ");
  scanf("%d", &newnode->data);

  newnode->next = head;
  head = newnode;

// ====================================================== //

  temmp = head;
  while (temmp != 0)
  {
    printf("%d ", temmp->data);
    temmp = temmp->next;
    count++;
  }
    printf("\nCount is %d\n", count);

  return 0;
}