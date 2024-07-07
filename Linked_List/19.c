// Delete from End
#include<stdio.h>
#include<stdlib.h>
int main() {
  struct node{
    int data;
    struct node* next;
  };

  struct node* head, *temp, *newnode, *prevnode;
  head = NULL;

  int choice = 1, count = 0;

  while(choice != 0) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    
    newnode->next = NULL;

    if(head == NULL) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }

    printf("Do you wanna continue(0, 1)? ");
    scanf("%d", &choice);
  }

  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("\nCount is %d\n", count);

  if(head == NULL) {
    printf("List is Empty, Deletion Not Possible.");
  } else {
    temp = head;
    while(temp->next != NULL) {
      prevnode = temp;
      temp = temp->next;

      if(temp == head) {
        head = NULL;
      } else {
        prevnode->next = NULL;
      }
      free(temp);
    }
  }

  count = 0;
  temp = head;
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("\nCount is %d", count);

  return 0;
}