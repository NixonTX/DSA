// Prefix to Infix

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_S 100

// Stack implementation
char stack[MAX_S][MAX_S];
int top = -1;

void push(char item[]) {
    if (top >= MAX_S - 1) {
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

// Function to check if character is an operator or not
bool isOperator(char x) {
    switch (x) {
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

// Function to convert prefix to infix expression
char* preToInfix(char pre_exp[]) {
    int length = strlen(pre_exp);

    // Reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            char* op1 = pop();
            char* op2 = pop();
            char temp[MAX_S];
            sprintf(temp, "(%s%c%s)", op1, pre_exp[i], op2);
            push(temp);
        } else {
            char temp[MAX_S];
            temp[0] = pre_exp[i];
            temp[1] = '\0';
            push(temp);
        }
    }
    // Stack now contains the Infix expression
    return stack[top];
}

int main() {
    char pre_exp[MAX_S];

    printf("Enter the prefix expression: ");
    fgets(pre_exp, MAX_S, stdin);
    pre_exp[strcspn(pre_exp, "\n")] = '\0'; // Remove newline character from input

    printf("Infix : %s\n", preToInfix(pre_exp));
    return 0;
}
