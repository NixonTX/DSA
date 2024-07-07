// Evaluation of Prefix
// Right to Left; top 2 digits (by handy)
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE -1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePrefix(char prefix[]) {
    int i, operand1, operand2;

    for(i = strlen(prefix) - 1; i >= 0; i--) {
        char current = prefix[i];

        if(isdigit(current)) {
            push(current - '0');
        } else if (isspace(current)) {
            continue;
        } else {
            operand1 = pop();
            operand2 = pop();

            switch (current) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char prefix[MAX_SIZE];
    int result;

    printf("Enter the prefix expression: ");
    fgets(prefix, MAX_SIZE, stdin);

    result = evaluatePrefix(prefix);

    printf("Result: %d\n", result);

    return 0;
}