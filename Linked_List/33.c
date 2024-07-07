// Reverse a DLL

#include<stdio.h>
#include<stdlib.h>

 struct node {
    int data;
    struct node* next;
    struct node* prev;
  };
  struct node* head, * newnode, *temp, *tail;
  int choice = 1;


void createDLL() {
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
}

void display() {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nlength is %d\n", count);
}

void reverse() { 
  struct node* current, *nextnode;
  current = head;

  while(current != 0) {
    nextnode = current->next;
    current->next = current->prev;
    current->prev = nextnode;
    current = nextnode;
  }
  current = head;
  head = tail;
  tail = current;
}

int main() {
  createDLL();
  display();
  reverse();
  display();

  return 0;
}