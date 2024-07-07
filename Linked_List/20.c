// Delete from a given Position
#include<stdio.h>
#include<stdlib.h>
int main() {
  struct node{
    int data;
    struct node* next;
  };

  struct node* head, *temp, *newnode, *nextnode;
  head = NULL;

  int choice = 1, count = 0, pos, i = 1;

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
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) { // Special case: Deleting the first node
                head = temp->next;
                free(temp);} else { 
    while(i < pos - 1) {
      temp = temp->next;
      i++;
    }
    
    nextnode = temp -> next;
    temp->next = nextnode->next;
    free(nextnode);
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