// Deletion of a Node from Circular LL
// deletion from beginning

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
} *tail = NULL;

void createCLL() {
  int choice = 1;
  struct node* newnode;
  while(choice){
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    if(tail == NULL) {
      tail = newnode;
      tail->next = newnode;
    } else {
      newnode->next = tail->next;
      tail->next = newnode;
      tail = newnode;
    }

    printf("1 for continue; 0 for exit ");
    scanf("%d", &choice);
  }
};

void delfrombeg() {
  struct node* temp;
  temp = tail->next;

  if (tail == NULL) {
    printf("List is Empty");
  } else if (temp->next == temp) {  // In case of only one Node
    tail = NULL;
    free(temp);
  } else {
    tail->next = temp->next;
    free(temp);
  }
};

void display() {
  struct node* temp = tail;

  if(tail == NULL) {
    printf("List is Empty");
  } else {
      temp = tail->next;
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != tail->next);
  }
};

int main() {
  createCLL();
  delfrombeg();
  display();

  return 0;
}