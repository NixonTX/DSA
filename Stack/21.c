#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
} *top = NULL; // top == head

void push() {
  int y;
  printf("Enter data: ");
  scanf("%d", &y);

  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));

  newnode->data = y;
  newnode->next = top;
  top = newnode;
}

void display() {
  struct node *temp = top;

  if(top == NULL) {
    printf("Stack Underflow\n");
  } else {
    printf("Stack elements are: ");
    while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

void peek() {
  if (top == NULL) {
    printf("Stack Underflow\n");
  } else {
    printf("top element is %d\n", top->data);
  }
}

void pop() {
  struct node *temp = top;

  if (top == NULL) {
    printf("Stack Underflow\n");
  } else {
    printf("Deleted item is %d\n", top->data);
    top = top->next;
    free(temp);
  }
}

int main() {
  int choice, y;

  do {
    printf("1.push\n2.pop\n3.peek\n4.display\n5.Exit\nEnter choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      // printf("enter data: ");
      // scanf("%d", &y);
      push();
      break;
    
    case 2:
      pop();
      break;

    case 3:
      peek();
      break;

    case 4:
      display();
      break;

    case 5:
      printf("Exiting...");   
      exit(0);
      break;
    
    default:
      printf("Enter valid choice");
      break;
    }
    printf("\n");
  }
  while(choice != 0);

  return 0;
}