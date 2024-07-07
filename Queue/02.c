// Queue implementation using Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void display() {
    struct node* temp;
    if(front == NULL && rear == NULL) {
        printf("Empty\n");
    } else {
        temp = front;

        printf("Elements in the queue are: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void dequeue() {
    struct node* temp = front;
    // temp = front;
    if (front == NULL && rear == NULL) {
        printf("Underflow\n");
    } else {
        printf("%d is dequeued\n", front->data);
        front = front->next;
        free(temp);
    }
}

void peek() {
    if(front == NULL && rear == NULL) {
        printf("Empty\n");
    } else {
        printf("peeking %d\n", front->data);
    }
}

int main() {
    enqueue(5);
    enqueue(0);
    enqueue(-2);

    display();
    dequeue();

    peek();
    display();

    return 0;
}