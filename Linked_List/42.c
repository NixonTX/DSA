// delete from a given position
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

void delfrompos() {
  struct node* current, *nextnode;
  int pos, i = 1, l;

  current = tail->next;   // setting current to be first Node.
  printf("\nEnter position: ");
  scanf("%d", &pos);

  l = getlength();

  if(pos < 1 || pos > l) {
    printf("Invalid position");
  } else if (pos == 1) {
    delfrombeg();
  } else {
    while(i < pos-1) {
      current = current->next;
      i++;
    }

    nextnode = current->next;
    current->next = nextnode->next;
    
    if (nextnode == tail) { // If the node to be deleted is the last node
      tail = current; // Update tail to the previous node
    }

    free(nextnode);
  }
};

int main() {
  createCLL();
  display();
  delfrompos();
  display();

  return 0;
}