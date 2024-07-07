// Implementation of Stack using Array
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
  int x;

  printf("Enter data: ");
  scanf("%d", &x);

  if (top == N-1) {
    printf("Stack Overflow\n");
    return;
  } else {
    top++;
    stack[top] = x;
  }
}

void pop() {
  int item;
  if (top == -1) {
    printf("Stack Underflow\n");
    return;
  } else {
    item = stack[top];
    top--;

    printf("Deleted item is %d\n", item);
  }
}

void peek() {   // top
  if (top == -1) {
    printf("Stack is Empty\n");
  } else {
    printf("top element is %d\n", stack[top]);
  }
}

void display() {
  if (top == -1) {
    printf("Stack is empty\n");
    return;
  }
  
  printf("Stack elements are: ");
  for(int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main() {
  int ch;
  // clrscr();   // Clear the screen

  do {
    printf("Enter choice:\n1.push\n2.pop\n3.peek\n4.display\n");
    scanf("%d", &ch);

    switch(ch) {
      case 1:
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

      default:
        printf("Enter valid choice");
    }
  }
  while (ch != 0);
  getch();    // Wait for a key press before exiting

  return 0;
}