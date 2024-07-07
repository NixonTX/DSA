// Deletion in Doubly Circular LL
// at beginnin
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

void deleteAtBeg() {
  struct node*temp;
  temp = head;

  if(head == NULL) {
    printf("List Empty");
  } else if (head->next == head) {  // In case only one Node
    head = tail = NULL;   // Setting both head and tail to Zero
    free(temp);
  } else {
    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
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
  deleteAtBeg();
  display();

  return 0;
}