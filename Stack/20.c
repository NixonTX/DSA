// Prefix to Infix
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_S 100

char stack[MAX_S][MAX_S];
int top = -1;

void push(char item[]) {
    if(top >= MAX_S - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    strcpy(stack[++top], item);
}

char* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

bool isOperator(char x) {
    switch(x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}

char* preToInfix(char prefix[]) {
    int l = strlen(prefix);

    for(int i = l - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            char* op1 = pop();
            char* op2 = pop();
            char temp[MAX_S];
            sprintf(temp, "(%s%c%s)", op1, prefix[i], op2);
            push(temp);
        } else {
            char temp[MAX_S];
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }
    }
    return stack[top];
} 

int main() {
    char prefix[MAX_S];

    printf("Enter the prefix expression: ");
    fgets(prefix, MAX_S, stdin);
    prefix[strcspn(prefix, "\n")] = '\0';

    printf("INfix : %s\n", preToInfix(prefix));
    return 0;
}