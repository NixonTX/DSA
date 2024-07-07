// Insertion in Doubly Circular LL
// at end
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
} *head, *tail;

void createDCLL() {
  struct node* newnode;
  head = NULL; int choice = 1;

  while(choice) {
    newnode = (struct node*) malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
      head = newnode;
      tail = newnode;
      head->next = head;
      head->prev = head;
    } else {
      tail->next = newnode;
      newnode->prev = tail;
      newnode->next = head;   // (last Node)always to the first node in case of a DCLL
      head->prev = newnode;   // (first Node)always to the last node
      tail = newnode;
    }
    printf("1 for continue; 0 for exit ");
    scanf("%d", &choice);
  }
};

void insertAtEnd() {
  struct node*newnode;

  newnode = (struct node*) malloc(sizeof(struct node));
  printf("Enter data to be inserted at the end: ");
  scanf("%d", &newnode->data);

  if (head == NULL) {
    head = tail = newnode;
    newnode->prev = tail;
    newnode->next = head;
  } else {
    newnode->prev = tail;
    tail->next = newnode;
    newnode->next = head;
    head->prev = newnode;
    tail = newnode;
  }
};

void display() {
  struct node *temp;
  temp = head;

  if (head == NULL) {
    printf("List Empty");
  } else {
    while(temp != tail) {
      printf("%d ", temp->data);
      temp = temp->next;
    }

    printf("%d", temp->data);
  }
};

int main() {
  createDCLL();
  display();
  printf("\n");
  insertAtEnd();
  display();

  return 0;
}