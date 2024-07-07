// Insert after the position

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* newnode;

void insertatbeg() {
  
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

int main() {
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
  
  int pos, i = 1, count = 0;
  struct node* temp;

  printf("Enter position: ");
  scanf("%d", &pos);

  if(pos == 1) {
    insertatbeg();
  } else {
        struct node* temp = head;
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

    while(i < pos) {
      temp = temp->next;
      i++;
    }
    
    newnode->prev = temp;
    newnode->next = temp->next;
    // temp->next = newnode;
    // newnode->next->prev = newnode;
    temp->next->prev = newnode;
    temp->next = newnode;
  }

printf("Updated list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;

}
