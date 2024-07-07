// Deletion of a Node from LL
// Deletion at the Beginning

#include<stdio.h>
#include<stdlib.h>

int main() {
  struct node {
    int data;
    struct node* next;
  };

  struct node* head, *temp, *newnode;
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
  while (temp != 0) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
    printf("\nCount is %d\n", count);

  // ================================================= //
  if (head != 0) {
    temp = head;
    head = head->next;
    free(temp);
  } else {
    printf("List is empty. Deletion not possible.\n");
  }
  
  //=========================================//
  temp = head;
  count = 0;
  while (temp != 0) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
    printf("\nCount is %d", count);

  return 0;

}