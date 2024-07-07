// Reversing a LL

#include<stdio.h>
#include<stdlib.h>
int main() {
  struct node{
    int data;
    struct node* next;
  };

  struct node* head, *prevnode, *currentnode, *nextnode;
  head = NULL;

  int choice = 1, count = 0;

  while(choice != 0) {
    nextnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &nextnode->data);
    
    nextnode->next = NULL;

    if(head == NULL) {
      head = nextnode;
      currentnode = nextnode;
    } else {
      currentnode->next = nextnode;
      currentnode = nextnode;
    }

    printf("Do you wanna continue(0, 1)? ");
    scanf("%d", &choice);
  }

  currentnode = head;
  while (currentnode != NULL) {
    printf("%d ", currentnode->data);
    currentnode = currentnode->next;
    count++;
  }
  printf("\nCount is %d\n", count);

  prevnode = NULL;

  currentnode = head;
  nextnode = head;

  while(nextnode != NULL) {
    nextnode = nextnode->next;
    currentnode->next = prevnode;
    prevnode = currentnode;

    currentnode = nextnode;
  }
  head = prevnode;

  // to display
  count = 0;  
  currentnode = head;

  while (currentnode != NULL) {
    printf("%d ", currentnode->data);
    currentnode = currentnode->next;
    count++;
  }

  printf("\nCount is %d\n", count);
  return 0;
}
