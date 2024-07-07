// Infix to Postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

struct Stack {
  int top;
  unsigned capacity;
  char* array;
};

struct Stack* createStack(unsigned capacity){
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (char*)malloc(stack->capacity* sizeof(char));
  return stack;
}

int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

void push(struct Stack* stack, char op) {
  stack->array[++stack->top] = op;
}

char pop(struct Stack* stack) {
  if (!isEmpty(stack)) {
    return stack->array[stack->top--];
  // return "One item poped";
  }
}

char peek(struct Stack* stack) {
  if (!isEmpty(stack)) {
    return stack->array[stack->top];
  // return "This is the top element";
  }
}

int precedence(char op) {
  switch(op) {
    case '+':
    case '-':
      return 1;
    case '/':
    case '*':
      return 2;
    case '^':
      return 3;
  }
  return -1;
}

void infixToPostfix(char* infix, char* postfix) {
  struct Stack* stack = createStack(strlen(infix));
  int i, k;
  for (i =0, k = -1; infix[i]; i++) {
    if (infix[i] == ' ' || infix[i] == '\t')
      continue;
    else if (isalnum(infix[i]))
      postfix[++k] = infix[i];
    else if (infix[i] == '(')
      push(stack, infix[i]);
    else if (infix[i] == ')') {
      while (!isEmpty(stack) && peek(stack) != '(')
        postfix[++k] = pop(stack);
      if(!isEmpty(stack) && peek(stack) != '(')
        return;
      else
        pop(stack);
    } else {
      while (!isEmpty(stack) && precedence(infix[i]) <=
      precedence(peek(stack)))
        postfix[++k] = pop(stack);
      push(stack, infix[i]);
    }
  }

  while (!isEmpty(stack))
    postfix[++k] = pop(stack);
  postfix[++k] = '\0';
}

int main() {
  char infix[MAX_SIZE], postfix[MAX_SIZE];
  printf("Enter infix expression: ");
  fgets(infix, MAX_SIZE, stdin);
  infix[strcspn(infix, "\n")] = 0;
  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);
  return 0;
}