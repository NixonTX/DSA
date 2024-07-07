#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_S 100

char stack[MAX_S];
int top = -1;

void push(char item) {
    if (top >= MAX_S) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        // exit(1);
    }
    return stack[top--];
}

void postfixToInfix(char postfix[]) {
    int i, l, j =0;
    char current[MAX_S];

    strrev(postfix);
    l = strlen(postfix);
    
    for(i = 0; i < strlen(postfix); i++) {
        stack[i] = '\0';
    }

    printf("\nInfix expression : ");
    
    for(i = 0; i < l; i++) {
        if(postfix[i] == '+' || postfix[i] == '-' 
        || postfix[i] == '*' || postfix[i] == '/') {
            push(postfix[i]);
        } else {
            current[j++] = postfix[i];
            current[j++] = pop();
        }
    }
    current[j] = postfix[top--];
    strrev(current);
    puts(current);
}

int main() {
    char postfix[MAX_S];

    printf("Enter the postfix expression: ");
    gets(postfix);

    postfixToInfix(postfix);
    
    return 0;
}