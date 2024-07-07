// Insertion at any position CLL
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

void insertAtBeg() {
  struct node* newnode;

  newnode = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter data: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;

  if(tail == NULL) {
    tail = newnode;
    tail->next = newnode;
  } else {
    newnode->next = tail->next;
    tail->next = newnode;
  }
  printf("data entered is %d\n", tail->next->data);
};

int getlength() {
  struct node* head = tail->next;
  int count = 0;
  struct node* temp = head;
  if (head != NULL){
    do {
      temp = temp->next;
      count++;
    } while (temp != head);
  }

  printf("\nlength is %d\n", count);
  return count;
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

void insertAtPos() {
  struct node* newnode, *temp;
  int pos, i = 1;

  printf("\nEnter the position to be inserted: ");
  scanf("%d", &pos);

  int l = getlength();

  if (pos < 0 || pos > l) {
    printf("Invalid position");
  } else if (pos == 1) {
    insertAtBeg();
  } else {
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter data you wanna insert: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;

  temp = tail->next;
  while(i < pos-1) {
    temp = temp->next;
    i++;
  }
  newnode->next = temp->next;
  temp->next = newnode;
  }
};

int main() {
  createCLL();
  display();
  insertAtPos();
  display();

  return 0;
}