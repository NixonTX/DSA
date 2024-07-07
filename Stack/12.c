// Evaluation of Prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
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
    int i;
    int operand1, operand2;

    // Start scanning from right to left
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        char current = prefix[i];

        // If current character is an operand, push it onto the stack
        if (isdigit(current)) {
            push(current - '0'); // Convert character digit to integer
        } else if (isspace(current)) {
            // Skip whitespace characters
            continue;
        } else {
            // If current character is an operator, pop two operands from the stack
            operand1 = pop();
            operand2 = pop();

            // Perform the operation based on the operator
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

    // The result will be the only element left on the stack
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
