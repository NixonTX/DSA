// Evaluation of Postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100  

// Stack implementation  
int stack[MAX_SIZE];  
int top = -1;  

void push(int item) {  
    if (top >= MAX_SIZE - 1) {  
        printf("Stack Overflow\n");  
        exit(1);  
    }  
    top++;  
    stack[top] = item;  
}  

int pop() {  
    if (top < 0) {  
        printf("Stack Underflow\n");  
        exit(1);  
    }  
    int item = stack[top];  
    top--;  
    return item;  
}  

int is_operator(char symbol) {  
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');  
}  

int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    while (symbol != '\0') {  
        if (isdigit(symbol)) {  
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(num);  
        }  
        else if (is_operator(symbol)) {  
            operand2 = pop();  
            operand1 = pop();  
            switch(symbol) {  
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(result);  
        }  
        i++;  
        symbol = expression[i];  
    }  
    result = pop();  
    return result;  
}  
  
int main() {  
    char expression[MAX_SIZE];
    printf("Enter the postfix expression: ");
    fgets(expression, MAX_SIZE, stdin);
  
    int result = evaluate(expression);  
    printf("Result= %d\n", result);  
  
    return 0;  
}  
