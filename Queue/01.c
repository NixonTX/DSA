// Implementation of Queue using Array

#include<stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void deque() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else if (front == rear)   // Only one element
    {
        printf("dequed element %d is the only element left in queue.\n",queue[front]);
        front = rear = -1;
    } else {
        printf("%d is dequed\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Elements in the queue are: ");
        for(int i = front; i < rear + 1; i++) {
            printf("%d ", queue[i]);
        }
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("\npeeking element %d.\n", queue[front]);
    }
}

int main() {
    enqueue(2);
    enqueue(5);
    enqueue(-1);

    display();
    peek();

    deque();
    peek();

    display();

    return 0;
}