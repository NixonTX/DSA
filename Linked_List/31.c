// delete from end

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

int main() {
  struct node* head = NULL;
  struct node* tail = NULL;
  struct node* newnode;
  int choice = 1;

  while(choice) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
      tail->next = newnode;
      newnode->prev = tail;
      tail = newnode;
    }

     printf("Do you want to continue(0, 1)? ");
    scanf("%d", &choice);
  }
  // delete at the End
  struct node* temp;
  if(tail == NULL) {
    printf("List is Empty");
  } else {
    temp = tail;
    // tail->prev->next = NULL;
    // tail = tail->prev;
    tail = tail->prev;
    tail->next = 0;

    free(temp);
  }

  int count = 0;
  //struct node* temp = head;
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("\nlength is %d\n", count);
  
  return 0;

}