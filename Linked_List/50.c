// Deletion in Doubly Circular LL
// from a given position
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

void delfromPos() {
  struct node* temp;
  int pos, i = 1;
  temp = head;

  printf("Enter position: ");
  scanf("%d", &pos);
  int l = getlength();

  if (pos < 1 || pos > l) {
    printf("Invalid Position");
  } else if (pos == 1) {
    deleteAtBeg();
  }
  else {
    while (i < pos) {
      temp = temp->next;
      i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

  // If position is the last node
    if (temp->next == head) {
      tail = temp->prev;
      free(temp);
    } else {
      free(temp);
    }
  }
}

int main() {
  createDCLL();
  display();
  printf("\n");
  delfromPos();
  display();

  return 0;
}