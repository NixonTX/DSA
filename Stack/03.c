// Implementation of Stack using LL
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node * next; // link
} *top = NULL;

void push(int x) {
  struct node* newnode;
  newnode = (struct node*)malloc(sizeof(struct node));

  newnode->data = x;
  newnode->next = top;
  top = newnode;
}
// Don't require an Overflow statement

void display() {
  struct node* temp = top;

  if (top == NULL) {
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
  struct node* temp = top;

  if (top == NULL) {
    printf("Stack Underflow\n");
  } else {
    printf("Deleted item is %d\n", top->data);
    top = top->next;
    free(temp);
  }
}


int main() {
  int ch, y;

  do {
    printf("1.push\n2.pop\n3.peek\n4.display\n5.Exit\nEnter choice:");
    scanf("%d", &ch);


    switch(ch) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &y);
        push(y);
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
    }
    printf("\n");
  }
  
  while (ch != 0);

  return 0;
}