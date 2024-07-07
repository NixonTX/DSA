// Queue using Stack

#include<stdio.h>
#include<stdlib.h>
#define N 5
int S1[N], S2[N];
int top1 = -1, top2 = -1;
int count = 0;
int i, a, b = 0;

void push1(int data) {
    if (top1 == N-1) {
        printf("Overflow\n");
    } else {
        top1++;
        S1[top1] = data;
    }
}

void push2(int data) {
    if (top2 == N-1) {
        printf("Overflow\n");
    } else {
        top2++;
        S2[top2] = data;
    }
}


int pop1() {
    return S1[top1--];  // Post decrement
}

int pop2() {
    return S2[top2--];  // Post decrement
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is Empty\n");
    } else {
        for(i = 0; i < count; i++) {
            a = pop1();
            push2(a);
        }
        
        b = pop2();
        printf("%d dequeued\n", b);
        count--;

        for(i = 0; i < count; i++) {
            a = pop2();
            push1(a);
        }
    }
}

void display() {
    printf("Elements are: ");
    for (i = 0; i <= top1; i++) {
        printf("%d ", S1[i]);
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    display();

    dequeue();
    display();

    enqueue(7);

    display();

    return 0;
}