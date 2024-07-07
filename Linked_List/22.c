// length of a LL

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
  printf("\nlength is %d\n", count);
}