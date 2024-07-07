// Infix to Prefix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100

int top = -1, array[MAX_SIZE];

void push(char x) {
  array[++top] = x;
}

char pop() {
  if (top == -1) {
    return -1;
  } else {
    return array[top--];
  }
}

int precedence(char c) {
  if(c == ')') {
    return 0;
  } else if (c == '+' || c == '-') {
    return 1;
  } else if (c == '*' || c == '/') {
    return 2;
  }  
}

void infixToPrefix(char infix[MAX_SIZE], char prefix[MAX_SIZE]) {
  char temp, x;
  int i = 0, j = 0;

  strrev(infix);

  while(infix[i] != '\0') {
    temp = infix[i];
    if (isalnum(temp)) {
      prefix[j++] = temp;
    } else if (temp == ')') {
      push(temp);
    } else if (temp == '(') {
      while ((x = pop()) != ')') {
        prefix[j++] = x;
      }
    }
    else {
      while(precedence(array[top]) >= precedence(temp)) {
        prefix[j++] = pop();
      } push(temp);
    }
    i++;
  } 
    while(top != -1) {
    prefix[j++] = pop();
    prefix[j] = '\0';
  }

   strrev(prefix);
}

int main() {
  char infix[MAX_SIZE], prefix[MAX_SIZE];
  printf("Enter the Infix expression: ");
  gets(infix);
  printf("\nThe infix expression is %s", infix);

  infixToPrefix(infix, prefix);

  printf("\nThe prefix expression is %s", prefix);

  return 0;
}
