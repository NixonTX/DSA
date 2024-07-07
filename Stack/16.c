// Evaluation of Postfix (with parenthesis)
// top 2 digits; Left to Right (by hand)
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100  

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i, operand1, operand2;
    int isInsideParenthesis = 0;
    int num = 0;

    for(i = 0; i <= strlen(postfix) - 1; i++) {
        char current = postfix[i];
     if(isInsideParenthesis) {
            if(isdigit(current)) {
                num = num * 10 + (current - '0');
            } else if (current == ')') {
                push(num);
                isInsideParenthesis = 0;
            }
        } else {
            if (isdigit(current)) {
            push(current - '0');
        } else if (current == '(') {
            isInsideParenthesis = 1;
            num = 0; // reset num for the new number
        } else if  (isspace(current)) {
            continue;
        } else {
            operand2 = pop();
            operand1 = pop();

            switch(current) {
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
    }
    return pop();    
}

int main() {
    char postfix[MAX_SIZE];
    int result;

    printf("Enter the postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);

    result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}